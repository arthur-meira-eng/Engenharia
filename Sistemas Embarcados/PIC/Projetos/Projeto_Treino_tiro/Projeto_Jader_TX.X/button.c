 
#include "rf433.h"

void button(){
// Verifica se o botão foi pressionado (LOW)
        if(BOTAO == 0) {

            __delay_ms(20); // Debounce de software

            if(BOTAO == 0) {

                // Envia o pacote várias vezes para garantir a entrega
                for(uint8_t i = 0; i < 5; i++) {
                    
                    // Chama a função da nossa biblioteca modularizada
                    envia_pacote(0x06);
                    
                    __delay_ms(3);
                }

                // Espera soltar o botão para não enviar infinitamente
                while(BOTAO == 0);
            } 
        }
}