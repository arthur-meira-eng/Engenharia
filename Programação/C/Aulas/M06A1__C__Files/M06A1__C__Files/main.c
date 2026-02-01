/* ============================================================================

    Linguagem C, o curso definitivo
    Módulo 6 Aula 1
    Parâmetros de Funções
    
    Autor: Dr. Eng. Wagner Rambo
    Data:  Maio de 2021

============================================================================ */


/* ========================================================================= */
/* --- Bibliotecas --- */
#include <stdio.h>
#include <stdlib.h>

/* ========================================================================= */
/* --- Protótipo das Funções --- */
void freq_555(float Ra, float Rb, float C); 
void carac(char ch);
void esp_carac(char chr, int number); 
void div_rest(int a, int b);

 
 
/* ========================================================================= */
/* --- Função Principal --- */
main()
{
   
   
   freq_555(4.7E3, 27.0E3, 100E-9);
   carac('a');

  system("PAUSE");	                             /* pausa execução (Pressione qualquer tecla para continuar . . .) */
  return 0;                                      /* retorna 0, se main for executada corretamente */
  
} /* end main */

 
/* ========================================================================= */
/* --- Desenvolvimento das Funções --- */
void freq_555(float Ra, float Rb, float C)
{
  float freq;
  
  freq = 1.44/((Ra+2*Rb)*C);    
  
  printf("freq= %.2fHz\n",freq); 
     
} /* end freq_555 */


void carac(char ch)
{
  switch(ch)
  {
    case 'a': putchar('A'); break;
    case 'b': putchar('B'); break;
    case 'c': putchar('C'); break;
    case 'd': putchar('D'); break;
    default:  putchar('E');
              putchar('r');
              putchar('r');
              putchar('o');
  
  } 

  putchar('\n');

} /* end carac */ 


void div_rest(int a, int b)
{
    printf("Divisao= %d\n", a/b);
    printf("Resto=   %d\n", a%b);

}  


void esp_carac(char chr, int number)
{
  char i;
  
  for(i=0; i<number; i++) 
    putchar(chr);
    
  putchar('\n');  
      
} /* end esp_carac */

 
 

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
  void div_rest(int a, int b)
  {
    printf("Divisao= %d\n", a/b);
    printf("Resto=   %d\n", a%b);

  }  
  
  
  ===================================  
  void carac(char ch)
  {
    switch(ch)
    {
      case 'a':  putchar('A'); break;
      case 'b':  putchar('B'); break;
      case 'c':  putchar('C'); break;
      case 'd':  putchar('D'); break;
      default:   putchar('E');
                 putchar('r');
                 putchar('r');
                 putchar('o');
  
    } 

    putchar('\n');

  }  




  ====================
  unsigned numero;
     
  while(1)
  {
    printf("Digite um numero: ");
    scanf("%d",&numero);
    
    if(numero == 7) esp_carac('*', 12);
    if(numero == 8) esp_carac('#', 27);
    if(numero == 9) esp_carac('$', 30);
    if(!numero)     break;
 
  } 
 


*/
