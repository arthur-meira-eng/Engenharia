/* ============================================================================

    Linguagem C, o curso definitivo
    Módulo 4 Aula 1
    Operadores Lógicos
    
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
  
  printf("%d\n", 15>11 && 8<4 || 7>=11);
     
  
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
   
  =========================
  
  char opt;
  
  printf("Digite s para sim e n para nao: ");
  scanf("%c",&opt);
  
  if(opt == 's' || opt == 'S')
    printf("Voce escolheu sim.\n");
    
  if(opt == 'n' || opt == 'N')
    printf("Voce escolheu nao.\n");  
   

  =========================
  
  int val;
  
  printf("Digite um valor inteiro: ");
  scanf("%d",&val);
  
  if(val>=10 && val<=20)
    printf("Faixa de valores entre 10 e 20.\n");
  
  else
    printf("Faixa de valores menor que 10 ou maior que 20.\n");


  =========================

  char teste;
  
  printf("Digite um valor: ");
  scanf("%d",&teste);
  
  if(!teste)
    printf("O valor foi ZERO.\n");
  else
    printf("Valor diferente de ZERO.\n");


  =========================
  
  int opA, opB, xor;
  
  printf("Entre com opA: ");
  scanf("%d",&opA);
  printf("Entre com opB: ");
  scanf("%d",&opB);
  xor = (opA || opB) && !(opA && opB);
  
  printf("%d XOR %d = %d\n",opA,opB,xor);







*/


