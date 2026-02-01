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
    int idade;
    char status;

    printf("Qual a sua idade?\n");
    scanf("%d",&idade);

    printf("Qual seu estatus civil?\n (S) - Solteiro(a)\n (C) - Casado(a)\n (D) - Divorciado(a)\n (V) - Viuvo(a)\n");
    scanf(" %c",&status);

    switch (status)
    {
    case 's':
        printf("O individuo e solteiro e tem %d anos.\n", idade);
        break;
    case 'S':
        printf("O individuo e solteiro e tem %d anos.\n", idade);
        break;
    case 'c':
        printf("O individuo e casado e tem %d anos.\n", idade);
        break;
    case 'C':
        printf("O individuo e casado e tem %d anos.\n", idade);
        break;
    case 'd':
        printf("O individuo e divorciado e tem %d anos.\n", idade);
        break;
     case 'D':
        printf("O individuo e divorciado e tem %d anos.\n", idade);
        break;
    case 'v':
        printf("O individuo e viuvo e tem %d anos.\n", idade);
        break;
    case 'V':
        printf("O individuo e viuvo e tem %d anos.\n", idade);
        break;

    default:
        printf("Opcao invalida!\n");
        break;
    }
    
    
    return 0;
}