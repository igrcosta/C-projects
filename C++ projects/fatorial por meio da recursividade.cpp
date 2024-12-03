#include <iostream>

using namespace std;

void fatorial (int N, int contador, int& resultado) {
    if (contador <= N){
        resultado*= contador;
        fatorial (N, contador+1, resultado);
    }
}

int main()
{
    int N;
    int contador = 1;

    //usu�rio insere o n�mero que deseja ver seu fatorial
    std::cin >> N;

    int resultado = 1;

    fatorial(N, contador, resultado);
    cout << "O fatorial do seu num �: " << resultado <<endl;

    return 0;
}
