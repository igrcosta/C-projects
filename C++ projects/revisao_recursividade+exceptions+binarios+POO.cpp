#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>

using namespace std;

class Produto{
protected:
    char nome[50];
    float price;

public:
    //construtor
    Produto(const char* n = "", float p = 0.0){
    strncpy(nome, n, sizeof(nome)-1);
    nome[sizeof(nome)-1]= '\0';
    price = p;
    }

    const char* getnome() const{
    return nome;}

    float getprice() {
    return price;}

    void setnome(const char* n){
    strncpy(nome, n, sizeof(nome)-1);
    nome[sizeof(nome)-1]= '\0';
    }

    void setprice(float p){
    price = p;
    }
};
    //método para add produtos no arquivo binário, enquanto ainda salva no arquivo binário e trata exceções

    void addProduto(){
        char tempN[50];
        float tempP;

    Produto p1;
    cout << "Insira o nome para o produto a ser adicionado: " << endl;
    cin >> tempN;
    p1.setnome(tempN);

    cout << "Insira o valor para o produto a ser adicionado: " << endl;
    try{
        cin >> tempP;

        if(tempP <= 0){
            throw "Numero invalido, insira um numero inteiro maior que 0";
        }
        }
        catch(const char* msg){
        cout << "ERRO: " << msg << endl;
        while (tempP <= 0){
            cin >> tempP;
        }
        }
    p1.setprice(tempP);
    cout << "Valor adicionado com sucesso!" << endl;

    //salvando dados do objeto no arquivo

    ofstream arquivoE;
    arquivoE.open("produtos.bin", ios::binary | ios::app);
    if (arquivoE.is_open())
        {
            arquivoE.write((char*) &p1, sizeof(Produto));
    }

    arquivoE.close();
    }

    void lerProdutos(){
    cout << "====== Leitura de Produtos ======" << endl;

    ifstream arquivoL;
    arquivoL.open("produtos.bin", ios::binary);

    if(arquivoL.is_open()){
        Produto leitor;
    //crio um objeto vazio, para receber os valores de cada objeto para impressão

    while(arquivoL.read((char*) &leitor, sizeof(Produto))){
        cout << "Nome do produto: " << leitor.getnome() << endl;
        cout << "Valor: " << leitor.getprice() << endl;
        cout << "=================" << endl;
    }
    }
    else {
        cout << "Erro ao abrir arquivo" << endl;
    }

    arquivoL.close();

    }

    float pesquisaprod(){
    //nessa function quero que o user pesquise um objeto para trabalhar recursividade, retornando um valor

    char N[50];
    cout << "Insira o nome do produto a ser pesquisado: " << endl;
    cin >> N;

    Produto leitorC;

    ifstream arquivoC;
    arquivoC.open("produtos.bin", ios::binary);

    if(arquivoC.is_open()){
        while(arquivoC.read((char*) &leitorC, sizeof(Produto))){
            if(strcmp(leitorC.getnome(), N) == 0){
                cout << "Produto encontrado!" << endl;
                cout <<"Nome: " <<leitorC.getnome() << endl;
                cout <<"Valor: " << leitorC.getprice() << endl;
                arquivoC.close();
                return leitorC.getprice();
            }
        }
    }
    else {
        cout << "Erro ao abrir arquivo" << endl;
        }
    }

    //método recursivo para soma
    float somar(int N, float valor){
        if (N == 0){
            return 0;
        }
        return valor + somar(N-1, valor);
    }

int main()
{
    int option = 10;
    while(option != 0)
    {
        cout << "===== Bem vindo ao Menu! =====" << endl;
        cout << "1: Adicione um produto" << endl;
        cout << "2: Leia os produtos listados" << endl;
        cout << "3: Pesquisar e somar quantidades do produto" << endl;
        cout << "0: Sair" << endl;
        cin >> option;

        switch (option){
    case 1:
        addProduto();
        break;

    case 2:
        lerProdutos();
        break;

    case 3: {
        float valorp = pesquisaprod();

        int quantidade;
        cout << "Quantos produtos desse aqui vc quer somar?" << endl;
        cin >> quantidade;

        float total = somar(quantidade,valorp);

        cout << "O valor de "<< quantidade << " unidades do seu produto eh de:" << endl << total << " Reais" << endl;
    }
        break;

    case 0:
        cout << "Adeus" << endl;
        break;
        }
        }
    return 0;
}
