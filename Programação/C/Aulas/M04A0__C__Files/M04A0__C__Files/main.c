/* ============================================================================

    Linguagem C, o curso definitivo
    Módulo 4 Aula 0
    Operadores Relacionais
    
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
  
  int dist, temp=0;
 
  printf("Entre com a distancia em cm: ");
  scanf("%d",&dist);
 
  if(dist <= 25)
  {
     printf("Robo desvia obstaculo.\n");
     temp = dist;
  }
  
  
  
  if(temp!=0)
    printf("O robo detectou na distancia de = %dcm\n",temp);
    
  else
    printf("O robo nao detectou obstaculos.\n");
 

  
  
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
  
  float salario, vendas;
  printf("Informe o salario R$: ");
  scanf("%f",&salario);
  printf("Informe o valor em vendas R$: ");
  scanf("%f",&vendas);
  
  if(vendas > 10000.0)
    salario = salario+(salario/100.0*10.0);

  printf("O salario foi de R$: %.2f\n", salario);

  ===========================
  
  float temperatura;

  printf("Digite a temperatura em graus Celsius: ");
  scanf("%f",&temperatura);

  if(temperatura >= 50.0)
    printf("Alerta, temperatura elevada.\n");
  else
    printf("Temperatura normal.\n");



  ===========================
  
  int dist, temp;
 
  printf("Entre com a distancia em cm: ");
  scanf("%d",&dist);
 
  if(dist <= 25)
  {
     printf("Robo desvia obstaculo.\n");
     temp = dist;
  }





*/


