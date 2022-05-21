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



    Partida* partida = nueva_partida(wordsList[10]);

    comenzar_partida(partida, wordsListValids);

    fclose(wordsFile);
    for (int i = 0; i < 200; i++){
        free(wordsList[i]);
    };


  return 0;
}
