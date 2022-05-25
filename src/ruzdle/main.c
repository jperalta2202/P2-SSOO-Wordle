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


    // INICIAMOS EL LEADERBOARD

    Lista_partidas_terminadas* lista = partidas_terminadas_init();



    // CICLO DE UNA PARTIDA

    Partida* partida = nueva_partida(wordsList[18], "chino"); //creo la partida

    comenzar_partida(partida, wordsListValids); // comienzo la partida, aqui va todo el flujo

    int puntaje = calcular_puntaje(partida); //al terminar la partida, quedo toda la info guardada asi que la uso para calcular puntaje

    Partida_terminada* primera = partida_terminada_init(partida->palabra_secreta, puntaje, partida->user_name); //creamos partida terminada
    append_partida(lista, primera); // lo appendiamos a la lista


    ///////////////////////// BLOQUE DE PRUEBA TOP 10

    // Partida_terminada* segunda = partida_terminada_init("mario", 3000, "George");
    // append_partida(lista, segunda);

    // Partida_terminada* tercera = partida_terminada_init("munoz", 5000, "juan");
    // append_partida(lista, tercera);

    // Partida_terminada* cuarta = partida_terminada_init("smile", 3000, "miguel");
    // append_partida(lista, cuarta);

    // Partida_terminada* quinta = partida_terminada_init("slurm", 4000, "jose");
    // append_partida(lista, quinta);

    // Partida_terminada* sexta = partida_terminada_init("aloha", 1700, "vale");
    // append_partida(lista, sexta);

    // Partida_terminada* septima = partida_terminada_init("chick", 1000, "alonso");
    // append_partida(lista, septima);

    // Partida_terminada* octaba = partida_terminada_init("holaa", 2, "carlos");
    // append_partida(lista, octaba);

    // Partida_terminada* novena = partida_terminada_init("asdas", 40001, "marcos");
    // append_partida(lista, novena);

    // Partida_terminada* decima = partida_terminada_init("rrrrr", 10000, "pato");
    // append_partida(lista, decima);

    // Partida_terminada* onceaba = partida_terminada_init("rrrrr", 100, "pato");
    // append_partida(lista, onceaba);


    ///////////////////////// BLOQUE DE PRUEBA TOP 10

    print_top_10(lista);


    // FREE DE TODO 

    destroy_lista(lista); 

    destroy_partida(partida);

    free(fiveLetterWord);
    free(fiveLetterWordValid);


    fclose(wordsFile);
    fclose(wordsFileValid);

    for (int i = 0; i < MAX_WORDS_NUM; i++){
        free(wordsList[i]);
    };

    free(wordsList);

    for (int r = 0; r < MAX_WORDS_NUM_VALIDS; r++){
        free(wordsListValids[r]);
    };

    free(wordsListValids);


  return 0;
}
