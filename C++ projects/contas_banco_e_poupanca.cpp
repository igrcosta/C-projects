#include <iostream>

using namespace std;

//na classe conta, é preciso que tenha métodos para depositar uma
//quantia, sacar uma quantia e obter o saldo. Para cada saque será debitada também uma taxa de
//operação equivalente à 0.5% do valor sacado, mas é preciso criar uma classe herdando conta, que tem uma taxa menor de saque
class conta{
protected:
    double saldo = 0;

public:

    //construtor
    conta(double saldo){
    this -> saldo = saldo;}

    //getters e setters

    double getsaldo () const{
    return saldo;}

    void aumentarsaldo (double valor){
        saldo += valor;
    }

    void diminuirsaldo (double valor){
    saldo -= valor;
    }

    //métodos extras para se trabalhar

    void depositar(){
        double valdeposito;

    cout <<"vamos depositar um valor na sua conta" << endl;
    cout << "Qual o valor que vai ser depositado?" << endl;
    cin >> valdeposito;

    aumentarsaldo(valdeposito);

    cout << "Depositado o valor de: " << valdeposito <<" Reais na sua conta" << endl;
    }

    virtual void sacar(){
        double valsaque;
        double valtotal;

        cout << "vamos realizar um saque de uma quantia na sua conta" << endl;
        cout << "qual a quantia que deseja sacar? (taxa de funcionamento de 0.5%)" << endl;
        cin >> valsaque;

        double taxa = valsaque * 0.005;
        valtotal = valsaque + taxa;

        cout << "sera retirado da sua conta o valor de: " << valtotal << " devido a taxa" << endl;

        diminuirsaldo(valtotal);
    }

    void versaldo(){
        cout <<"Vamos ver seu saldo atual" << endl;
        cout <<"Seu saldo atual esta em: "<< getsaldo() << " Reais" <<endl;
    }
};

//classe derivada da conta original para fazer a conta premium
class contaDeluxe: public conta {

public:
    //construtor
    contaDeluxe(double saldo) : conta(saldo) {}

    //método diferente para saque
    void sacar() override {
        double valsaque;
        double valtotal;

        cout << "Vamos realizar um saque de uma quantia na sua conta Deluxe" << endl;
        cout << "Qual a quantia que deseja sacar? (taxa de funcionamento de 0.1%)" << endl;
        cin >> valsaque;

        double taxa = valsaque * 0.001;
        valtotal = valsaque + taxa;

        cout << "Vai ser retirado da sua conta o valor de: " << valtotal << " Reais totais" << endl;
        diminuirsaldo(valtotal);
    }

};

class contapoupanca : public conta {
public:
//construtor
contapoupanca(double saldo) : conta(saldo) {}

//método especial para render juros da poupança

void investimento () {
    double valinvest;

    cout << "----------------------------" << endl;
    cout << "Bem vindo a sua tela de investimentos - Poupança" << endl << "Qual valor vai ser investido?" << endl;
    cin >> valinvest;

    cout << "Retirando agora " << valinvest << " R$ da sua conta para o investimento" << endl;
    diminuirsaldo(valinvest);

    cout << "Nossa taxa de juros mensal esta em 1% mensal!" << endl;

    cout <<"Investimento realizado com sucesso!" << endl;
    passarmeses(valinvest);

}

void passarmeses(double valinvest){
    int escolha;

    cout << "----------------------------" << endl;
    cout << "Quer simular 1 mes no futuro para ver o quanto vai receber com o juros mensal?" << endl;
    cout << "1 - SIM" << endl << "2- N" << endl;
    cin >> escolha;

    if (escolha == 1) {
        cout << "Seu saldo 1 mes no futuro sera de:" << endl;
        double simulation = valinvest * 1.01;
        cout << simulation << endl;
        cout << "----------------------------" << endl;

    } else {
    cout << "ent sai daqui kk" << endl;
    }
}

};

int main()
{
    //aqui no main, o usuário vai ter um menu, para criar sua conta
    //após o usuário definir o tipo de conta (comum ou especial),
    //o menu permitirá ao usuário depositar, sacar e mostrar saldo da conta instanciada.

    int escolha;
    int option;

    cout << "Bem vindo ao Banco Fazoeli!" << endl;
    cout <<"O que deseja fazer?" << endl;
    cout << "1- Criar conta" << endl << "2- Fechar programa" << endl;
    cin >> escolha;

    if (escolha == 1){
        escolha = 0;
        cout << "Qual tipo de conta gostaria de criar?" << endl;
        cout << "1- Conta default" << endl << "2- Conta deluxe" << endl << "3- Conta poupança"<<endl;
        cin >> option;
        if (option == 1){
            cout << "Ok seu pobre, vc esta na sua conta agora!" << endl;
            conta contanova(0);
            escolha = 0;
            while(escolha != 5){
                    cout << "O que quer fazer na sua conta?" << endl;
                    cout << "1- depositar na sua conta" << endl << "2- sacar um valor" << endl;
                    cout << "3- Ver seu saldo" << endl;
                    cout << "5- Sair do programa" << endl << endl;
                    cin >> escolha;
                switch (escolha){
                    case 1:
                    contanova.depositar();
                    break;

                    case 2:
                    contanova.sacar();
                    break;

                    case 3:
                    contanova.versaldo();
                    break;

                    case 5:
                    cout << "Adeus" << endl;
                    return 0;
                }
            }
        }
        else if (option == 2){
        cout << "Ok amado cliente, vamos criar sua conta em alguns milisegundos" << endl;
        contaDeluxe contapremium(0);
        escolha = 0;
        while(escolha != 5) {
                    cout << "O que quer fazer na sua conta?" << endl;
                    cout << "1- depositar na sua conta" << endl << "2- sacar um valor" << endl;
                    cout << "3- Ver seu saldo" << endl;
                    cout << "5- Sair do programa"<< endl << endl;
                    cin >> escolha;
                switch (escolha){
                    case 1:
                    contapremium.depositar();
                    break;

                    case 2:
                    contapremium.sacar();
                    break;

                    case 3:
                    contapremium.versaldo();
                    break;

                    case 5:
                    return 0;
                }
        }
        }else if (option == 3){
            cout << "Ok seu velho, vc esta na sua conta agora!" << endl;
            contapoupanca idosa(0);
            escolha = 0;
            while(escolha != 5){
                    cout << "O que quer fazer?" << endl;
                    cout << "1- depositar na sua conta" << endl << "2- sacar um valor" << endl;
                    cout << "3- Ver seu saldo" << endl << "4- Fazer Investimento na Poupança" << endl;
                    cout << "5- Sair do programa" << endl;
                    cin >> escolha;
                switch (escolha){
                    case 1:
                    idosa.depositar();
                    break;

                    case 2:
                    idosa.sacar();
                    break;

                    case 3:
                    idosa.versaldo();
                    break;

                    case 4:
                    idosa.investimento();
                    break;

                    case 5:
                    cout << "Adeus" << endl;
                    return 0;
                }
            }
            }
}
else {
    cout << "Se n vai usar, pq abriu? D:" << endl;}
    return 0;
}
