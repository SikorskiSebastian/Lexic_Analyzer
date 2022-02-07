#include <string.h>
#include "fun_main.h"
#include "parser.h"
#include "store.h"

void howmanyfun ( char **nazwy, int *ilenazw) {

    for (int i = 0; i < position_def; i++){
        if(is_sequence_present(nazwy, (*ilenazw), definitions[i].store) == 0){
            nazwy[*ilenazw] = definitions[i].store;
            (*ilenazw)++;
        }
    }
    for (int i = 0; i < position_proto; i++){
        if(is_sequence_present(nazwy, (*ilenazw), prototypes[i].store) == 0){
            nazwy[*ilenazw] = prototypes[i].store;
            (*ilenazw)++;
        }
    }
    for (int i = 0; i < position_call; i++){
        if(is_sequence_present(nazwy, (*ilenazw), calls[i].store) == 0){
            nazwy[*ilenazw] = calls[i].store;
            (*ilenazw)++;
        }
    }
}

int is_sequence_present(char** array, int ilenazw, char* string){
    for( int i = 0; i < ilenazw; i++ ){
        if(strcmp(array[i], string) == 0)
            return 1;
    }
    return 0;
}
