#include <stdio.h>
#include <stdlib.h>

int main() {
 


int idade;
char car;

    printf("Qual a sua idade?\n");
    scanf("%d", &idade);

    printf("Voce possui carro?\n");
    scanf(" %c",&car);

    if ((car == 'n' || car == 'N') && (idade >= 18 || idade <= 50))
        printf("Parabens voce recebera um auxilio de R$500,00\n");

    else  printf("Parabens voce recebera um auxilio de R$200,00\n");

    return 0;
}