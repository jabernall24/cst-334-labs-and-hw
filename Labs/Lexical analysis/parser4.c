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
// assign_stmt ::= ID '=' NUM + NUM
void assign_stmt() {
    char *id = lexer_id_val();
    match(ID);
    match('=');
    int i = lexer_num_val();
    match(NUM);
    match('+');
    int j = lexer_num_val();
    match(NUM);
    printf("%s = %d + %d\n", id, i, j);

}

