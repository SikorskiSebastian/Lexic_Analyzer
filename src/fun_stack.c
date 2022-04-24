#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun_stack.h"

struct funstack *tophead;

int top_of_funstack( void ){
    //potrzebne jest chyba sprawdzenie czy nie jest puste
    if (tophead == NULL)
        return 0;
    return tophead->par_level;
}

void put_on_fun_stack( int par_level, char *funame ){
    struct funstack *nw = NULL;
    nw = malloc(sizeof(struct funstack));
    nw->funname = (char*) malloc((1+strlen(funame)) * sizeof(nw->funname));
    strcpy(nw->funname,funame );
    nw->par_level = par_level;
    nw->before = tophead;
    tophead = nw;
}

char *get_from_fun_stack( void ){
    if (tophead == NULL)
        exit (1);               // to nie jest najlepsze, ale jest proste ;-)
    char *tmp;
    tmp = tophead->funname;
    tophead = tophead->before;
    return tmp;
}
