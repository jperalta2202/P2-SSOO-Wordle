#include <stdio.h>	// FILE, fopen, fclose, etc.
#include <stdlib.h> // malloc, calloc, free, etc
#include <string.h>
#include <time.h>
#include <stdbool.h>


#include "../partida/partida.h"

#define MAX_WORDS_NUM 200
#define MAX_WORDS_NUM_VALIDS 12972


int main (int argc, char *argv[]){
  
    // CARGAR LISTA ARCHIVO PALABRAS
    char** wordsList = calloc(MAX_WORDS_NUM, sizeof(char*));
    int word_count = 0;
    char* fiveLetterWord = malloc(6*sizeof(char));

    FILE* wordsFile = fopen("palabras.txt", "r");

    while (fscanf(wordsFile, "%s", fiveLetterWord) != EOF && word_count < MAX_WORDS_NUM)
    {
        wordsList[word_count] = fiveLetterWord;
        word_count++;
        fiveLetterWord = malloc(6*sizeof(char));
    };
    //

    Partida* partida = nueva_partida(wordsList[10]);
    // CARGAR LISTA ARCHIVO PALABRAS_VALIDAS
    char** wordsListValids = calloc(MAX_WORDS_NUM_VALIDS, sizeof(char*));
    int word_count_valid = 0;
    char* fiveLetterWordValid = malloc(6*sizeof(char));

    FILE* wordsFileValid = fopen("palabras_validas.txt", "r");

    while (fscanf(wordsFileValid, "%s", fiveLetterWordValid) != EOF && word_count_valid < MAX_WORDS_NUM_VALIDS)
    {
        wordsListValids[word_count_valid] = fiveLetterWordValid;
        word_count_valid++;
        fiveLetterWordValid = malloc(6*sizeof(char));
    };
    //



    // Partida* partida = nueva_partida(wordsList[10]);

    // comenzar_partida(partida, wordsListValids);

    ///////////////////////// BLOQUE DE PRUEBA TOP 10
    Lista_partidas_terminadas* lista = partidas_terminadas_init();

    Partida_terminada* primera = partida_terminada_init("hello", 277, "Steve");

    append_partida(lista, primera);

    Partida_terminada* segunda = partida_terminada_init("mario", 3000, "George");

    append_partida(lista, segunda);

    Partida_terminada* tercera = partida_terminada_init("munoz", 3, "juan");
    append_partida(lista, tercera);

    Partida_terminada* cuarta = partida_terminada_init("smile", 5000, "miguel");
    append_partida(lista, cuarta);

    Partida_terminada* quinta = partida_terminada_init("slurm", 1700, "jose");
    append_partida(lista, quinta);

    Partida_terminada* sexta = partida_terminada_init("aloha", 1500, "vale");
    append_partida(lista, sexta);

    Partida_terminada* septima = partida_terminada_init("chick", 1000, "alonso");
    append_partida(lista, septima);


    printf(" \nllamo a print lista\n");
    print_top_10(lista);
    printf(" \n\n");
    destroy_lista(lista);


    ///////////////////////// BLOQUE DE PRUEBA TOP 10

    fclose(wordsFile);
    fclose(wordsFileValid);
    for (int i = 0; i < 200; i++){
        free(wordsList[i]);
    };
    for (int i = 0; i < MAX_WORDS_NUM_VALIDS; i++){
        free(wordsListValids[i]);
    };


  return 0;
}
