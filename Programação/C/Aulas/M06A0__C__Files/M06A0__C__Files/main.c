/* ============================================================================

    Linguagem C, o curso definitivo
    Módulo 6 Aula 0
    Funções e Procedimentos
    
    Autor: Dr. Eng. Wagner Rambo
    Data:  Maio de 2021

============================================================================ */


/* ========================================================================= */
/* --- Bibliotecas --- */
#include <stdio.h>
#include <stdlib.h>

/* ========================================================================= */
/* --- Protótipo das Funções --- */
void asteriscos();
void sustenidos();


/* ========================================================================= */
/* --- Função Principal --- */
main()
{
  unsigned numero;
     
  while(1)
  {
    printf("Digite um numero: ");
    scanf("%d",&numero);
    
    if(numero == 7) asteriscos();
    if(numero == 8) sustenidos();
    if(!numero)     break;
  
  } /* end while */
  

  system("PAUSE");	                             /* pausa execução (Pressione qualquer tecla para continuar . . .) */
  return 0;                                      /* retorna 0, se main for executada corretamente */
  
} /* end main */

 
/* ========================================================================= */
/* --- Desenvolvimento das Funções --- */
void asteriscos()
{
  char asts;
  
  for(asts=0; asts<10; asts++) 
    putchar('*');
    
  putchar('\n');  
      
} /* end asteriscos */


void sustenidos()
{
  char asts;
  
  for(asts=0; asts<10; asts++) 
    putchar('#');
    
  putchar('\n');       
  
} /* end sustenidos */
 

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
  ===================================
  int i, j;

  for(i=0;i<3;i++)
  {
    for(j=0;j<30;j++)
     putchar('#');
    
    putchar('\n');

  } 

  printf("\nMenu principal do programa\n\n");

  for(i=0;i<3;i++)
  {
    for(j=0;j<30;j++)
     putchar('#');
    
    putchar('\n');

  } 

  printf("\nMenu tarefas a executar\n\n");

  for(i=0;i<3;i++)
  {
    for(j=0;j<30;j++)
     putchar('#');
    
    putchar('\n');

  } 

  printf("\nMenu Help\n\n");


 


*/
