/* ============================================================================

    Linguagem C, o curso definitivo
    Módulo 5 Aula 0
    Incremento e Decremento
    
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
  unsigned a, b, c, d, soma;
  
  printf("a= ");
  scanf("%d",&a);
  printf("b= ");
  scanf("%d",&b);
  printf("c= ");
  scanf("%d",&c);
  printf("d= ");
  scanf("%d",&d);
  
  printf("Valores originais: \n");
  printf("a= %d\n", a);
  printf("b= %d\n", b);
  printf("c= %d\n", c);
  printf("d= %d\n", d);
  
  soma = a + b + c + d;
  
  b--;
  d = c + b;
  c = a;
  a++;
  
  soma = soma + a + b + c + d;
  
  
  
  printf("Valores atuais: \n");
  printf("a= %d\n", a);
  printf("b= %d\n", b);
  printf("c= %d\n", c);
  printf("d= %d\n", d);
  printf("s= %d\n",soma);
  
  
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
   
  ===========================
  int x, y;
  
  x = 5;
  y = 8;
  
  printf("x = %d\n",x);
  printf("y = %d\n",y);
  
  x++;
  y--;
  
  printf("\ninc e dec...\n");
  printf("x = %d\n",x);
  printf("y = %d\n\n",y);  
 


*/


