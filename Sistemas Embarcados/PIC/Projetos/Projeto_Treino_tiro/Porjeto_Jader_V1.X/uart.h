#ifndef UART_H
#define UART_H

#include <xc.h>
#include <stdint.h>

// Variável global externa acessível pelo main e pela interrupção
extern volatile uint8_t dado_rx;

// Protótipos das funções
void uart_init(void);
void uart_rx_isr(void);

#endif /* UART_H */