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
int id = 121000;
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
    id = id + 1; 
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

// la fonction qui verifier l'age
int age_valide(int age) {
    if (age >= 0 && age <= 120){
        return 1;}
    else{
        printf("%sce l\'age n\'est pas valide . %s\n",rouge,reset);
        return 0;} 
}

// la fonction qui verifier la date de reservation
int date_valide(int jour, int mois, int annee) {
    int jours[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (annee % 4 ==0) {
        jours[1]=29;}

    if (mois < 1 || mois > 12) {
        return 0;}

    if (jour < 1 || jour > jours[mois - 1]) {
        return 0;}

    return 1;}