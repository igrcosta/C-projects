#include <iostream>
#include <string>
#include <vector>

using namespace std;

class loja {
protected:
    std::string nome;
    std::string telefone;
    double price;

public:
    //construtor (nome da classe + declaração de var no 1o (), coloca : e mostra cada variável onde vai ser amazenada)
    loja(string nome, string telefone, double price){
    this -> nome = nome;
    this -> telefone = telefone;
    this -> price = price;
    }

    //aparentemente, se eu criar uma array de objetos sem ter colocado algo dentro desses objetos
    //o array não consegue ser criado, então vou criar um construtor padrão, só para a função cadastrolojas
    //poder ir substituindo esses valores e fazer seu trabalho

    loja() {
    nome = "";
    telefone = "";
    price = 0.0;}

    //setters
    //crio uma função que tem string nome como parâmetro, assim, o que eu entregar pra ela, vai sobrescrever
    void setnome (string nome) {
    this->nome = nome;}

    void settelefone (string telefone){
    this->telefone = telefone;}

    void setprice (double price){
    this -> price = price;}


    //getters
    //como precisamos pegar alguma variável, usamos int para esse método, com um return do que queremos pegar
    string getnome(){
    return nome;
    }

    string gettel(){
    return telefone;
    }

    double getprice(){
    return price;
    }
};

void cadastrolojas(loja lojas[10]){

    std::string tempNome;
    std::string tempTel;
    double tempPrice;

    //criamos variáveis temporárias para poder atribuir elas ao setters

    for (int contador = 0; contador <10; contador ++){
        cout << "Vc esta preenchendo dados da loja " << contador+1 << endl;
        cout << "Qual o nome dessa loja?" << endl;
        cin >> tempNome;
        lojas[contador].setnome(tempNome);

        cout <<"\nQual o telefone dessa loja?" << endl;
        cin >> tempTel;
        lojas[contador].settelefone(tempTel);

        cout <<"\nQual o valor do produto dessa loja?" << endl;
        cin >> tempPrice;
        lojas[contador].setprice(tempPrice);

        cout <<endl;
    }
}

void minorprice(loja lojas[10]){
    double bestprice = lojas[0].getprice();
    for (int i = 1; i < 10; i++){
            if(lojas[i].getprice() < bestprice){
                    bestprice = lojas[i].getprice();
            }
    }
    std::cout << "o produto com o melhor preco custa:\n" << bestprice << endl;
}

void mediumprice(loja lojas[10]){
    double soma = 0;
    double media = 0;
    for(int i=0; i <10; i++){
        soma += lojas[i].getprice();
    }
    media = soma / 10.00;

    std::cout << "A media do valor de cada produto de cada loja eh de:\n" << media<< endl;
}

void maxprice(loja lojas[10]){
double worstprice = lojas[0].getprice();
    for (int i = 1; i < 10; i++){
            if(lojas[i].getprice() > worstprice){
                    worstprice = lojas[i].getprice();
            }
    }
    std::cout << "o produto com o pior preco custa:\n" << worstprice << endl;}


int main()
{
    //preciso que ele declare um vetor de alimentos e que deixe o user add informações das lojas e preço

    //aqui estou criando um array de objetos da classe loja, no caso, vamos usar 10
    loja lojas[10];

    //aqui cadastramos os preços de cada loja e seus dados
    cadastrolojas(lojas);

    //aqui, vamos verificar qual o menor preço dos que estão armazenados
    minorprice(lojas);

    //aqui, vamos verificar o preço médio dos produtos em geral
    mediumprice(lojas);

    //aqui, vamos ver qual loja tem o maior valor e por quanto seria esse preço
    maxprice(lojas);

    return 0;
}
