/* ============================================================================

    Linguagem C, o curso definitivo
    Módulo 5 Aula 3
    break e continue
    
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
  
 
  int numero;
  
  while(1)
  {
    printf("Digite um numero: ");
    scanf("%d",&numero);
    
    if(numero%2) break;
    
    printf("Tudo OK\n");

  }
  
  printf("ERRO, o numero \x82 impar\n");
  
  system("PAUSE");	                             /* pausa execução (Pressione qualquer tecla para continuar . . .) */
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
  =======================
  char i = 0;

  while(i < 15)
  {
    if(i==10) break;
    i++;
    printf("%d\n",i);

  } 


  =======================
  unsigned long int i=0;
  
  while(1)
  {
    if(kbhit()) break;
    i++;
    printf("%d\n",i);
         
  }

  
  =======================
  char ok, chr;

  ok = 0;

  while(!ok)
  {
    chr = getchar();     

    if(chr == '@')        
    {
      ok = 1;            
      continue;       
 
    }  
   
    putchar(chr+2);    

  }  
















*/
