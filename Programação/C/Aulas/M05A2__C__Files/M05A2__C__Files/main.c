/* ============================================================================

    Linguagem C, o curso definitivo
    Módulo N Aula N
    Título da Aula
    
    Autor: 
    Data: 

============================================================================ */


/* ========================================================================= */
/* --- Bibliotecas --- */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>                              /* para trabalhar com acentuação */

/* ========================================================================= */
/* --- Função Principal --- */
main()
{
  
  setlocale(LC_ALL,"Portuguese_Brazil");         /* configuração para aceitar caracteres do português brasileiro */  
    
  int numero;
    
  do
  {
    printf("Digite o número: ");
    scanf("%d",&numero);
                                                                                     
  } while(numero>=10);
   
  
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
  ==========================
  
  char opt;

  do
  {
    printf("(a) Menus.\n");
    printf("(q) Quit.\n");
    printf("Opção: ");
    scanf(" %c",&opt);

    switch(opt)
    {
      case 'a':  printf("Menus\n"); break;
      case 'q':  printf("Saiu\n");  break;
      default:   printf("Inválido\n");
   
    } 


  }while(opt!='q');
  

  ========================== 
  char opt;

  do
  {
    printf("(a) Menus.\n");
    printf("(b) Menu 2.\n");
    printf("(q) Quit.\n");
    printf("Opção: ");
    scanf(" %c",&opt);
    
    system("CLS");

    switch(opt)
    {
      case 'a':  
      case 'A':  printf("Menus\n"); break;
      case 'b':
      case 'B':  printf("Menu2\n"); break;
      case 'q':  
      case 'Q':  printf("Saiu\n");  break;
      default:   printf("Inválido\n");
   
    } 


  }while(opt!='q' && opt!='Q');  




*/
