#include <iostream>

using namespace std;

int reverso(string palavra, int contador){
    if (contador > -1){
        //se no if, eu colocar at� 0, ele n�o imprime a �ltima letra

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
    //o usu�rio digita uma palavra
    std::cin >> palavra;

    contador = palavra.size() -1;
    //nessa linha, estou pegando o tamanho da string e atribuindo
    //ao int contador, mas se n�o uso -1, d� um espa�o � mais.

    reverso(palavra, contador);
    return 0;
}
