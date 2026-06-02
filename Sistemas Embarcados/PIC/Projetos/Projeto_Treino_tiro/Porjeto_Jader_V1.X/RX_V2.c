// CONFIG
#pragma config FOSC = INTRCIO   // Oscilador interno
#pragma config WDTE = OFF       // Watchdog Timer desativado
#pragma config PWRTE = OFF      // Power-Up Timer desativado
#pragma config MCLRE = OFF      // MCLR desativado (GP3 atua como entrada digital)
#pragma config BOREN = OFF      // Brown-out Detect desativado
#pragma config CP = OFF         // Proteção de código desativada
#pragma config CPD = OFF        // Proteção de dados desativada

#include <xc.h>
#include <stdint.h>

// Frequência definida para 4 MHz
#define _XTAL_FREQ 4000000

// Mapeamento de Hardware
#define SERVO1  GPIObits.GP0

// Protótipos das funções
void servo_0_graus(void);
void servo_90_graus(void);
void servo_180_graus(void);

void main(void)
{
    CMCON  = 0x07;  // Desliga comparadores
    TRISIO = 0x08;  // GP3 é entrada (obrigatório no PIC), restante é saída (0b00001000)
    
    SERVO1 = 0;     // Garante que o pino inicia em LOW

    while(1)
    {
        servo_0_graus();
    __delay_ms(1000); // Pausa de 1 segundo em 0 graus
    
    servo_90_graus();
    __delay_ms(1000); // Pausa de 1 segundo em 90 graus
    
    servo_180_graus();
    __delay_ms(1000); // Pausa de 1 segundo em 180 graus
    }
}

void servo_0_graus(void)
{
    // 25 repetições de 20ms = 500ms de duração
   
        SERVO1 = 1;
        __delay_us(1000);  // Pulso exato de 1ms
        SERVO1 = 0;
        __delay_us(19000); // Complemento exato de 19ms
    
}

void servo_90_graus(void)
{
 
        SERVO1 = 1;
        __delay_us(1500);  // Pulso exato de 1.5ms
        SERVO1 = 0;
        __delay_us(18500); // Complemento exato de 18.5ms
    
}

void servo_180_graus(void)
{
    
        SERVO1 = 1;
        __delay_us(2000);  // Pulso exato de 2ms
        SERVO1 = 0;
        __delay_us(18000); // Complemento exato de 18ms
    
}