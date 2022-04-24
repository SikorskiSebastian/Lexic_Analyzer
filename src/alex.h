#ifndef _ALEX_H_IS_INCLUDED_
#define _ALEX_H_IS_INCLUDED_

#include <stdio.h>

// interesujące leksemy: błąd, inny symbol, koniec pliku, otwierająca klamra {, 
//                       zamykająca klamra }, identyfikator, otwierający nawias, 
//                       zamykający nawias
typedef enum { ERROR, OTHER, EOFILE, OPEBRA, CLOBRA, IDENT, OPEPAR, CLOPAR } lexem_t;

// zacznij czytać nowy plik
void alex_init4file( FILE * );
// daj kolejny leksem w czytanym pliku
lexem_t alex_nextLexem( void );    
// daj ostatni identyfikator
char * alex_ident( void );        
// daj aktualny nr linii
int alex_getLN();              

// sprawdz co jest w komentarzu typu /* */
void in_comment_1();
 // sprawdz co jest w komentarzu typu //
void in_comment_2();
// pomijanie komentarza
void skip_comment();

// funkcja pomija liczby całkowite i zmiennoprzecinkowe
int skip_number();

// funkcja dla cudzyslowia
void case_quote(int c);

//funkcja z isalpha
void case_alpha(int c);

//sprawdza czy w tablicy mamy keyworda i zwraca TRUE lub FALSE
int isKeyword(char* ident);

#endif
