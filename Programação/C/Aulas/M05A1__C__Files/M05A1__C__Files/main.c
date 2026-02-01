/* ============================================================================

    Linguagem C, o curso definitivo
    Módulo 5 Aula 1
    Laço while
    
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
  int tab, n;
  
  tab = 1;
  
  while(tab <=9)
  {
    n = 1;
    
    printf("=============\n");
    printf("Tabuada do %d\n",tab);
    
    while(n <= 9)
    {
      printf("%2d x %2d = %2d\n",n,tab,n*tab);
      n++;       
            
    } /* end while anin. */ 
    
    tab++; 
    putchar('\n');      
              
  } /* end while */
  
  
  
  
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
  ================================
  
  int val = 0;               
  
  while(val <= 20)            
  {
    printf("%3d\n",val);       
    val++;                    

  }  
  

  ================================
    
  int i = 10;

  while(i)
  {
    printf("9 x %2d = %2d\n", i, 9*i);
    i--;

  }  


*/
