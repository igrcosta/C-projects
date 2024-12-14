#include <iostream>
#include <string>
using namespace std;

class Veiculo{
protected:
    int Velmax;
    string cor;

public:
    Veiculo(int velmax, string color):Velmax(velmax),cor(color){}

    int getVel(){
    return Velmax;}

    string getcor(){
    return cor;}

    void setvel(int VM){
    Velmax = VM;}

    void setcolor(string c){
    cor = c;}

    //método move

    virtual void move(){
    cout << "Este veiculo anda!" << endl;}};

    class Carro:public Veiculo{
public:
    Carro(int vel, string c): Veiculo(vel,c){}

    void move()override{
    cout << "Tem algm me dirigindo!"<< endl;}};

    class Aviao : public Veiculo {
public:
    Aviao(int vel, string c):Veiculo(vel, c){}

    void move()override{
    cout << "Eu to voando alto kk" << endl;}
    };

int main()
{
    Carro v1{120,"Blue"};
    v1.move();

    Aviao a1{1000,"Black"};
    a1.move();
    //erro pra bool

    Aviao a2{2000,"Purple"};
    a2.move();
    return 0;
}
