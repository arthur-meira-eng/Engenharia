/* ============================================================================

    Linguagem C, o curso definitivo
    Módulo 4 Aula 5
    switch
    
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
  char letra;
  
  printf("Digite a letra: ");
  scanf(" %c",&letra);
  
  switch(letra)
  {
    case 'a':
    case 'A':
     printf("A letra \x82 A\n");
     break; 
    case 'b':
    case 'B':
     printf("A letra \x82 B\n");
     break;  
    case 'd':
    case 'D':
     printf("A letra \x82 D\n");
     break;  
    default:
     printf("Letra nao encontrada.\n");          
    
  }

  
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
  ==============================
  char conc;
  
  printf("Digite a inicial da concession\xA0ria: ");
  scanf(" %c",&conc);
  
  switch(conc)
  {
    case 'F': 
      printf("FIAT\n");     
      break;
    case 'V':
      printf("VOLKS\n");
      break;
    case 'R':
      printf("RENAULT\n");
      break;
    case 'H':
      printf("HYUNDAI\n");
      break;                                        
  }  


  ==============================
  int nota;
  
  printf("Digite a nota do aluno: ");
  scanf("%d",&nota);
  
  switch(nota)
  {
    case 7:
      printf("Aprovado! Bolsa de 10%%\n");  
      break;          
    case 8:
      printf("Aprovado! Bolsa de 20%%\n");  
      break;  
    case 9:
      printf("Aprovado! Bolsa de 30%%\n");  
      break;  
    case 10:
      printf("Aprovado! Bolsa de 40%%\n");  
      break;  
    default:
      printf("Reprovado!\n");              
              
  }


  ==============================
  int opt = 0;
  
  printf("1, 2 ou 3- Menu Principal\n"); 
  printf("4        - Help\n");
  printf("5        - Saida\n");
  printf("Escolha a opcao: ");
  scanf("%d",&opt);
  
  switch(opt)
  {
    case 1:
    case 2:
    case 3:
     printf("Acesso ao menu principal\n");
     break;
    case 4:
     printf("Acesso ao help\n");
     break;
    case 5:
     printf("Saida\n");           
                    
  }



  ==============================
  char letra;
  
  printf("Digite a letra: ");
  scanf(" %c",&letra);
  
  switch(letra)
  {
    case 'a':
    case 'A':
     printf("A letra \x82 A\n");
     break; 
    case 'b':
    case 'B':
     printf("A letra \x82 B\n");
     break;   
    default:
     printf("Letra nao encontrada.\n");          
    
  }




*/
