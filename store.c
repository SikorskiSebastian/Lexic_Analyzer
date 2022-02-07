#include <stdio.h>
#include <stdlib.h>
#include "store.h"

#define MAXLINE 1000

storages_t definitions[MAXLINE];
storages_t prototypes[MAXLINE];
storages_t calls[MAXLINE];

int position_def = 0;
int position_proto = 0;
int position_call = 0;

void store_add_def(char *store, int ln, char* inpname) {

    definitions[position_def].number_line = ln; // w ktorej linijce to wystapilo

    definitions[position_def].file_name = inpname; // przypisanie nazwy pliku w ktorym to wyspilo

    definitions[position_def].store = store;

    position_def++;
}

void store_add_proto(char *store, int ln, char* inpname) {
    prototypes[position_proto].number_line = ln;

    prototypes[position_proto].file_name = inpname;

    prototypes[position_proto].store = store;

    position_proto++;
}

void store_add_call(char *store, int ln, char* inpname) {
    calls[position_call].number_line = ln;

    calls[position_call].file_name = inpname;

    calls[position_call].store = store;

    position_call++;
}
