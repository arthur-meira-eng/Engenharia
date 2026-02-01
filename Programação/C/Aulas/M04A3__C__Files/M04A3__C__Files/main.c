/* ============================================================================

    Linguagem C, o curso definitivo
    Módulo 4 Aula 3
    if else if
    
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
  float n1, n2;
  int opt;
  
  printf("Digite n1: ");
  scanf("%f",&n1);
  printf("Digite n2: ");
  scanf("%f",&n2);
   
  printf("1 - Somar\n");
  printf("2 - Subtrair\n");
  printf("3 - Multiplicar\n");
  printf("4 - Dividir\n");
  printf("Escolha a opcao: ");
  scanf("%d",&opt);
  
  if(opt == 1)
    printf("%.2f + %.2f = %.2f\n",n1,n2,n1+n2);
  else if(opt == 2)
    printf("%.2f - %.2f = %.2f\n",n1,n2,n1-n2);
  else if(opt == 3)
    printf("%.2f x %.2f = %.2f\n",n1,n2,n1*n2);
  else if(opt == 4)
    printf("%.2f / %.2f = %.2f\n",n1,n2,n1/n2);
  else
    printf("Opcao invalida\n");
     
  
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
   
  =============================  
  
  int temp, energy;

  printf("Temperatura em graus Celsius: ");
  scanf("%d",&temp);
  printf("Energia em \%: ");
  scanf("%d",&energy);
  
  if(temp < 30)
    if(energy > 80)
      printf("Aciona aquecedor.\n");
    else
      printf("Alerta: Energia insuficiente.\n");

  else
    printf("Temperatura ok.\n");



  ============================= 

  int val;
  
  printf("Insira um valor: ");
  scanf("%d",&val);

  if(val == 1)
    printf("Valor igual a 1\n");
  else if(val == 2)
    printf("Valor igual a 2\n");
  else if(val == 3)
    printf("Valor igual a 3\n");
  else
    printf("Valor nao encontrado\n");


  ============================= 
  
  
  int numero, chute;
  
  printf("Insira um numero de 0 a 10: ");
  scanf("%d",&numero);
  
  if(numero < 0 || numero > 10)
  {
    printf("Entrada invalida. O numero \x82 5.\n");
    numero = 5;
    system("PAUSE");
  }
  system("CLS");
  
  printf("Adivinhe o numero: ");
  scanf("%d", &chute);
  
  if(chute == numero)
    printf("Acertou, o numero \x82 %d!!!\n", numero);
  else if(chute > numero)
    printf("Errou, o numero \x82 menor!\n");
  else
    printf("Errou, o numero \x82 maior!\n");
    

  =============================    
    
  float n1, n2;
  int opt;
  
  printf("Digite n1: ");
  scanf("%f",&n1);
  printf("Digite n2: ");
  scanf("%f",&n2);
   
  printf("1 - Somar\n");
  printf("2 - Subtrair\n");
  printf("3 - Multiplicar\n");
  printf("4 - Dividir\n");
  printf("Escolha a opcao: ");
  scanf("%d",&opt);
  
  if(opt == 1)
    printf("%.2f + %.2f = %.2f\n",n1,n2,n1+n2);
  else if(opt == 2)
    printf("%.2f - %.2f = %.2f\n",n1,n2,n1-n2);
  else if(opt == 3)
    printf("%.2f x %.2f = %.2f\n",n1,n2,n1*n2);
  else if(opt == 4)
    printf("%.2f / %.2f = %.2f\n",n1,n2,n1/n2);
  else
    printf("Opcao invalida\n");




*/
