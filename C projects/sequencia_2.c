#include <stdio.h>
#include <stdlib.h>

int main()
{
    //receber valor para quantas vezes vai se repetir a atribui��o
    int S;
    scanf("%d",&S);

    //vari�vel que vai receber as atribui��es, j� come�ando com 1
    float resultado=1;

    //definindo numeradores e denominadores
    float Num=1;
    float Den=1;

    //vari�vel para o while
    int x=1;

    //atribui��es em loop de S vezes
    while(x!=S){
        Num+=2;
        Den+=1;
        resultado+=Num/Den;
        x++;
    }
    //impress�o do valor final
    printf("%.2f",resultado);
    return 0;
}
