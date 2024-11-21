#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[20];
    int Ninvers[20];
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &vetor[0], &vetor[1], &vetor[2], &vetor[3], &vetor[4], &vetor[5],&vetor[6], &vetor[7], &vetor[8], &vetor[9], &vetor[10],&vetor[11], &vetor[12], &vetor[13], &vetor[14], &vetor[15],&vetor[16], &vetor[17], &vetor[18], &vetor[19]);
    //guardado cada valor em sua respectiva posição

    //agora, vamos fazer com que ele pegue o ultimo num daquele vetor,
    //subtraia com o valor da posição atual (0, 1 ,2 ...),
    //e jogue naquela posição que subtraimos
    //ou seja, posição 1 recebe valor mais alto menos 1 e por aí vai

    for(int i=0; i<20; i++){
            int temp;
        temp = Ninvers[i];
        Ninvers[i]=vetor[19-i];
        vetor[19-i]=temp;
        printf("N[%d] = %d\n", i, Ninvers[i]);
    }
    return 0;
}
