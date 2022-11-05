#include <stdio.h>

int main() {
    char palavrasecreta[20];

    sprintf(palavrasecreta, "MELANCIA");
    /*1º parâmetro: variável ou array
    2º parâmetro: palavra ou frase
    Essa função irá guardar o que vc escreveu na var ou array...
    - ela encherga o array de char como uma string, então só vai para de exibir o que está lá dentro, quando encontrar um final, que logicamente é 'vazio \0', então se tenho uma frase no array e quero exibir apenas uma palavra da frase, eu coloco o \0 no indice logo após o termino da palavra*/

    printf("%s", palavrasecreta);
}
