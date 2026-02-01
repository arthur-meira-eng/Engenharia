/******************************************************************************
 * NOME: Arthur Henrique Santos Meira
 * DATA: 31/01/2026
 * DESCRIÇÃO: Desenho de moldura dinâmica no console
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int largura = 30;
    char texto[] = " NUMERO 3 ";
    int padding = (largura - strlen(texto)) / 2;

    // 1. Desenha a linha superior de "+"
    for (int i = 0; i < largura; i++) printf("+");
    printf("\n");

    // 2. Desenha as laterais superiores "|"
    printf("|");
    for (int i = 0; i < largura - 2; i++) printf(" ");
    printf("|\n");

    // 3. Desenha a moldura interna superior (tracejado)
    printf("| ");
    for (int i = 0; i < largura - 4; i++) printf("-");
    printf(" |\n");

    // 4. Linha com o TEXTO centralizado
    printf("| |");
    for (int i = 0; i < padding - 3; i++) printf(" "); // Espaço antes do texto
    printf("%s", texto);
    for (int i = 0; i < padding - 3; i++) printf(" "); // Espaço depois do texto
    printf("| |\n");

    // 5. Desenha a moldura interna inferior (tracejado)
    printf("| ");
    for (int i = 0; i < largura - 4; i++) printf("-");
    printf(" |\n");

    // 6. Desenha as laterais inferiores "|"
    printf("|");
    for (int i = 0; i < largura - 2; i++) printf(" ");
    printf("|\n");

    // 7. Desenha a linha inferior de "+"
    for (int i = 0; i < largura; i++) printf("+");
    printf("\n");

    return 0;
}