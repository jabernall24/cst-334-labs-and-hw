#include "lexer.h"
#include "error.h"
#include "regex.h"
#include "charx.h"

void match();
REGEX *regex();

int lookahead;    // most recent token

void match(int t) { 
    if (lookahead == t)
	lookahead = lexan();
    else error("syntax error");
} 

// parses a regular expression
REGEX *parse() {
   lookahead = lexan();
   REGEX *regx = regex();
   return regx;
}

// return a regular expression
REGEX *regex() {

   // your code here; replace the code below

   CHARX *a = charx_create('a', NO_MOD);
   CHARX *b = charx_create('b', NO_MOD);
   REGEX *regx = regex_create(a, regex_create(b, NULL, 0), 0);

   return regx; 
}


