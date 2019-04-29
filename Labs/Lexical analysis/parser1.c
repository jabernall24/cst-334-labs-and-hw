#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

int lookahead;
void assign_stmt();

void match(int t) { 
    if (lookahead == t) {
	lookahead = lexan();
    } else {
        printf("syntax error");
	exit(1);
    }
} 

// main parsing function
void parse() {
   lookahead = lexan();
   assign_stmt();
}

// a simple assignment statement
// assign_stmt ::= ID '=' NUM
void assign_stmt() {
   if (lookahead == ID) {
      lookahead = lexan();
      if (lookahead == '=') {
         lookahead = lexan();
         if (lookahead == NUM) {
            return;
         }
      }
   }
   printf("syntax error\n"); 
   exit(1);
}

