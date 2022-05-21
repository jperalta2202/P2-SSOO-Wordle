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


struct Partida {

    char* palabra_secreta;

    int intentos;

};

Partida* nueva_partida(char* palabra_secreta);

void nuevo_intento(char* intento);

void comenzar_partida(Partida* partida);

bool string_equals(char *string1, char *string2);
