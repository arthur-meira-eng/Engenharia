#include "rf433.h"

// ========================================================
// FUNÇÕES PRIVADAS (Só existem dentro deste arquivo)
// ========================================================

// Quanto menor, mais rápido transmite (200us funciona bem)
static void tempo(void) {
    __delay_us(200);
}

static void envia_1(void) {
    TX = 1;
    tempo();
    TX = 0;
    tempo();
}

static void envia_0(void) {
    TX = 0;
    tempo();
    TX = 1;
    tempo();
}

static void start_rf(void) {
    TX = 1;
    __delay_us(800);
    TX = 0;
    __delay_us(200);
}

static void preambulo(void) {
    for(uint8_t i = 0; i < 20; i++) {
        TX = 1;
        tempo();
        TX = 0;
        tempo();
    }
}

static void envia_byte(uint8_t dado) {
    for(uint8_t i = 0; i < 8; i++) {
        if(dado & 0x01)
            envia_1();
        else
            envia_0();
        
        dado >>= 1;
    }
}

static uint8_t checksum(uint8_t d) {
    return d ^ 0xAA;
}

// ========================================================
// FUNÇÃO PÚBLICA (Pode ser chamada pelo main.c)
// ========================================================
void envia_pacote(uint8_t comando) {
    preambulo();
    start_rf();
    
    envia_byte(0x55);               // endereço do sistema
    envia_byte(comando);            // comando enviado
    envia_byte(checksum(comando));  // verificação de erro
    
    TX = 0; // Garante que o TX termina em LOW
}