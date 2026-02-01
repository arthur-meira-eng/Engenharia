#include <stdio.h>
#include <stdlib.h>


int main() 
{
	int op1, op2;
	
	printf("Digite o primeiro operando:\n");
	scanf("%d", &op1); 
	printf("Digite o segundo operando:\n");
	scanf(" %d",&op2);
	
	printf("%d < %d = ",op1,op2);
	(op1<op2)?(printf("True\n")):(printf("False\n"));
	
	printf("%d > %d = ",op1,op2);
	(op1>op2)?(printf("True\n")):(printf("False\n"));
	
	printf("%d == %d = ",op1,op2);
	(op1==op2)?(printf("True\n")):(printf("False\n"));
	
	printf("%d <= %d = ",op1,op2);
	(op1<=op2)?(printf("True\n")):(printf("False\n"));
	
	printf("%d >= %d = ",op1,op2);
	(op1>=op2)?(printf("True\n")):(printf("False\n"));
	
	printf("%d ! %d = ",op1,op2);
	(op1!=op2)?(printf("True\n")):(printf("False\n"));
	
    return 0;
}