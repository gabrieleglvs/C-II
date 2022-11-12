//Para que a var c, seja a mesma tanto no main quanto na funcao, o endereço de memória dela tem que aportar para o mesmo lugar, tanto na funcao, quanto no main.

//Para verificar o endereço de memórial de cada variável eu uso o & antes da variavel.

#include <stdio.h>

void calcula(int c) {
    //imprimindo o endereço de memória das vars
    printf("calcula %d %d\n", c, &c);
    c++;
    printf("calcula %d %d\n", c, &c);
}

int main() {
    int c = 10;

    //imprimindo o endereço de memória das vars
    printf("main %d %d\n", c, &c);
    calcula(c);
    printf("main %d %d\n", c, &c);
}