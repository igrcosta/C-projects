#include <stdio.h>

// Função para calcular o fatorial de um número
double fatorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    double f = 1;
    for (int i = 2; i <= n; i++) {
        f *= i;
    }
    return f;
}

// Função para calcular a soma S
double calcularS(int N) {
    double S = 0.0;
    for (int i = 0; i <= N; i++) {
        S += 1 / fatorial(i);
    }
    return S;
}

int main() {
    int N;
    //leitura do valor de N
    scanf("%d", &N);

    double resultado = calcularS(N);
    printf("%.2f\n", resultado);

    return 0;
}
