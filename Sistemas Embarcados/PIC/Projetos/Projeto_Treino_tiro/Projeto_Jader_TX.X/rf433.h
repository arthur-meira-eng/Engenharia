#ifndef RF433_H
#define RF433_H

#include <xc.h>
#include <stdint.h>

// Definição da frequência de clock para os delays
#define _XTAL_FREQ 4000000

// Definição do pino de Transmissão (Pode ser alterado aqui futuramente)
#define TX GP2

// Protótipo da única função pública que o main() precisa conhecer
void envia_pacote(uint8_t comando);

#endif /* RF433_H */