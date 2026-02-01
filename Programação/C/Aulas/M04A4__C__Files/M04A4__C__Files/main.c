/* ============================================================================

    Linguagem C, o curso definitivo
    Módulo 4 Aula 4
    O Operador Condicional ?
    
    Autor: Dr. Eng. Wagner Rambo
    Data:  Maio de 2021

============================================================================ */


/* ========================================================================= */
/* --- Bibliotecas --- */
#include <stdio.h>
#include <stdlib.h>


/* ========================================================================= */
/* --- Função Principal --- */
main()
{
  
  
  
  
  
  system("PAUSE");	                             /* pausa excução (Pressione qualquer tecla para continuar . . .) */
  return 0;                                      /* retorna 0, se main for executada corretamente */
  
} /* end main */


/* ============================================================================  
                                                              
                                       _                      
                                      / \                     
                                     |oo >                    
                                     _\=/_                    
                    ___         #   /  _  \   #               
                   /<> \         \\//|/.\|\\//                
                 _|_____|_        \/  \_/  \/                 
                | | === | |          |\ /|                    
                |_|  0  |_|          \_ _/                    
                 ||  0  ||           | | |                    
                 ||__*__||           | | |                    
                |* \___/ *|          []|[]                    
                /=\ /=\ /=\          | | |                    
________________[_]_[_]_[_]_________/_]_[_\_______________________________
                                                              
                                                              
============================================================================ */
/* --- Final do Programa --- */


/*


  EXEMPLOS DA AULA
  ============================
  
  int val;
  printf("Digite um valor: ");
  scanf("%d",&val);
  
  val < 100 ? printf("Menor que 100\n") : printf("Maior que 100\n");


  ============================

  float Tc;
  printf("Entre com a temperatura em graus Celsius: ");
  scanf("%f",&Tc);
  
  printf("Status da temperatura: %c\n", Tc>30.0 ? 'H' : 'L');


  ============================
  
  float salario, vendas;
  
  printf("Salario R$: ");
  scanf("%f",&salario);
  printf("Vendas  R$: ");
  scanf("%f",&vendas);
  
  salario = salario +
            (vendas > 10000.0 ? 10 : 0) *
            (salario/100.0);
  
  printf("Seu salario \x82 R$: %.2f\n",salario);


  ============================
  
  unsigned char regist = 0x00;
  
  printf("Carregua um valor no registrador 00h a FFh: ");
  scanf("%X",&regist);
  
  printf("Valor carregado: %Xh\n",regist);
  
  regist = regist ? 0x80 : 0x00;
  
  printf("Valor corrigido: %Xh\n",regist);





*/
