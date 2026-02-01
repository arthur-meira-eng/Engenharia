/******************************************************************************
 * NOME: Arthur Henrique Santos Meira
 * DATA: 31
 ******************************************************************************/
#include <stdio.h>

int main() {
    
    int freql,freqh,i=0;

    printf("Digite o valor da frequencia de corte inferior:\n");
    scanf("%d", &freql);
    
    printf("Digite o valor da frequencia de corte superior:\n");
    scanf(" %d", &freqh);

    putchar('\n'); //imprime apenas um caracter na tela

    while (i <=  freqh-freql)
    {
        printf("%3dHz\n", freql+i);
        i++;
    }
    
    return 0;
}