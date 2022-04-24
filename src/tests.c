#include "tests.h"
#include "fun_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testuj_top_of_funstack(){
    int i = 20;
    put_on_fun_stack(i, "Kasia");
    printf("Testuje funkcje top_of_funstack :\n");

    if(top_of_funstack() == i){
        printf("\t> Test funkcji top_of_funstack POMYŚLNY!\n");
    }else{
        printf("\t> Test funkcji top_of_funstack NIEPOMYŚLNY!\n");
    }
    get_from_fun_stack();
}
void testuj_put_on_fun_stack(){
    char *name = "Ala";
    put_on_fun_stack(20, name);
    printf("Testuje funkcje put_on_fun_stack :\n");

    if ((top_of_funstack() == 20) && (strcmp(get_from_fun_stack(),name) == 0)){
        printf("\t> Test funkcji put_on_fun_stack POMYŚLNY!\n");
    }
    else{
        printf("\t> Test funkcji put_on_fun_stack NIEPOMYŚLNY!\n");
    }
}
void testuj_get_from_fun_stack(){
    char *name = "Kamil";
    int par = 10;
    int isStillGood = 1;

    printf("Testuje funkcje get_from_fun_stack :\n");
    put_on_fun_stack(par,name);
    if (top_of_funstack()!=par)
        isStillGood--;
    if ((strcmp(get_from_fun_stack(),name) != 0))
        isStillGood--;
    put_on_fun_stack(par,name);
    name = "Ania";
    put_on_fun_stack(par,name);
    if ((strcmp(get_from_fun_stack(),name) != 0))
        isStillGood--;

    if(isStillGood == 1){
        printf("\t> Test funkcji get_from_fun_stack POMYŚLNY!\n\n");
    }else{
        printf("\t> Test funkcji get_from_fun_stack NIEPOMYŚLNY!\n");
    }
}
