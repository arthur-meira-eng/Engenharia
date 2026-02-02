/******************************************************************************
 * Projeto: 
 * Arquivo: uso_de_cin.cpp
 * Autor: Arthur Henrique Santos Meira
 * Data: CURRENT_DAY/02/2026
 * Descrição: Operanco com as entradas que o usuario insere no programa
 * 
 * Organização: UnB / I.ALL Automação
 ******************************************************************************/

#include <iostream>


int main() 
{
    float num1, num2;

    std::cout<<">Digite dois numeros:\n";
    std::cin>> num1 >> num2; //faz a leitura de dois valores (ignora o enter)

    std::cout<<"\n----------Resultado das comparacoes----------\n";
    
    if(num1<num2)
        std::cout<<num1<< " < " <<num2;

    else if(num1 == num2)
        std::cout<<num1<< " = " <<num2;

    else
        std::cout<<num1<< " > " <<num2;

    std::cout<<"\n----------Operacoes basicas------------------\n";

    std::cout<<"Soma:          "<<num1 + num2<< "\n";
    std::cout<<"Subtraxao:     "<<num1 - num2<< "\n"; 
    std::cout<<"Multiplicacao: "<<num1 * num2<< "\n";
    std::cout<<"Divisao:       "<<num1 / num2<< "\n"; 


    return 0;
}