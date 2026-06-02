#include "servo.h"

// Variáveis de controle do PWM escondidas neste arquivo (static para proteção)
static volatile uint16_t contador = 0;
static volatile uint8_t pulso1 = 15;
static volatile uint8_t pulso2 = 15;

void servo_init(void)
{
    T1CON = 0b00000001;
    TMR1H = 0xFF;
    TMR1L = 0x9C;
    TMR1IF = 0;
    TMR1IE = 1;
}

// Função para atualizar os valores dos pulsos de forma segura
void servo_set_posicao(uint8_t pos1, uint8_t pos2)
{
    pulso1 = pos1;
    pulso2 = pos2;
}

// Função executada a cada 100us pela interrupção do Timer1
void servo_tick_isr(void)
{
    // Recarrega o Timer1 (100us)
    TMR1H = 0xFF;
    TMR1L = 0x9C;

    contador++;

    // INÍCIO PWM
    if(contador >= 200)
    {
        contador = 0;
        SERVO1 = 1;
        SERVO2 = 1;
    }

    // SERVO1
    if(contador >= pulso1)
    {
        SERVO1 = 0;
    }

    // SERVO2
    if(contador >= pulso2)
    {
        SERVO2 = 0;
    }
}