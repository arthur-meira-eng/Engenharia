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

    char op;

    do
    {   

        printf("==============================Main Menu===============================\n");
        printf("(N) - Para Novo Cliente.\n");
        printf("(C) - para Consultar Clientes.\n");
        printf("(D) - para Deletar Clientes.\n");
        printf("(L) - para Listar Clientes.\n");
        printf("(S) - Para Sair.\n");
        printf("======================================================================\n");

        scanf(" %c", &op);



        switch (op)
        {
            case 'n':
            case 'N':
                printf("===================Cadastro de novo cliente===================\n");
            break;
            
            case 'c':
            case 'C':
                printf("===================Consulta de clientes===================\n");
            break;

            case 'd':
            case 'D':
                printf("===================Deletar cliente===================\n");
            break;

            case 'l':
            case 'L':
                printf("===================Listar cliente===================\n");
            break;

            case 's':
            case 'S':
                printf("===================Obrigado===================\n");
                return 0;
            break;
            
        default:
                printf("***********************Opção inválida!***********************\n");
            break;
        }
        
        
    } while (op != 's'|| op!='S');
        puts("Imprime no console"); //imprime a string no console e pula a linha automaticamente.


    return 0;
}
