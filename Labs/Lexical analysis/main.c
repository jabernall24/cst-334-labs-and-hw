#include <stdlib.h>
#include <stdio.h>
#include "parser.h"
#include "lexer.h"

void main(int argc, char *argv[]) {

   // parse program
   lexer_init();
   parse();
   printf("parsed\n");

   exit(EXIT_SUCCESS);
}
