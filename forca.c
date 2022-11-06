#include <stdio.h>
#include <string.h> // biblioteca para usar o strlen

int main() {
    char palavrasecreta[20];

    sprintf(palavrasecreta, "MELANCIA");

    int acertou = 0;
    int enforcou = 0;

    do {

        for(int i=0; i<strlen(palavrasecreta); i++) {
            printf("_ ");
        }
        printf("\n");

        char chute;
        scanf(" %c", & chute); //dei espaço para ele não salvar o enter no buffer e bugar o nosso jogo.

    } while (!acertou && !enforcou);
}
