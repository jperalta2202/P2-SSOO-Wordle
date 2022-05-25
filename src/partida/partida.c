#include "partida.h"


Partida* nueva_partida(char* palabra_secreta, char* user_name){

    Partida* new = malloc(sizeof(Partida));

    new -> intentos = 0;
    new -> palabra_secreta = palabra_secreta;
    new -> suma_incorrectas = 0;
    new -> user_name = user_name;

    return new;
  
}

Partida_terminada* partida_terminada_init(char* palabra_secreta, int puntaje, char* nombre){

    Partida_terminada* new = malloc(sizeof(Partida_terminada));

    new -> palabra_secreta = palabra_secreta;
    new -> puntaje = puntaje;
    new -> nombre = nombre;

    new -> prev = NULL;
    new -> next = NULL;

    return new;

}

Lista_partidas_terminadas* partidas_terminadas_init(){

    Lista_partidas_terminadas* lista = malloc(sizeof(Lista_partidas_terminadas));

    lista -> head = NULL;

    return lista;
};

void append_partida(Lista_partidas_terminadas* lista, Partida_terminada* partida)  
{

    if (lista->head == NULL){

        lista -> head = partida;
        return;

    }

    Partida_terminada* current = lista -> head;

    //comparando con el primero

    if(partida->puntaje > current->puntaje){

        lista -> head = partida;
        partida -> next = current;
        current -> prev = partida;

    } else {

        Partida_terminada* previus = current;
        current = current -> next;

        while(current) {

            if(partida -> puntaje > current -> puntaje) {

                previus -> next = partida;
                current -> prev = partida;
                partida -> next = current;
                partida -> prev = current -> prev;
                return;

            }

            previus = current;
            current = current -> next;

            printf("dentro del while\n");
        }

        printf("fuera del while");
        previus -> next = partida;
        partida -> prev = previus;

    }

}

void print_top_10(Lista_partidas_terminadas* lista){

    printf("LEADERBOARD\n");

    int posicion = 1;
    Partida_terminada* current = lista->head;
    while (current && posicion < 11){
  
        printf("%iº - %i - %s - %s \n", posicion, current->puntaje, current->nombre, current->palabra_secreta);

        posicion++;
        current = current->next;
    };    
    
};

void destroy_lista(Lista_partidas_terminadas* lista)
{
    Partida_terminada* current = lista->head;
    while(current){
        if(current->next){
            Partida_terminada* previous = current;
            current = previous->next;
            free(previous);

        } else {
            free(current);
            break;
        };
    }
    free(lista);
};


bool string_equals(char *string1, char *string2)
{
  return !strcmp(string1, string2);
}


void nuevo_intento(Partida* partida, char* palabra_secreta, char* intento){


    char resultado[6] = {'X', 'X', 'X', 'X', 'X', '\0'};
    bool pista[5] = {false, false, false, false, false};

    for (int i = 0; i < 5; i++){

        if (intento[i] == palabra_secreta[i]){

            resultado[i] = 'H';
            pista[i] = true;

        } else {

            for (int j = 0; j < 5; j++){

                if (intento[i] == palabra_secreta[j] && !pista[j]){

                    resultado[i] = '?';
                    pista[j] = true;
                    break;

                } 

            }

        }

        if (resultado[i] == 'X'){
            partida->suma_incorrectas += 1;
        }

    }

    printf("%s\n", resultado);

}

void comenzar_partida(Partida* partida, char** lista_validas){

    int run = 1;
    char intento[6];

    while(run) {

        printf("Inserte palabra \n");
        scanf("%s", intento);

        int valida = word_is_valid(intento, lista_validas);

        if(valida) {

            nuevo_intento(partida, partida->palabra_secreta, intento);

            if (string_equals(partida->palabra_secreta, intento)){

                printf("Ganaste\n");
                run = 0;

            } else {

                printf("Sigue intentando\n");

            }

            partida->intentos++;

        } else {

            printf("Ingresa una palabra valida\n");

        }

    }
    
}

int word_is_valid(char* string, char** lista_validas)
{
    int largo = 12972;

    for (int i = 0; i < largo; i++) {
        int comparacion = strcmp(string, lista_validas[i]);
        if (comparacion == 0){
            return 1;
        }
    }
    return 0;
};

int calcular_puntaje(Partida* partida){
    int tope = 10000;
    int n = partida -> intentos;
    int x_i = partida -> suma_incorrectas;

    int puntaje = ((tope)/(n*(1+x_i)));

    return puntaje;
};

void destroy_partida(Partida* partida){

    free(partida);

}