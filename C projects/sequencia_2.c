#include <stdio.h>
#include <stdlib.h>

int main()
{
    //receber valor para quantas vezes vai se repetir a atribuição
    int S;
    scanf("%d",&S);

    //variável que vai receber as atribuições, já começando com 1
    float resultado=1;

    //definindo numeradores e denominadores
    float Num=1;
    float Den=1;

    //variável para o while
    int x=1;

    //atribuições em loop de S vezes
    while(x!=S){
        Num+=2;
        Den+=1;
        resultado+=Num/Den;
        x++;
    }
    //impressão do valor final
    printf("%.2f",resultado);
    return 0;
}
