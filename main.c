#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv){

    printf("Starting Program\n");

    int* temp;
    if(!(temp = malloc(sizeof(int)))) {
        printf("Malloc Failed\n");
    } else {
        printf("Malloc Success\n");
    }

    printf("Ending Program\n");

    return 0;
}