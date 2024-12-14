#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal{
protected:
    string nome;
    int idade;
    string som_t;

public:
    //construtor
    Animal(string n, int i, string st) : nome(n),idade(i), som_t(st){}

    //getters & setters

    string getnome(){
    return nome;}

    int getage(){
    return idade;}

    string getsomt(){
    return som_t;}

    void setnome(string n){
    nome = n;}

    void setage(int i){
    idade = i;}

    void setsomt(string st){
    som_t = st;}

    //métodos específicos

    virtual void fazSom(){
    cout << getsomt() << endl << "som doido!" << endl;
    }

    //a função abaixo não precisa de virtual, ela não vai ser sobrescrita por papagaio nem por nenhuma outra classe
    void exibeInfo(){
    cout << "Info do animal:" <<endl;
    cout << "Nome: " << getnome() << endl;
    cout << "Idade: " << getage() << endl; }
};

class Leao:public Animal{
public:
    //construtor adaptado para herdar tudo de animal
    Leao(string n, int i, string st) : Animal(n, i, st){}

    //método sobrescrito
    void fazSom() override{
    cout << getsomt() << endl << "O leao esta rugindo ferozmente!" << endl;}
};

class Papagaio:public Animal{
public:
    string frase; //frase que o papagaio fala

    //construtor adaptado
    Papagaio(string n, int i, string st, string f):Animal(n,i,st), frase(f){}

    void ensinaFrase(){
    cout << "Insira a frase que o Papagaio vai dizer" << endl;
    cin >> frase;
    }

    void fazSom() override{
        cout << getsomt() << endl << frase << endl;
    }
};

int main()
{
    Leao L1{"Alex",9,"ra"};
    L1.setsomt("rugido");


    Papagaio P1{"Loro", 5, "pa", "gaio"};
    P1.setsomt("piado");
    P1.ensinaFrase();

    vector <Animal*> Zoo;
    Zoo.push_back(&L1);
    Zoo.push_back(&P1);

    for(Animal* animal: Zoo){
        animal -> exibeInfo();
        animal -> fazSom();
    }
    return 0;
}
