#include <iostream>
#include <vector> //vamos trabalhar com vetores aqui
#include <algorithm> //usares uma função dela para ver o que tem comum

using namespace std;

void divisoesN(const int& N, int numero, vector<int>& divisoresN) {
    if (numero <= N) {
        if (N % numero == 0) {
            divisoresN.push_back(numero);
        }
        divisoesN(N, numero + 1, divisoresN);
    }
}

void divisoesM(const int& M, int numero, vector<int>& divisoresM) {
    if (numero <= M) {
        if (M % numero == 0) {
            divisoresM.push_back(numero);
        }
        divisoesM(M, numero + 1, divisoresM);
    }
}

int main()
{
    int N, M;
    int numero = 1;

    int i = 0;
    int u = 0;

    vector<int> divisoresN;
    vector<int> divisoresM;

    //usuário fornece o número N pra ver seus divisores
    cin >> N;
    //usuário fornece o número M para ver seus divisores
    cin >> M;

    divisoesN(N, 1, divisoresN);
    divisoesM(M, 1, divisoresM);

    cout << "os divisores em comum são" << endl;
    for (int y = 0; y < divisoresM.size(); y++) {
        if (find(divisoresN.begin(), divisoresN.end(), divisoresM[y]) != divisoresN.end()) {
            cout << divisoresM[y] << endl;
        }
    }
    return 0;
}
