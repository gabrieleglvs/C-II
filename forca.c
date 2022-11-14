#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

//Variáveis globais
char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;

void abertura() {
    printf("*****************\n");
    printf("* Jogo de Forca *\n");
    printf("*****************\n\n");
}

void chuta() {
    char chute;
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
    chutesdados++;
}

int jachutou(char letra) {
    int achou = 0;

    for(int j=0; j<chutesdados; j++) {

        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaforca() {

    int erros = chuteserrados();

    printf("  _______      \n");
    printf(" |/      |     \n");
    //A cabeça vai aparecer se erros for maior que 1.
    printf(" |      %c%c%c \n", (erros >= 1 ? '(' : ' '), 
    (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    //esse é um if ternário, UAU COISA NOVA... A sintaxe de um if ternário é a seguinte: (condicao ? valor verdadeiro : valor falso). Repare no ponto-de-interrogação separando a condição do valor verdadeiro, e o dois-pontos separando o valor usado no caso que a condição é falsa.

    //O corpo vai aparecer se erros for maior do que 2
    //Os braços vão parecer se erros for maior que 3
    printf(" |      %c%c%c \n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
    printf(" |       %c    \n", (erros >= 2 ? '|' : ' '));

    //As pernas vão aparecer quando erros for maior do que 4
    printf(" |      %c %c  \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));

    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");

    for(int i=0; i<strlen(palavrasecreta); i++) {

        int achou = jachutou(palavrasecreta[i]);

        if (achou) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void adicionapalavra() {
    char quer;

    printf("Voce deseja adicionar uma nova palavra no jogo? (S/N)");
    scanf(" %c", &quer);

    if(quer == 'S') {

        char novapalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra? ");
        scanf("%s", novapalavra);

        FILE* f;

        //r+ quer dizer leitura e escrita
        f = fopen("palavras.txt", "r+");
        //se o arquivo nao abrir por qualquer motivo, eu posso tratar esse erro, já deixando um aviso para o usuario
        if(f == 0) {
            printf("Desculpe, banco de dados nao disponivel\n\n");
            exit(1);
        }

        //pegou o num que tinha no começo do arquivo e somou um para ele, e logo foi para a linha de baixo
        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        //essa funcao faz com que o ponteiro retorne para a linha zero, (ou seja, nesse caso a linha de cima) e só aí reescreva essa linha com a quantidade nova.
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        //posicionando o cursor na ultima linha
        fseek(f, 0, SEEK_END);
        //escreve a nova palavra no arquivo
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }
}

void escolhepalavra() {
    //a var f tem o tipo 'arquivo' e devolve para gente um ponteiro de um arquivo.
    FILE* f;

    //abri o arquivo
    f = fopen("palavras.txt", "r");
    
    //se o arquivo nao abrir por qualquer motivo, eu posso tratar esse erro, já deixando um aviso para o usuario
    if(f == 0) {
        printf("Desculpe, banco de dados nao disponivel\n\n");
        exit(1);
    }

    int qtddepalavras;
    //lendo um arquivo e guardando o num da primeira linha na var qtdpalavras
    fscanf(f, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand() % qtddepalavras;

    for(int i=0; i<=randomico; i++) {
        fscanf(f, "%s", palavrasecreta);
    }
    //fechando o arquivo
    fclose(f);
}

int acertou() {
    for(int i=0; i<strlen(palavrasecreta); i++) {
        if(!jachutou(palavrasecreta[i])) {
            return 0;
        }
    }
    return 1;
}

int chuteserrados() {
    int erros = 0;

    for(int i=0; i<chutesdados; i++) {
        int existe = 0;

        for(int j=0; j<strlen(palavrasecreta); j++) {
            if(chutes[i] == palavrasecreta[j]) {
                existe = 1;
                break;
            }
        }
        if(!existe) erros++;
    }
    return erros;
}

int enforcou() {

    return chuteserrados() >=5;
}

int main() {

    escolhepalavra();
    abertura();

    do {
        desenhaforca();
        chuta();

    } while (!acertou() && !enforcou());

    if(acertou()) {
        printf("\nParabéns, você ganhou!\n\n");
    } else {
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra secreta era **%s**\n\n", palavrasecreta);
    }
    adicionapalavra();
}