#include <iostream>

using namespace std;

int soma(int contador)
//aqui em cima, criei uma fun��o int, j� que vou precisar retornar valor
// essa fun��o int recebe um int que vai ser incrementado.
{
    if (contador<5){
    contador++;
    std::cout << contador << ",";
    //aqui, estadmos imprimindo o valor de contador e uma v�rgula depois,
    //uso as setinhas duplas para separar o que ser� impresso na linha

    soma(contador);
    //para ter recursividade, a fun��o precisa chamar ela mesma, logo,
    //nesta parte a soma � chamada denovo, com o novo valor do contador.
    }
    return 0;
    //quando o contador chegar em 5, precisa parar, ent�o, o IF l� em
    //cima trabalha com o else nesse return 0.
}

int main()
{
    cout << "Vamos criar uma sequence com recursividade!" << endl;
    // imprimindo um texto gen�rico, usando cout << "" <<
    //o endl serve para fazer quebra de linha depois

    soma(0);
    //aqui, estou chamando minha fun��o soma e entregando o valor 0
    // p/ ela
    return 0;
}
