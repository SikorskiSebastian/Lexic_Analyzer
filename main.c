#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun_main.h"
#include "parser.h"
#include "store.h"

#define MAXNAZW 100

int main(int argc, char **argv) {
    char *nazwy[MAXNAZW];
    int ilenazw = 0;

    if (argc == 1) {
        fprintf(stderr, "Blad: Nie podano pliku do przeszukania\n");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {

        FILE *in = fopen (argv[i], "r");

        if (in == NULL) {
            fprintf(stderr, "Blad: Taki plik nie istnieje.\n");
            continue;
        }
        else {
            printf("\nCzytam plik : %s\n", argv[i]);
            analizatorSkladni(argv[i]);
        }       
    }
    howmanyfun(nazwy,&ilenazw);

    for (int j = 0; j < ilenazw; j++){
        printf("Funkcja %s\n", nazwy[j]);
        printf("\tDefinicje funkcji: \n" );
        int czyznalazlo = 0;
        for (int k = 0; k < position_def; k++){
            if (strcmp(nazwy[j],definitions[k].store) == 0){
                printf("\t\t plik: <%s> linia %d\n", definitions[k].file_name, definitions[k].number_line+1);
                czyznalazlo++;
            }

        }

        if (czyznalazlo == 0){
            printf("\t\t brak\n");
        }
        //proto
        printf("\tPrototypy funkcji: \n" );
        czyznalazlo = 0;
        for (int k = 0; k < position_proto; k++){
            if (strcmp(nazwy[j],prototypes[k].store) == 0){
                printf("\t\t plik: <%s> linia %d\n", prototypes[k].file_name, prototypes[k].number_line+1);
                czyznalazlo++;
            }

        }

        if (czyznalazlo == 0){
            printf("\t\t brak\n");
        }
        //calls
        printf("\tUżycie funkcji: \n" );
        czyznalazlo = 0;
        for (int k = 0; k < position_call; k++){
            if (strcmp(nazwy[j],calls[k].store) == 0){
                printf("\t\t plik: <%s> linia %d\n", calls[k].file_name, calls[k].number_line+1);
                czyznalazlo++;
            }

        }

        if (czyznalazlo == 0){
            printf("\t\t brak\n");
        }
    }

    return EXIT_SUCCESS;
}
