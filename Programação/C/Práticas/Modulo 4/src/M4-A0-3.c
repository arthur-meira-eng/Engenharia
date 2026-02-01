#include <stdio.h>
#include <stdlib.h>


int main() 
{
	float salario;
	float vendas;
	
	printf("Qual os eu salario base (R$)?\n");
	scanf("%f", &salario);
	
	printf("Quais foram as suas vendas (R$)?\n");
	scanf( "%f", &vendas);
	
	if(vendas >= 30000)
		salario = salario+(salario*0,25);
	    else 
		    if(vendas >= 20000)
			    salario = salario+(salario*0,15);
                else if(vendas >= 10000)
                    salario = salario+(salario*0,10);

	else salario = salario;
	
	printf("Seu salario serÃ¡ de %.2f\n", salario);


	return 0;
}