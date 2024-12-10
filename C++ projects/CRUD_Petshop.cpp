#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Dog{
public:
    string nome = "";
    int idade = 0;
    string raca = "";
    double price = 0;

//construtor
Dog(string nome,int idade, string raca, double price){
this -> nome = nome;
this -> idade = idade;
this -> raca = raca;
this -> price = price;
}
};

class Cat{
public:
    string nome = "";
    int idade = 0;
    string raca = "";
    double price = 0;

//construtor
Cat(string nome,int idade, string raca, double price){
this -> nome = nome;
this -> idade = idade;
this -> raca = raca;
this -> price = price;
}
};

class Loja {
protected:
    vector<Dog> dogs;
    vector<Cat> cats;

    //construtor
public:
    Loja(): dogs(), cats(){}
    //utilizei dois pontos aqui, pois estamos pegando referências
    //de outros locais.

    //getters
    vector<Dog> getDogs() const{
    return dogs;}

    vector<Cat> getCats() const{
    return cats;}

    //setters
    void addDog(Dog& dog){
    dogs.push_back(dog);}
    //estou dizendo que dentro da classe dog (ponteiro), vou trabalhar com seus objetos
    //esse objeto será acrescentado ao vetor dogs, pelo comando push_back.

    void addCat(Cat& cat){
    cats.push_back(cat);}
    //mesmo que dogs, mas com cat.

    //método para cadastrar pets
    void cadastropet(){
    int option;

    string tempnome;
    int tempidade;
    string tempraca;
    double tempprice;
    //variáveis temporárias


    cout <<"vamos cadastrar um gato(digite 1) ou cachorro(digite 2)?" << endl;
    cin >> option;

    if(option == 1){
        cout << "Digite o nome do gato:"<< endl;
        cin >> tempnome;
        cout << "Digite a idade do gato:"<< endl;
        cin >> tempidade;
        cout << "Digite a raca do gato:"<< endl;
        cin >> tempraca;
        cout << "Digite o valor do gato(Ex:200.00):"<< endl;
        cin >> tempprice;

        Cat newcat(tempnome, tempidade, tempraca, tempprice);
        addCat(newcat);
        cout << "\nGato " << tempnome << " adicionado com sucesso"<< endl;
        cout << "------------------------" << endl;
    }else if(option == 2){
        cout << "Digite o nome do cachorro:"<< endl;
        cin >> tempnome;
        cout << "Digite a idade do cachorro:"<< endl;
        cin >> tempidade;
        cout << "Digite a raca do cachorro:"<< endl;
        cin >> tempraca;
        cout << "Digite o valor dele(Ex:200.00):"<< endl;
        cin >> tempprice;

        Dog newdog(tempnome, tempidade, tempraca, tempprice);
        addDog(newdog);
        cout << "\nCachorro " << tempnome << " adicionado com sucesso" << endl;
        cout << "------------------------" << endl;
        }
}

void verDogs(){
cout << "Analisando cachorros disponíveis" << endl;

vector<Dog> dogsDisponiveis = getDogs();
if(dogsDisponiveis.empty()){
    cout << "sem cachorros no momento" << endl;
} else {
cout << "apresentando cachorros disponíveis:" << endl;

for(size_t i = 0; i < dogsDisponiveis.size(); i++){
//para o tamanho de i no vetor = 0, enquanto i for menor do que o tamanho do vetor, i aumenta;
cout << "Cachorro " << i + 1 << ":" << endl;
    cout << "Nome: " << dogsDisponiveis[i].nome << endl;
    cout << "Idade: " << dogsDisponiveis[i].idade << endl;
    cout << "Raça: " << dogsDisponiveis[i].raca << endl;
    cout << "Valor: R$ " << dogsDisponiveis[i].price << endl;
    cout << "------------------------" << endl;
}
}
}

void verCats(){
cout << "Analisando gatos disponíveis" << endl;

vector<Cat> catsavaliable = getCats();
if(catsavaliable.empty()){
    cout << "sem gatos no momento" << endl;
} else {
cout << "apresentando gatos disponíveis:" << endl;

for(size_t i = 0; i < catsavaliable.size(); i++){
//para o tamanho de i no vetor = 0, enquanto i for menor do que o tamanho do vetor, i aumenta;
cout << "Gato " << i + 1 << ":" << endl;
    cout << "Nome: " << catsavaliable[i].nome << endl;
    cout << "Idade: " << catsavaliable[i].idade << endl;
    cout << "Raca: " << catsavaliable[i].raca << endl;
    cout << "Preço: R$ " << catsavaliable[i].price << endl;
    cout << "------------------------" << endl;
}
}
}

//método pra apagar gatos

void eraselastCat(){
    cout << "que noticia boa! o ultimo gato adicionado vai pro seu lar! :D" << endl;
    cats.pop_back();
    cout << "o ultimo gato adicionado esta fora da lista!" << endl;
    cout << "------------------------" << endl;
}
//método para apagar cachorros

void eraselastDog(){
    cout << "que noticia boa! o ultimo cachorro adicionado vai pro seu lar! :D" << endl;
    dogs.pop_back();
    cout << "o ultimo cachorro adicionado esta fora da lista!" << endl;
    cout << "------------------------" << endl;
}

};


int main()
{
    Loja minhaloja;
    //criei o objeto que usaremos para ser nossa loja

    int escolha;
    //preciso fazer um CRUD para uma loja de animais de estimação
    // primeiro, vamos criar a classe loja, dentro dela, coloco as classes
    //de gato e cachorro, os objetos gato ou cachorro serão
    //acrescentados em um vetor que vai passar para um arquivo,
    //quando alguém comprar um pet, vamos apagar o objeto dele e atualizar o vetor no arquivo

    do {
    cout << "Bem vindo ao petshop!" << endl << "Escolha o que deseja fazer em sua loja" << endl;
    cout <<"1- Cadastrar pet" << endl <<"2- Veja os cachorros disponíveis" << endl;
    cout <<"3- Veja os gatos disponíveis" << endl <<"4- Apagar o ultimo cachorro da lista" << endl;
    cout <<"5- Apagar o ultimo Gato da lista" << endl << "6- Fim do programa" << endl;

    cin >> escolha;

    switch (escolha){
    case 1:
        minhaloja.cadastropet();
        break;
    case 2:
        minhaloja.verDogs();
        break;
    case 3:
        minhaloja.verCats();
        break;
    case 4:
        minhaloja.eraselastDog();
        break;
    case 5:
        minhaloja.eraselastCat();
        break;
    case 6:
        cout << "Adeus";
        return 0;
    }
    } while (escolha!=6);
}
