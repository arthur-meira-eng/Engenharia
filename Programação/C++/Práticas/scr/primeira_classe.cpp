/******************************************************************************
 * Projeto: Nome do Projeto
 * Arquivo: primeira_classe.cpp
 * Autor: Arthur Henrique Santos Meira
 * Data: CURRENT_DAY/02/2026
 * Descrição:
 * Descreva aqui a funcionalidade do código (ex: Controle DALI / Cálculo de Reynolds)
 * 
 * Organização: UnB / I.ALL Automação
 *****************************************************************************/


//inclusão de bibliotecas 
//diretivas de pre processametno
#include <iostream>
#include <string> //class de string no padrão c++

using std::string;
using std::getline;
using std::cout;
using std::cin;
using std::endl;


//---- Desenvolvimento da Classe ---
class SalesScore         
{
    public:             //public é um especificador de acesso
        void bootSystem(string storeTitle)
        {
            cout << "Score de Vendas!\n"<<storeTitle <<endl;
        }

}; //end class SalesScore


//--- Função Principal ---
int main() 
{
    string storeTitle;                          //String de caracteres para armazenar o titulo da loja
    SalesScore mySales;                         //Objeto mySales

    cout <<"Digite o nome da loja:"<<endl;
    getline(cin,storeTitle);                    //Lê o nome da loja com espaços em branco
    cout<<endl;                                 //pula uma linha

    mySales.bootSystem(storeTitle);

    return 0;
} //end main