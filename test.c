#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int id_table[10000];
int id = 121000;
int conteur_id = 0;

int generer_id() {
    id++; 
    id_table[conteur_id]=id;
    conteur_id++; 
    return id;
    }

int main() {
    // Write C code here
    printf("%d",generer_id);

    return 0;
}