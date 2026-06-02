#include <xc.h>
#include <stdint.h>
#include "uart.h"
#include "servo.h"

//=====================================================
// CONFIG
//=====================================================

#pragma config FOSC = INTOSCIO
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config MCLRE = OFF
#pragma config BOREN = OFF
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config CP = OFF

#define _XTAL_FREQ 4000000

//=====================================================
// VARIÁVEIS
//=====================================================

uint8_t pos_servo1 = 15;
uint8_t pos_servo2 = 15;

uint8_t executando = 0;
uint8_t etapa_auto = 0;

uint8_t trava_botao = 0;

//=====================================================
// INTERRUPÇÃO
//=====================================================

void __interrupt() isr(void)
{
    if(RCIF)
    {
        uart_rx_isr();
    }

    if(TMR1IF)
    {
        TMR1IF = 0;
        servo_tick_isr();
    }
}

//=====================================================
// MAIN
//=====================================================

void main(void)
{
    CMCON = 0x07;

    PORTA = 0x00;
    PORTB = 0x00;

    TRISB = 0b00000010;

    uart_init();
    servo_init();

    PEIE = 1;
    GIE = 1;

    servo_set_posicao(15, 15);

    while(1)
    {
        //=================================================
        // RECEPÇÃO
        //=================================================

        if(dado_rx != 0)
        {
            uint8_t comando = dado_rx;
            dado_rx = 0;

            //=============================================
            // SERVO 1
            //=============================================

            if(comando >= (0x10 + 10) &&
               comando <= (0x10 + 20))
            {
                pos_servo1 = comando - 0x10;
            }

            //=============================================
            // SERVO 2
            //=============================================

            else if(comando >= (0x20 + 10) &&
                    comando <= (0x20 + 20))
            {
                pos_servo2 = comando - 0x20;
            }

            //=============================================
            // BOTÃO
            //=============================================

            else if(comando == 0x06)
            {
                // Evita múltiplos toggles
                if(trava_botao == 0)
                {
                    executando = !executando;

                    etapa_auto = 0;

                    trava_botao = 1;
                }
            }
        }

        // Libera trava após tempo
        if(trava_botao)
        {
            __delay_ms(300);
            trava_botao = 0;
        }

        //=================================================
        // AUTOMÁTICO
        //=================================================

        if(executando)
        {
            switch(etapa_auto)
            {
                case 0:
                    servo_set_posicao(10, 20);
                    __delay_ms(700);
                    etapa_auto = 1;
                    break;

                case 1:
                    servo_set_posicao(15, 15);
                    __delay_ms(700);
                    etapa_auto = 2;
                    break;

                case 2:
                    servo_set_posicao(20, 10);
                    __delay_ms(700);
                    etapa_auto = 0;
                    break;
            }
        }

        //=================================================
        // MANUAL
        //=================================================

        else
        {
            servo_set_posicao(pos_servo1, pos_servo2);

            // Delay pequeno reduz jitter
            __delay_ms(20);
        }
    }
}