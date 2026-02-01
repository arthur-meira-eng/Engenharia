/******************************************************************************
 * Nome: Arthur Henrique Santos Meira
 * Disciplina: Programacao C
 * Projeto:  Nivel da bateria com operador condicional '?'
 * Data: 31/01/2026
 * Descricao: 
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    float bat;
    
    printf("Digite a tensao da bateria:\n");
    scanf("%f",&bat);
    
    (bat<=10)?(printf("Bateria abaixo de 10 volts!")):(printf("Bateria está OK."));

    return 0;
}