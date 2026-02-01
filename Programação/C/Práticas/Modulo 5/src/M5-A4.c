/******************************************************************************
 * NOME: Arthur Henrique Santos Meira
 * DATA: 31
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    // Configura acentuação para Português
    setlocale(LC_ALL, "Portuguese_Brazil");

    int num;
    puts("Digite o número de degraus:");
    scanf("%d", &num);

    for (int i = 0; i <= num; i++)
    {
        for (int j = 0; j < num-(num-i); j++)
        {
            putchar('#');
        }
        putchar('\n');
    }
    

    return 0;
}
