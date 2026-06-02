#include <xc.h>
#include <stdint.h>
#include "rf433.h"

//=====================================================
// CONFIG
//=====================================================

#pragma config FOSC = INTRCIO
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config MCLRE = OFF
#pragma config BOREN = OFF
#pragma config CP = OFF
#pragma config CPD = OFF

#define _XTAL_FREQ 4000000

//=====================================================
// PINOS
//=====================================================

#define BOTAO  GP4
#define JOY_X  GP0
#define JOY_Y  GP1

//=====================================================
// FUNÇÕES
//=====================================================

void button(void);
void adc_init(void);
uint8_t adc_read(uint8_t channel);

//=====================================================
// VARIÁVEIS
//=====================================================

uint8_t valor_x = 0;
uint8_t valor_y = 0;

// 0 = MANUAL
// 1 = AUTOMÁTICO
uint8_t flag = 0;

//=====================================================
// MAIN
//=====================================================

void main()
{
    OSCCAL = *(unsigned char*)0x3FF;

    CMCON = 0x07;

    TRISIO = 0b00010011;

    GPIO = 0x00;

    // Pull-up botão
    OPTION_REGbits.nGPPU = 0;
    WPUbits.WPU4 = 1;

    adc_init();

    while(1)
{
    button();

    //=========================================
    // MODO MANUAL
    //=========================================

    if(flag == 0)
    {
        valor_x = adc_read(0);
        valor_y = adc_read(1);

        uint8_t pulso_x = 10 + (valor_x / 25);
        uint8_t pulso_y = 10 + (valor_y / 25);

        //=====================================
        // FILTRO SERVO X
        //=====================================

        static uint8_t ultimo_x = 255;

        if(pulso_x != ultimo_x)
        {
            ultimo_x = pulso_x;

            envia_pacote(0x10 + pulso_x);

            __delay_ms(10);
        }

        //=====================================
        // FILTRO SERVO Y
        //=====================================

        static uint8_t ultimo_y = 255;

        if(pulso_y != ultimo_y)
        {
            ultimo_y = pulso_y;

            envia_pacote(0x20 + pulso_y);

            __delay_ms(10);
        }
    }

    __delay_ms(20);
}
}

//=====================================================
// BOTÃO
//=====================================================

void button()
{
    if(BOTAO == 0)
    {
        __delay_ms(20);

        if(BOTAO == 0)
        {
            // Alterna modo
            flag = !flag;

            // Envia comando várias vezes
            for(uint8_t i = 0; i < 5; i++)
            {
                envia_pacote(0x06);
                __delay_ms(5);
            }

            // Espera soltar
            while(BOTAO == 0);
        }
    }
}

//=====================================================
// ADC
//=====================================================

void adc_init(void)
{
    ANSEL = 0b00010011;

    ADCON0 = 0b00000001;
}

//=====================================================
// LEITURA ADC
//=====================================================

uint8_t adc_read(uint8_t channel)
{
    ADCON0 &= 0b11110011;

    ADCON0 |= (channel << 2);

    __delay_us(20);

    GO_nDONE = 1;

    while(GO_nDONE);

    return ADRESH;
}