#include "flujo.h"

#define MAX_WORDS_NUM 200

int main() {

    char** wordsList = calloc(MAX_WORDS_NUM, sizeof(char*));
    int word_count = 0;
    char* fiveLetterWord = malloc(6*sizeof(char));
    FILE* wordsFile = fopen("palabras.txt", "r");
    while (fscanf(wordsFile, "%s", fiveLetterWord) != EOF && word_count < MAX_WORDS_NUM)
    {
        wordsList[word_count] = fiveLetterWord;
        printf("PALABRA DENTRO DEL WHILE: %s \n",fiveLetterWord);
        printf("PALABRA DENTRO DEL WHILE pero lista: %s \n",wordsList[word_count]);
        word_count++;
        char* fiveLetterWord = malloc(6*sizeof(char));
    };
    printf("\npalabra 190: %s \n\n", wordsList[189]);

    for (int i = 0; i < 200; i++){
        printf("Palabra %i : %s \n",i, wordsList[i]);
    };

    return 0;
};