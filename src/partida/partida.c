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


char* nuevo_intento(char* palabra_secreta, char* intento){

    printf("estoy en un intento\n");

    char resultado[6] = {'X', 'X', 'X', 'X', 'X', '\0'};
    bool pista[5] = {false, false, false, false, false};

    for (int i = 0; i < 5; i++){

        if (intento[i] == palabra_secreta[i]){

            resultado[i] = 'H';
            pista[i] = true;

        } else {

            for (int j = 0; j < 5; j++){

                if (intento[i] == palabra_secreta[j] && !pista[j]){

                    resultado[i] = 'Y';
                    pista[j] = true;
                    break;

                } 

            }

        }

    }

    printf("resultado %s \n", resultado);

}

void comenzar_partida(Partida* partida){

    int run = 1;
    char intento[6];

    while(run) {

        printf("Inserte Palabra \n");
        scanf("%s", intento);

        printf("Ingresaste la palabra %s \n", intento);

        nuevo_intento(partida->palabra_secreta, intento);


        if (string_equals(partida->palabra_secreta, intento)){
            printf("ganaste\n");
            run = 0;
        } else{
            printf("sigue intentando\n");
        }
        //aqui deberia ir el testeo del intento

        partida->intentos++;

    }
    
}