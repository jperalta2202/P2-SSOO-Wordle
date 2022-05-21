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

void comenzar_partida(Partida* partida, char** lista_validas){

    int run = 1;
    char intento[6];

    while(run) {

        printf("Inserte Palabra \n");
        scanf("%s", intento);

        printf("Ingresaste la palabra %s \n", intento);
        int valida = word_is_valid(intento, lista_validas);


        if (string_equals(partida->palabra_secreta, intento)){
            printf("ganaste\n");
        } else{
            printf("sigue intentando\n");
        }
        //aqui deberia ir el testeo del intento

        partida->intentos++;

    }
    
}

int word_is_valid(char* string, char** lista_validas)
{
    int largo = 12972;
    int word_is_in_list = 1; // 1 significa que no está, 0 que si
    for (int i = 0; i < largo; i++) {
        int comparacion = strcmp(string, lista_validas[i]);
        if (comparacion == 0){
            printf("\nPALABRA ES VALIDA\n\n");
            return 0;
        }
    }
    printf("\nPALABRA NO ES VALIDA\n\n");
    return 1;
};