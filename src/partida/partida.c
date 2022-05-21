#include "partida.h"


Partida* nueva_partida(char* palabra_secreta){

    Partida* new = malloc(sizeof(Partida));

    new -> intentos = 0;
    new -> palabra_secreta = palabra_secreta;

    return new;
  
}

bool string_equals(char *string1, char *string2)
{
  return !strcmp(string1, string2);
}


void nuevo_intento(char* intento){

}

void comenzar_partida(Partida* partida){

    int run = 1;
    char* intento;

    while(run) {

        printf("Inserte Palabra \n");
        scanf("%s", intento);

        printf("Ingresaste la palabra %s \n", intento);


        if (string_equals(partida->palabra_secreta, intento)){
            printf("ganaste\n");
        } else{
            printf("sigue intentando\n");
        }
        //aqui deberia ir el testeo del intento

        partida->intentos++;

    }
    
}