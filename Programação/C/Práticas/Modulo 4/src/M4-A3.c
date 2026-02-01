/******************************************************************************
 * Nome: Arthur Henrique Santos Meira
 * Disciplina: Programacao C
 * Projeto:  
 * Data: 31/01/2026
 * Descricao: 
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    float ddp;
    int res, indice;

    printf("Digite o valor da tensao:\n");
    scanf("%f",&ddp);

    printf("Digite o valor da resistencia:\n");
    scanf(" %d",&res);
    printf("=====================Menu de opcoes==========================\n \n");
    printf("[1] - Corrente que circula pelo resistor.\n");
    printf("[2] - Potencia dissipada no resistor.\n");
    printf("[3] - Valor da tensao para uma corrente de 100mA.\n\n");
    printf("==============================================================\n");
    scanf(" %d",&indice);

        if(indice == 1)
            printf("A corrente I = %.2f",ddp/res);

            else if (indice ==2)
                printf("A potencia dissipada P = %.2f", 100E-3*ddp);
        else
            printf("A tensao para 100mA V = %.2f", 100E-3*res);

    return 0;
}