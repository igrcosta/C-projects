#include <iostream>

using namespace std;

int reverso(string palavra, int contador){
    if (contador > -1){
        //se no if, eu colocar até 0, ele não imprime a última letra

        std::cout << palavra[contador];
        contador--;
        reverso(palavra, contador);
    }
    return 0;
}

int main()
{
    string palavra;
    int contador;
    //o usuário digita uma palavra
    std::cin >> palavra;

    contador = palavra.size() -1;
    //nessa linha, estou pegando o tamanho da string e atribuindo
    //ao int contador, mas se não uso -1, dá um espaço à mais.

    reverso(palavra, contador);
    return 0;
}
