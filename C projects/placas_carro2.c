#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//vou utilizar isalpha e isdigit aqui

int main()
{
    char entrada[10];
    int M = 0;
    int N = 0;
    int u = 4;
    //declara��o vari�veis que vou usar

    fgets(entrada,10,stdin);
    entrada[strcspn(entrada, "\n")] = '\0';
    //tirando /n do fgets
    fflush(stdin);
    //recebendo string de entrada da placa

    // Verificar o comprimento da string
    int len = strlen(entrada);
    if (len == 8) {
        // Verificar padr�o antigo (AAA-0000)
        if (isalpha(entrada[0]) && isalpha(entrada[1]) && isalpha(entrada[2]) &&
            entrada[3] == '-' &&
            isdigit(entrada[4]) && isdigit(entrada[5]) && isdigit(entrada[6]) && isdigit(entrada[7])) {
            printf("1\n");
            return 0;
        }
    } else if (len == 7) {

        // Verificar padr�o novo (AAA0A00)
        if (isalpha(entrada[0]) && isalpha(entrada[1]) && isalpha(entrada[2]) &&
            isdigit(entrada[3]) &&
            isalpha(entrada[4]) &&
            isdigit(entrada[5]) && isdigit(entrada[6])) {
            printf("2\n");
            return 0;
        }
    }

    // Se n for nenhum dos padr�es v�lidos
    printf("0\n");
    return 0;
}

