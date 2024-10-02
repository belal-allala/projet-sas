#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct reservation {
    char id[8];
    char nom[20];
    char prenom[20];
    char telephone[20];
    int age;
    int statut;
    };

struct reservation reservations[1000];
int nb_reservation = 0;
char id_table[10000][8];
int conteur_id = 0;
int i,d,choix,revenu,verifi;

const char *reset = "\033[0m";
const char *vert = "\033[32m";
const char *rouge = "\033[31m";
const char *jaune = "\033[33m";

// la fonction qui generer des id
char *generer_id() {
    char *idi = malloc(8);
    int i;
    authre:
    srand(time(NULL));
    int num = rand() % 900000 + 100000; 
    sprintf(idi, "YC%06d", num);
    for (i = 0; i <= conteur_id;i++){
        if (!strcmp(id_table[conteur_id], idi)){
            free(idi);
            goto authre;}}
    strcpy(id_table[conteur_id],idi);
    conteur_id++; 
    return idi;
    }

// la fonction qui verifier le nom 
int nom_verifier(char *nom){
    if (strlen(nom) >= 20) {
        printf("%sLe nom est trop long.%s\n",rouge,reset);
        return 0;}

    for (int i = 0; nom[i] != '\0'; i++) {
        if (!isalpha(nom[i]) && nom[i] != ' ') {
            printf("%sle nom ne doit contenir que des lettres et des espaces.%s\n",rouge,reset);
            return 0;}
    }
return 1;}

// la fonction qui verifier le numero de telephone
int numero_valide(const char *numero) {
    int longueur = strlen(numero);
    if (longueur != 10) {
        return 0;}

    if (numero[0] != '0' || (numero[1] != '6' && numero[1] != '7')) {
        return 0;}

    for (int i = 0; i < longueur; i++) {
        if (numero[i] < '0' || numero[i] > '9') {
            return 0;}}

    for (int i = 0; i < nb_contacts; i++) {
        if (strcmp(contacts[i].numero, numero) == 0 ) {
            printf("%sle numero existe deja :%s\n",rouge,reset);
            return 0;} }
    return 1;}
