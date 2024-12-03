#include <iostream>

using namespace std;

void divisoes (const int& N, int& numero){
    if (N >= numero) {
        if (N % numero == 0){
            cout << numero << " ";
            }
            numero++;
            divisoes(N, numero);
            }
}

int main()
{
    int N;
    int numero = 1;

    //usuário fornece o número N pra ver seus divisores
    cin >> N;

    cout << "Divisores de " << N << " são:" << endl;
    divisoes(N, numero);
    return 0;
}
