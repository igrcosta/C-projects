#include <iostream>

using namespace std;


int reverso(string& normal, string& oposta, int contador, int i){
    if(contador > 0){
            oposta[i] = normal[contador];
            contador--;
            i++;
            reverso(normal,oposta,contador,i);
    }
    return (normal, oposta, contador, i);
}

int main()
{
    string normal;
    string oposta;
    int contador;
    int i = 0;

    //o usuário fornece a string;
    std::cin >> normal;
    oposta = normal;

    //agora, temos duas cópias da string original, uma vai ser invertida

    contador = normal.size() -1;

    reverso(normal, oposta, contador, i);

    //comparação para ver se é palíndromo ou não
    if (normal == oposta){
        std::cout << "Palíndromo";
        return 0;
    } else if (normal != oposta){
    std::cout << "Não é palíndromo";
    }
    return 0;
}
