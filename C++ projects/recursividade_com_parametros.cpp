#include <iostream>

using namespace std;

//faremos algo parecido com o exercício 1, mas agora, o usuário define o momento
//que o loop da recursividade vai parar

int somando(int limite, int contador)
//mesmo que tenha criado a variável lá no main, preciso especificar com int e td mais
//para que a função faça meio que uma cópia dela, aí assim, trabalho com as variáveis que quero

{
if (contador <= limite){
    //utilizei <= para que chegue até o número do parâmetro que desejarem

    std::cout << contador << ",";
    //mesmo esquema para impressão std::cout << variável << "texto";

    contador++;
    somando(limite, contador);
    //recursividade, entrego devolta pra função os novos valores das variáveis e continua
}
return 0;
//caso o IF não seja atendido, fim do código
}

int main()
{
    int limite;
    //usaremos essa variável para guardar o parâmetro da recursividade

    //usuário informa até quando a sequência vai
    std::cin >> limite;

    //o cin serve como nosso scanf, mas lembrando da lógica das setas, aqui são >>

    somando(limite, 1);
    return 0;
}
