#include "uart.h"

// Declaração real da variável de recepção
volatile uint8_t dado_rx = 0;

void uart_init(void)
{
    SPBRG = 51;
    BRGH = 0;
    SYNC = 0;
    SPEN = 1;
    CREN = 1;
    RX9 = 0;
    TXEN = 0;
    RCIE = 1;
}

// Função chamada dentro da interrupção quando chega um dado
void uart_rx_isr(void)
{
    dado_rx = RCREG;
}