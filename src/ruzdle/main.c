#include <stdio.h>	// FILE, fopen, fclose, etc.
#include <stdlib.h> // malloc, calloc, free, etc
#include <string.h>
#include <time.h>
#include <stdbool.h>


#include "../partida/partida.h"

#define MAX_WORDS_NUM 200


int main (int argc, char *argv[]){
  

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

    for (int i = 0; i < 200; i++){
        printf("Palabra %i : %s \n",i, wordsList[i]);
    };


    Partida* partida = nueva_partida(wordsList[10]);

    comenzar_partida(partida);

    fclose(wordsFile);
    for (int i = 0; i < 200; i++){
        free(wordsList[i]);
    };


  return 0;
}
