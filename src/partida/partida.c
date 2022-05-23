#include "partida.h"


Partida* nueva_partida(char* palabra_secreta){

    Partida* new = malloc(sizeof(Partida));

    new -> intentos = 0;
    new -> palabra_secreta = palabra_secreta;
    new -> suma_incorrectas = 0;

    return new;
  
}

Partida_terminada* partida_terminada_init(char* palabra_secreta, int puntaje, char* nombre){

    Partida_terminada* new = malloc(sizeof(Partida_terminada));

    new -> palabra_secreta = palabra_secreta;
    new -> puntaje = puntaje;
    new -> nombre = nombre;

    return new;

}

Lista_partidas_terminadas* partidas_terminadas_init(){
    Lista_partidas_terminadas* lista = malloc(sizeof(Lista_partidas_terminadas));

    lista -> head = NULL;
    lista -> tail = NULL;

    return lista;
};

void append_partida(Lista_partidas_terminadas* lista, Partida_terminada* partida)  
{
    Partida_terminada* current = lista -> head;
    if(!(current))
    {

        lista -> head = partida;
        lista -> tail = partida;
        return;
    } else {
        while(current){
            if (current->puntaje > partida->puntaje){
                // caso en que no es mejor que el mejor
                if (current == lista -> tail){
                    lista -> tail = partida;
                    partida -> prev = current;
                    current -> next = partida;
                    return;
                };
                current = current->next;

            } else if (current == lista->tail){
                if (current->puntaje >= partida->puntaje){
                    current->next = partida;
                    partida->prev = current;
                    lista->tail = partida;
                } else if(current->puntaje < partida->puntaje){
                    if (current->prev){
                        partida->prev = current->prev;
                        current->prev->next = partida;
                        current->prev = partida;
                    } else {
                        lista->head = partida;
                        current->prev = partida;
                        partida->next = current;
                    };
                }
                return;

            } else if (current->puntaje <= partida->puntaje){
                if(current == lista->head){
                    lista->head = partida;
                    partida->next = current;
                    current->prev = partida;
                } else {
                    current->prev->next = partida;
                    current->prev = partida;
                    partida->prev = current->prev;
                    partida->next = current;
                };

                return;
            };
        };
    };
    return;
};

void print_top_10(Lista_partidas_terminadas* lista){
    printf("Imprimimos el top 10\n");
    // primero seteamos los 10 primeros elementos de la lista como los top 10
    // por mientras es top 3 pero despues se puede escalar
    int posicion = 1;
    Partida_terminada* current = lista->head;
    while (current){
        if (posicion == 8){
            break;
        };
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
            printf("Liberando a: %s \n",previous->nombre);
            free(previous);

        } else {
            printf("Liberando a: %s \n",current->nombre);
            free(current);
            break;
        };
    }
    free(lista);
    printf("LISTA LIBERADA CORRECTAMENTE\n");
};

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

        // int puntaje = calcular_puntaje(partida);
        // printf("Puntaje deberia ser 277, es: %i \n", puntaje);


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

int calcular_puntaje(Partida* partida){
    int tope = 10000;
    int n = partida -> intentos;
    int x_i = partida -> suma_incorrectas;

    int puntaje = ((tope)/(n*(1+x_i)));

    return puntaje;
};