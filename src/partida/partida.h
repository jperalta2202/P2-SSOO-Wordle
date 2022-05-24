#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>



struct Partida;
typedef struct Partida Partida;
struct Partida_terminada;
typedef struct Partida_terminada Partida_terminada;


struct Partida {
    char* palabra_secreta;
    int intentos;
    int suma_incorrectas;
};

struct Partida_terminada {

    char* palabra_secreta;
    int puntaje;
    char* nombre;
    struct Partida_terminada* prev;
    struct Partida_terminada* next; 

};

typedef struct lista_partidas_terminadas {
    struct Partida_terminada* head;
    struct Partida_terminada* tail;

} Lista_partidas_terminadas;

Partida* nueva_partida(char* palabra_secreta);

Lista_partidas_terminadas* partidas_terminadas_init();

Partida_terminada* partida_terminada_init(char* palabra_secreta, int puntaje, char*nombre);
void append_partida(Lista_partidas_terminadas* lista, Partida_terminada* partida);
void destroy_lista(Lista_partidas_terminadas* lista);

void print_top_10(Lista_partidas_terminadas* lista);

void nuevo_intento(char* intento);

void comenzar_partida(Partida* partida, char** lista_validas);

bool string_equals(char *string1, char *string2);

int word_is_valid(char* string, char** lista_validas);

int calcular_puntaje(Partida* partida);
