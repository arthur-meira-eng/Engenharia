
#include <xc.h>
#include <stdint.h>

//=====================================================
// CONFIG
//=====================================================

#pragma config FOSC = INTOSCIO
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config MCLRE = ON
#pragma config BOREN = OFF
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config CP = OFF

#define _XTAL_FREQ 4000000

//=====================================================
// PINOS
//=====================================================

#define input_UP    PORTAbits.RA0
#define input_DW    PORTAbits.RA1
#define input_TELA  PORTAbits.RA2

#define motor_UP    PORTAbits.RA3
#define motor_DW    PORTBbits.RB1
#define motor_TELA  PORTBbits.RB0

#define fim_SUP     PORTBbits.RB2
#define fim_INF     PORTBbits.RB3

#define DEBOUNCE_MS 20

//=====================================================
// ESTADOS
//=====================================================

typedef enum
{
    MOT_PARADO = 0,
    MOT_SUBINDO,
    MOT_DESCENDO

} motor_estado_t;

//=====================================================
// VARIAVEIS
//=====================================================

volatile uint32_t contador_motor = 0;
volatile uint32_t contador_tela = 0;

uint32_t tempo_motor = 30000UL;
uint32_t tempo_tela = 30000UL;

volatile motor_estado_t estado_motor = MOT_PARADO;
volatile uint8_t tela_ativa = 0;

// Entradas com debounce
uint8_t UP_ok = 0;
uint8_t DW_ok = 0;
uint8_t TELA_ok = 0;
uint8_t fim_SUP_ok = 0;
uint8_t fim_INF_ok = 0;
uint8_t tempo_bits_ok = 0;

//=====================================================
// PROTOTIPOS
//=====================================================

void setup(void);
void le_entradas_debounce(void);
void define_timer(void);
uint32_t tempo_por_bits(uint8_t valor);

void atualizar_motor(void);
void atualizar_tela(void);

void iniciar_subida(void);
void iniciar_descida(void);
void parar_motor(void);
void parar_tela(void);

//=====================================================
// INTERRUPCAO
//=====================================================

void __interrupt() isr(void)
{
    if(T0IF)
    {
        T0IF = 0;
        TMR0 = 6;

        if(estado_motor != MOT_PARADO)
        {
            contador_motor++;

            if(contador_motor >= tempo_motor)
            {
                parar_motor();
            }
        }

        if(tela_ativa)
        {
            contador_tela++;

            if(contador_tela >= tempo_tela)
            {
                parar_tela();
            }
        }
    }
}

//=====================================================
// MAIN
//=====================================================

void main(void)
{
    setup();

    while(1)
    {
        le_entradas_debounce();

        define_timer();

        atualizar_motor();

        atualizar_tela();
    }
}

//=====================================================
// SETUP
//=====================================================

void setup(void)
{
    CMCON = 0x07;

    TRISA = 0b00000111;

    // RB0 = saida tela
    // RB1 = livre
    // RB2 = fim superior
    // RB3 = fim inferior
    // RB4-RB7 = selecao de tempo
    TRISB = 0b11111100;

    PORTA = 0;
    PORTB = 0;

    // Timer0 aproximadamente 1 ms com clock de 4 MHz
    OPTION_REG = 0b00000001;

    TMR0 = 6;

    T0IE = 1;
    GIE = 1;
}

//=====================================================
// DEBOUNCE
//=====================================================

void le_entradas_debounce(void)
{
    uint8_t up1, dw1, tela1, sup1, inf1, tempo1;
    uint8_t up2, dw2, tela2, sup2, inf2, tempo2;

    up1 = input_UP;
    dw1 = input_DW;
    tela1 = input_TELA;
    sup1 = fim_SUP;
    inf1 = fim_INF;
    tempo1 = (PORTB >> 4) & 0x0F;

    __delay_ms(DEBOUNCE_MS);

    up2 = input_UP;
    dw2 = input_DW;
    tela2 = input_TELA;
    sup2 = fim_SUP;
    inf2 = fim_INF;
    tempo2 = (PORTB >> 4) & 0x0F;

    if(up1 == up2)       UP_ok = up2;
    if(dw1 == dw2)       DW_ok = dw2;
    if(tela1 == tela2)   TELA_ok = tela2;
    if(sup1 == sup2)     fim_SUP_ok = sup2;
    if(inf1 == inf2)     fim_INF_ok = inf2;
    if(tempo1 == tempo2) tempo_bits_ok = tempo2;
}

//=====================================================
// DEFINE TEMPOS
//=====================================================

void define_timer(void)
{
    uint8_t bits_motor;
    uint8_t bits_tela;

    bits_motor = tempo_bits_ok & 0x03;          // RB4 e RB5
    bits_tela  = (tempo_bits_ok >> 2) & 0x03;   // RB6 e RB7

    tempo_motor = tempo_por_bits(bits_motor);
    tempo_tela = tempo_por_bits(bits_tela);
}

uint32_t tempo_por_bits(uint8_t valor)
{
    switch(valor)
    {
        case 0b00: return 30000UL;
        case 0b01: return 60000UL;
        case 0b10: return 90000UL;
        case 0b11: return 120000UL;
        default:   return 30000UL;
    }
}

//=====================================================
// CONTROLE DO MOTOR SUBIDA / DESCIDA
//=====================================================

void atualizar_motor(void)
{
    if(UP_ok && DW_ok)
    {
        parar_motor();
        return;
    }

    if(UP_ok && !DW_ok)
    {
        if(fim_SUP_ok)
        {
            parar_motor();
        }
        else
        {
            iniciar_subida();
        }

        return;
    }

    if(DW_ok && !UP_ok)
    {
        if(fim_INF_ok)
        {
            parar_motor();
        }
        else
        {
            iniciar_descida();
        }

        return;
    }

    if(estado_motor == MOT_SUBINDO)
    {
        if(fim_SUP_ok)
        {
            parar_motor();
        }
        else
        {
            motor_UP = 1;
            motor_DW = 0;
        }
    }
    else if(estado_motor == MOT_DESCENDO)
    {
        if(fim_INF_ok)
        {
            parar_motor();
        }
        else
        {
            motor_UP = 0;
            motor_DW = 1;
        }
    }
    else
    {
        parar_motor();
    }
}

void iniciar_subida(void)
{
    if(estado_motor != MOT_SUBINDO)
    {
        contador_motor = 0;
        estado_motor = MOT_SUBINDO;
    }

    motor_UP = 1;
    motor_DW = 0;
}

void iniciar_descida(void)
{
    if(estado_motor != MOT_DESCENDO)
    {
        contador_motor = 0;
        estado_motor = MOT_DESCENDO;
    }

    motor_UP = 0;
    motor_DW = 1;
}

void parar_motor(void)
{
    motor_UP = 0;
    motor_DW = 0;
    contador_motor = 0;
    estado_motor = MOT_PARADO;
}

//=====================================================
// CONTROLE DA TELA
//=====================================================

void atualizar_tela(void)
{
    if(TELA_ok && !tela_ativa)
    {
        contador_tela = 0;
        tela_ativa = 1;
        motor_TELA = 1;
    }

    if(tela_ativa)
    {
        motor_TELA = 1;
    }
    else
    {
        motor_TELA = 0;
    }
}

void parar_tela(void)
{
    motor_TELA = 0;
    contador_tela = 0;
    tela_ativa = 0;
}
