/******************************************************************************
 * NOME: Arthur Henrique Santos Meira
 * DATA: 31/01/2026
 * DESCRIÇÃO: Sequência de Fibonacci até 50
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    int atual = 1, anterior = 0, proximo;

    printf("--- Sequência de Fibonacci ---\n");
    
    // Imprime o primeiro termo
    printf("%d\n", anterior);

    while (atual <= 1000) {
        printf("%d\n", atual);
        
        proximo = anterior + atual; // Soma os dois anteriores
        anterior = atual;           // O atual vira o anterior para a próxima rodada
        atual = proximo;            // O próximo vira o atual
    }

    return 0;
}