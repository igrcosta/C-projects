#include <iostream>

using namespace std;

//faremos algo parecido com o exerc�cio 1, mas agora, o usu�rio define o momento
//que o loop da recursividade vai parar

int somando(int limite, int contador)
//mesmo que tenha criado a vari�vel l� no main, preciso especificar com int e td mais
//para que a fun��o fa�a meio que uma c�pia dela, a� assim, trabalho com as vari�veis que quero

{
if (contador <= limite){
    //utilizei <= para que chegue at� o n�mero do par�metro que desejarem

    std::cout << contador << ",";
    //mesmo esquema para impress�o std::cout << vari�vel << "texto";

    contador++;
    somando(limite, contador);
    //recursividade, entrego devolta pra fun��o os novos valores das vari�veis e continua
}
return 0;
//caso o IF n�o seja atendido, fim do c�digo
}

int main()
{
    int limite;
    //usaremos essa vari�vel para guardar o par�metro da recursividade

    //usu�rio informa at� quando a sequ�ncia vai
    std::cin >> limite;

    //o cin serve como nosso scanf, mas lembrando da l�gica das setas, aqui s�o >>

    somando(limite, 1);
    return 0;
}
