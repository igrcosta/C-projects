#include <iostream>

using namespace std;

int fibonacci(int n) {
if (n == 0){
    return 0;
} else if (n == 1) {
    return 1;
} else {
    return fibonacci(n-1) + fibonacci(n-2);
}


}

int main(){
    int n;

    cout << "Vamos descobrir o valor de uma sequencia de fibonacci!" << endl;
    cout << "digite o valor e vamos encontrar seu termo!" << endl;
    cin >> n;

    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;

    cout << "Obrigado!" << endl;
    return 0;
}