#ifndef _STORE_H_
#define _STORE_H_


extern int position_def;
extern int position_proto;
extern int position_call;

typedef struct storage {
    char *store; // nazwa funkcji (string)
    int number_line; // linijka w której to wystąpiło
    char *file_name; // nazwa pliku
} storages_t;

extern storages_t definitions[];
extern storages_t prototypes[];
extern storages_t calls[];

void store_add_def(char *store, int ln, char* inpname);

void store_add_proto(char *store, int ln, char* inpname);

void store_add_call(char *store, int ln, char* inpname);

#endif
