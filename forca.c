#include <stdio.h>
#include <string.h> // biblioteca para usar o strlen

int main() {
    char palavrasecreta[20];

    sprintf(palavrasecreta, "MELANCIA");

    int acertou = 0;
    int enforcou = 1;

    do {
        char chute;
        scanf("%c", & chute);

        //o strlen lê cada posição do array
        for(int i=0; i<strlen(palavrasecreta); i++) {
            if(palavrasecreta[i] == chute) {
                printf("A posição %d tem essa letra\n", i);
            }
        }
    } while (!acertou && !enforcou); 
}
