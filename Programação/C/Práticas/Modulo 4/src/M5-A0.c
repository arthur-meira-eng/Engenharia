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
    int num,
        v_mais,
        v_menos,
        v_sum;
    long v_quad;

    printf("Digite um calor menor que 85!\n");
    scanf("%d", &num);
    
   if(num>85)
   {
    printf("Numero digitado invalido!\n");
    return 0;
   }    

    v_mais = num;
    v_menos = num;

    v_mais++;
    v_menos--;

    v_sum = num + v_mais + v_menos;
    v_quad = (long)v_sum*v_sum;

    printf("O resultado: %d, %d, %d, %ld\n", v_mais,v_menos, v_sum, v_quad);



    return 0;
}