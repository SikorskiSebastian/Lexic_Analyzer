#include "alex.h"

#include <ctype.h>
#include <string.h>
#include <stdio.h>

#define MAXIDENT 256
#define KEYWORDSIZE 32

static int ln = 0;
static char ident[MAXIDENT];
static FILE *ci = NULL;

void alex_init4file(FILE *in) {
  ln = 0;
  ci = in;
}

char *alex_ident(void) {
  return ident;
}

int alex_getLN(void) {
  return ln;
}

int isKeyword(char *ident) {
  char* keyword[32] = {
      "auto","double","int","struct","break","else","long",
      "switch","case","enum","register","typedef","char",
      "extern","return","union","const","float","short",
      "unsigned","continue","for","signed","void","default",
      "goto","sizeof","voltile","do","if","static","while"
  };
  
  for(int i = 0; i < KEYWORDSIZE; i++) {
    if (strcmp(ident, keyword[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

int skip_number(void) {
  int d;

  while ((isdigit( d = fgetc(ci) ) || d == '.')) {
    ;
  }
  return d;
}

void case_quote(int c) {
  while ((c = fgetc(ci)) != EOF && c != '"') {
    if (c == '\\') {
      c = fgetc(ci);
      continue;
    }
  }
}

void case_alpha(int c) {
  int i = 1;
  ident[0] = c;

  while (isalnum(c = fgetc(ci))) {
    ident[i++] = c;
  }
  ident[i] = '\0';
  fseek(ci, -1L, SEEK_CUR);

}

void in_comment_1(void) { 
  int c, d;

  c = fgetc(ci);
  d = fgetc(ci);

  while (c != '*' || d != '/')  {
    c = d;
    d = fgetc(ci);
  }
}
void in_comment_2(void) { 
  int c;

  while ((c = fgetc(ci)) != '\n')  {
    ;
  }
}

void skip_comment (void) {
  int d;

  if ((d = fgetc(ci)) == '*') {
    in_comment_1();
  }

  else if (d == '/')  {
    in_comment_2();
  }
}

lexem_t alex_nextLexem(void) {
  int c;

  while ((c = fgetc(ci)) != EOF) {
    if (c == '\n') {
      ln++;
    }

    else if (isspace(c)) {
      continue;
    }

    else if (c == '(') {
      return OPEPAR;
    }

    else if (c == ')') {
      return CLOPAR;
    }

    else if (c == '{') {
      return OPEBRA;
    }

    else if (c == '}') {
      return CLOBRA;
    }

    else if (isalpha(c)) {
      case_alpha(c);
      return isKeyword(ident) ? OTHER : IDENT;
    }

    else if (c == '"') { 
      case_quote(c);
      return c == EOF ? EOFILE : OTHER;
    }

    else if (c == '/') { 
      skip_comment();
      return c == EOF ? EOFILE : OTHER;
    }

    if (isdigit(c) || c == '.') {
      c = skip_number();
      return c == EOF ? EOFILE : OTHER;
    }

    else {
      return OTHER;
    }
  }

  return EOFILE;
}