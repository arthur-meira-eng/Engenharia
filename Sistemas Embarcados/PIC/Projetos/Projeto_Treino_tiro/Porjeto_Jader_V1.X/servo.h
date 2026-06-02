#ifndef SERVO_H
#define SERVO_H

#include <xc.h>
#include <stdint.h>

// Pinos dos Servos
#define SERVO1 RB3
#define SERVO2 RB4

// Protótipos das funções
void servo_init(void);
void servo_tick_isr(void);
void servo_set_posicao(uint8_t pos1, uint8_t pos2);

#endif /* SERVO_H */