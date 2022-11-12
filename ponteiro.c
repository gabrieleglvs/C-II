//Para que a var c, seja a mesma tanto no main quanto na funcao, o endereço de memória dela tem que aportar para o mesmo lugar, tanto na funcao, quanto no main.

#include <stdio.h>

//coloquei um asterisco para sinalizar que o que estou passando é o endereço de memória da var c que está no main.
void calcula(int* c) {

    //o asterisco antes do c, declara que eu quero entrar no endereço de memoria e pegar o valor que tem lá dentro, e depois soma +1.
    printf("calcula %d %d\n", (*c), c);
    (*c)++;
    printf("calcula %d %d\n", (*c), c);
}

int main() {
    int c = 10;

    printf("main %d %d\n", c, &c);
    calcula(&c);
    printf("main %d %d\n", c, &c);
}