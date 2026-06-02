#include <xc.h>
#include <stdint.h>

//=====================================================
// CONFIG PIC12F675
//=====================================================
#pragma config FOSC = INTRCIO
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config MCLRE = OFF
#pragma config BOREN = ON
#pragma config CP = OFF
#pragma config CPD = OFF

#define _XTAL_FREQ 4000000

//=====================================================
// PINOS
//=====================================================
#define OUT_TX         GP5

// JOYSTICK
#define JOY_X_CHANNEL  2     // AN2 = GP2
#define JOY_Y_CHANNEL  3     // AN3 = GP4
#define JOY_SW         GP0   // Botão do joystick

//=====================================================
// CONSTANTES E VARIÁVEIS
//=====================================================
#define TRIS_GPIO      0b010101 
#define SERIAL_NUMBER  0x57

// O SEGREDO DA VELOCIDADE ESTÁ AQUI:
// Reduzido de 500 para 250. Isso dobra a taxa de atualização (30 Hz)!
#define TE             500

uint8_t buffer[5];

//=====================================================
// FUNÇÕES DE TRANSMISSÃO
//=====================================================
void shift_right_buffer(void) {
    uint8_t carry = 0;
    for(int8_t i = 4; i >= 0; i--) {
        uint8_t next = buffer[i] & 0x01;
        buffer[i] >>= 1;
        if(carry) buffer[i] |= 0x80;
        carry = next;
    }
}

void env_bit1(void) {
    OUT_TX = 0;
    __delay_us(2 * TE);
    OUT_TX = 1;
    __delay_us(TE);
    OUT_TX = 0;
}

void env_bit0(void) {
    OUT_TX = 0;
    __delay_us(TE);
    OUT_TX = 1;
    __delay_us(2 * TE);
    OUT_TX = 0;
}

void start_bit(void) {
    OUT_TX = 1;
    __delay_us(TE);
    OUT_TX = 0;
}

//=====================================================
// INICIALIZAÇÃO E ADC
//=====================================================
void init_system(void) {
    CMCON = 0x07;             // Desliga comparadores
    ANSEL = 0b00001100;       // AN2 (GP2) e AN3 (GP4) como analógicos
    ADCON0 = 0x01;            // Liga o módulo ADC
    TRISIO = TRIS_GPIO;       // Configura entradas e saídas
    WPU = 0b00000001;         // Pull-up no botão GP0
    OPTION_REGbits.nGPPU = 0; // Habilita pull-ups globais
    GPIO = 0;                 // Zera as saídas
}

uint8_t read_adc_manual(uint8_t channel) {
    ADCON0 = (channel << 2) | 0x01;
    __delay_us(50);
    GO_nDONE = 1;
    while(GO_nDONE);
    return ADRESH;
}

//=====================================================
// MAIN
//=====================================================
void main(void) {
    init_system();

    while(1) {
        uint8_t a;
        buffer[0] = 0; // Limpa o checksum

        // 1. SERIAL
        buffer[4] = SERIAL_NUMBER;
        buffer[0] += buffer[4];

        // 2. JOYSTICK X (AN2)
        buffer[3] = read_adc_manual(JOY_X_CHANNEL);
        buffer[0] += buffer[3];

        // 3. JOYSTICK Y (AN3)
        buffer[2] = read_adc_manual(JOY_Y_CHANNEL);
        buffer[0] += buffer[2];

        // 4. BOTÃO DO JOYSTICK (0 = Pressionado, 1 = Solto)
        buffer[1] = (JOY_SW == 0) ? 1 : 0;
        buffer[0] += buffer[1];

        // ENVIO DOS DADOS
        start_bit();
        for(a = 0; a < 40; a++) {
            if(buffer[0] & 0x01) {
                env_bit1();
            } else {
                env_bit0();
            }
            shift_right_buffer();
        }

        // PAUSA ENTRE PACOTES (Sincronismo do RX)
        __delay_us(11 * TE);
    }
}