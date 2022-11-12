//aprendendo sobre ponteiros

#include <stdio.h>

void calcula(int c) {
    printf("calcula %d\n", c);
    c++;
    printf("calcula %d\n", c);
}

int main() {
    int c = 10;

    printf("main %d\n", c);
    calcula(c);
    printf("main %d\n", c);
}

//impressão:
//main 10
//calcula 10
//calcula 11
//main 10