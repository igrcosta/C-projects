#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Cliente {
protected:
    string nome, nascimento, adress, telefone;

public:
    //construtor abaixo:
    //primeiro vem o nome da classe, depois, a declara��o do que cada um vai receber no 1o par�nteses, a� vem :, para depois, o nome da vari�vel e oq ela receber com ().
    Cliente(std::string nome, std::string nascimento, std::string adress, std::string telefone):nome(nome), nascimento(nascimento), adress(adress), telefone(telefone) {
    };
    //as chaves precisam estar depois da constru��o

    //setters
    //m�todo para definir nome, ele vai tacar o novoNome para sobrescrever o valor de nome
    void setNome(const string& novoNome){
    this->nome = novoNome;}

    void setNascimento(const string& novoNascimento){
    this->nascimento = novoNascimento;}

    void setAdress(const string& novoAdress){
    this->adress = novoAdress;}

    void setTelefone(const string& novoTelefone){
    this->telefone = novoTelefone;}

    // M�todo para exibir dados (TESTE)
    void exibirDados() const {
        cout << "Nome: " << nome << ", Nascimento: " << nascimento
             << ", Endere�o: " << adress << ", Telefone: " << telefone << endl;
}
};

void criar_user (vector<Cliente>& Clientes, int num){
    string temp_nome, temp_nascimento, temp_adress, temp_telefone;

    for(int i = 0; i < num; i++) {

    //criamos um objeto vazio de Cliente para podermos guardar os dados nele e tacar no vetor depois
    Cliente novo_cliente ("","","","");

    //usu�rio insere nome do estudante do momento
    std::getline (cin,temp_nome);
    //colocamos o que ele inserir pra dentro do objeto com um setter que recebe temp_nome
    novo_cliente.setNome(temp_nome);

    //agora, usu�rio insere nascimento dele
    std::getline (cin,temp_nascimento);
    //igual nome, mas com nascimento
    novo_cliente.setNascimento(temp_nascimento);

    //agora, usu�rio insere endre�o dele
    std::getline (cin,temp_adress);
    //igual nascimento, mas com endre�o
    novo_cliente.setAdress(temp_adress);

    //agora, usu�rio insere telefone dele
    std::getline (cin,temp_telefone);
    //igual endre�o, mas com telefone
    novo_cliente.setTelefone(temp_telefone);


    //guardamos os dados do objeto novo_cliente no vetor, com o uso do push_back
    Clientes.push_back(novo_cliente);

    //em resumo, criamos um novo objeto, usamos setters para guardar cada coisa no seu lugar
    //e mandamos esse objeto para o vetor que vai pular de casa em casa.
    }
}

int main()
{
    int num;

    //usu�rio insere quantos clientes eles vai criar
    std::cin >> num;

    //limpando buffer para user getline na fun��o criar_user
    std::cin.ignore(1000, '\n');

    std::vector<Cliente> Clientes;
    //criando um vetor para os clientes, por enquanto, vazio e de tamanho indefinido, mas ele � din�mico

    criar_user (Clientes, num);
    //chamos a fun��o que fica respons�vel por guardar cada cliente em seu lugar

    // Exibir os dados dos clientes (TESTE)
    for (const auto& cliente : Clientes) {
        cliente.exibirDados();
    }
    return 0;
}
