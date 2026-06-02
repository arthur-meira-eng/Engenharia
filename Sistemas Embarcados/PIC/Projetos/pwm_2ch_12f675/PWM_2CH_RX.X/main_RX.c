#include <xc.h>
#include <stdint.h>

//=====================================================
// CONFIG PIC12F629
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

#define SERVO1     GP2
#define SERVO2     GP4

#define RFIN       GP3

//=====================================================
// CONSTANTES
//=====================================================

#define TRIS_GPIO      0b001000

#define SERIAL_NUMBER  0x57

#define TMAX           30

//=====================================================
// FLAGS
//=====================================================

struct
{
    unsigned flag_vez : 1;
    unsigned flag_h   : 1;
    unsigned flag_rok : 1;
    unsigned flag_tpr : 1;

} flags;

struct
{
    unsigned flag_it1 : 1;

} flags1;

//=====================================================
// VARIÁVEIS
//=====================================================

uint8_t hc;
uint8_t lc;
uint8_t qb;

volatile uint8_t vp1;
volatile uint8_t vp2;

uint8_t botoes;

uint8_t buffer[5];

//=====================================================
// SHIFT RIGHT
//=====================================================

void shift_right_buffer(uint8_t bit_in)
{
    uint8_t carry = bit_in;

    for(int8_t i = 4; i >= 0; i--)
    {
        uint8_t next = buffer[i] & 1;

        buffer[i] >>= 1;

        if(carry)
            buffer[i] |= 0x80;

        carry = next;
    }
}

//=====================================================
// RESET RX
//=====================================================

void reset_rx(void)
{
    lc = 0;

    hc = 0;

    flags.flag_h = 0;
}

//=====================================================
// INIT
//=====================================================

void init_system(void)
{
    CMCON = 0x07;

    TRISIO = TRIS_GPIO;

    OPTION_REG = 0x01;

    T1CON = 0x01;

    TMR1H = 0xD8;
    TMR1L = 0xF0;

    GPIO = 0;

    qb = 40;

    hc = 0;
    lc = 0;

    flags.flag_vez = 0;
    flags.flag_h   = 0;
    flags.flag_rok = 0;
    flags.flag_tpr = 0;

    flags1.flag_it1 = 0;

    // centro do servo
    vp1 = 0x3F;
    vp2 = 0x3F;

    TMR0IF = 0;
    TMR1IF = 0;

    TMR1IE = 1;

    PEIE = 1;
    GIE = 1;
}

//=====================================================
// TIMER ISR
//=====================================================

void __interrupt() isr(void)
{
    //=================================================
    // TIMER1
    //=================================================

    if(TMR1IF)
    {
        TMR1H = 0xD8;
        TMR1L = 0xF0;

        flags1.flag_it1 = 1;

        flags.flag_tpr = 0;

        // alterna servo
        if(!flags.flag_vez)
        {
            SERVO1 = 1;

            flags.flag_vez = 1;
        }
        else
        {
            SERVO2 = 1;

            flags.flag_vez = 0;
        }

        TMR0 = 64;

        TMR0IE = 1;

        TMR1IF = 0;
    }

    //=================================================
    // TIMER0
    //=================================================

    if(TMR0IF)
    {
        if(!flags1.flag_it1)
        {
            if(flags.flag_tpr)
            {
                SERVO1 = 0;
                SERVO2 = 0;

                TMR0IE = 0;
            }
            else
            {
                flags.flag_tpr = 1;

                if(flags.flag_vez)
                    TMR0 = vp1;
                else
                    TMR0 = vp2;
            }
        }

        flags1.flag_it1 = 0;

        TMR0IF = 0;
    }
}

//=====================================================
// MAIN
//=====================================================

void main(void)
{
    init_system();

    while(1)
    {
        __delay_us(50);

        //=================================================
        // RECEPÇÃO RF
        //=================================================

        if(RFIN && !flags.flag_rok)
        {
            flags.flag_h = 1;

            if(++hc == 0)
                hc--;
        }
        else
        {
            if(!flags.flag_h)
            {
                if(++lc == 0)
                    lc--;
            }
            else
            {
                if(lc > TMAX)
                {
                    qb = 40;
                }
                else
                {
                    shift_right_buffer(lc > hc);

                    if(--qb == 0)
                    {
                        qb = 40;

                        uint8_t checksum =
                            buffer[1] +
                            buffer[2] +
                            buffer[3] +
                            buffer[4];

                        if((checksum == buffer[0]) &&
                           (buffer[4] == SERIAL_NUMBER))
                        {
                            //=================================
                            // SERVO 1
                            //=================================

                            vp1 = ~buffer[3];

                            //=================================
                            // SERVO 2
                            //=================================
                            // mesmo joystick

                            vp2 = ~buffer[3];

                            botoes = buffer[1];

                            flags.flag_rok = 1;
                        }
                    }
                }

                reset_rx();
            }
        }

        //=================================================
        // PACOTE OK
        //=================================================

        if(flags.flag_rok)
        {
            flags.flag_rok = 0;
        }
    }
}