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

    //o usu�rio fornece a string;
    std::cin >> normal;
    oposta = normal;

    //agora, temos duas c�pias da string original, uma vai ser invertida

    contador = normal.size() -1;

    reverso(normal, oposta, contador, i);

    //compara��o para ver se � pal�ndromo ou n�o
    if (normal == oposta){
        std::cout << "Pal�ndromo";
        return 0;
    } else if (normal != oposta){
    std::cout << "N�o � pal�ndromo";
    }
    return 0;
}
