#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Cliente {
protected:
    string nome, nascimento, adress, telefone;

public:
    //construtor abaixo:
    //primeiro vem o nome da classe, depois, a declaração do que cada um vai receber no 1o parênteses, aí vem :, para depois, o nome da variável e oq ela receber com ().
    Cliente(std::string nome, std::string nascimento, std::string adress, std::string telefone):nome(nome), nascimento(nascimento), adress(adress), telefone(telefone) {
    };
    //as chaves precisam estar depois da construção

    //setters
    //método para definir nome, ele vai tacar o novoNome para sobrescrever o valor de nome
    void setNome(const string& novoNome){
    this->nome = novoNome;}

    void setNascimento(const string& novoNascimento){
    this->nascimento = novoNascimento;}

    void setAdress(const string& novoAdress){
    this->adress = novoAdress;}

    void setTelefone(const string& novoTelefone){
    this->telefone = novoTelefone;}

    // Método para exibir dados (TESTE)
    void exibirDados() const {
        cout << "Nome: " << nome << ", Nascimento: " << nascimento
             << ", Endereço: " << adress << ", Telefone: " << telefone << endl;
}
};

void criar_user (vector<Cliente>& Clientes, int num){
    string temp_nome, temp_nascimento, temp_adress, temp_telefone;

    for(int i = 0; i < num; i++) {

    //criamos um objeto vazio de Cliente para podermos guardar os dados nele e tacar no vetor depois
    Cliente novo_cliente ("","","","");

    //usuário insere nome do estudante do momento
    std::getline (cin,temp_nome);
    //colocamos o que ele inserir pra dentro do objeto com um setter que recebe temp_nome
    novo_cliente.setNome(temp_nome);

    //agora, usuário insere nascimento dele
    std::getline (cin,temp_nascimento);
    //igual nome, mas com nascimento
    novo_cliente.setNascimento(temp_nascimento);

    //agora, usuário insere endreço dele
    std::getline (cin,temp_adress);
    //igual nascimento, mas com endreço
    novo_cliente.setAdress(temp_adress);

    //agora, usuário insere telefone dele
    std::getline (cin,temp_telefone);
    //igual endreço, mas com telefone
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

    //usuário insere quantos clientes eles vai criar
    std::cin >> num;

    //limpando buffer para user getline na função criar_user
    std::cin.ignore(1000, '\n');

    std::vector<Cliente> Clientes;
    //criando um vetor para os clientes, por enquanto, vazio e de tamanho indefinido, mas ele é dinâmico

    criar_user (Clientes, num);
    //chamos a função que fica responsável por guardar cada cliente em seu lugar

    // Exibir os dados dos clientes (TESTE)
    for (const auto& cliente : Clientes) {
        cliente.exibirDados();
    }
    return 0;
}
