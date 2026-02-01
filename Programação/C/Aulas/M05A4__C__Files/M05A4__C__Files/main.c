/* ============================================================================

    Linguagem C, o curso definitivo
    Módulo 5 Aula 4
    O Laço for
    
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
  char     done = 0;
  unsigned linha, coluna;
  
  for(linha=0;linha<4;linha++)
  {
     for(coluna=0;coluna<16;coluna++)
      if(coluna<6 && !done) printf("%2Xh ",coluna); 
      else                  printf("FFh ");
       
     done = 1; 
     putchar('\n');                         
                              
                              
  } /* end for */
   
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
  
  
  int a, b;

  for(a=0, b=0; a+b<=50; a++, b++)
   printf("%3d\n",a+b);
  
  
  =======================  
  int chute, number;

  printf("Insira um numero para o seu amigo acertar: ");
  scanf("%d",&number);
  system("CLS");

  for(chute=0; chute!= number; )
  {
    printf("Tente acertar o numero: ");
    scanf("%d",&chute);

  }

  printf("Acertou!\n");
  
  
  =======================   
  for( ; ; )
  {
    printf("BOM DIA!\n");
    if(kbhit()) break;

  }  
  
  
  =======================  
  int i,j;
  
  for(i=0;i<5;i++)
  {
     for(j=0;j<10;j++)
      printf(" 1 ");
      
     putchar('\n');                 
                            
  }
  


*/
