#include <stdio.h>
#include <ctype.h>
#include "error.h"
#include "lexer.h"

#define BUFSIZE 256
#define EOS    '\0'   

int  lineno = 1;
int  tokenval = NONE;

// lexical analyzer
// - tokens have an integer type plus a "token attribute value":
//   - if a number, the type is NUM and tokenval is the value
//   - if a variable, the type is ID and tokenval is an index
//     into the symbol table
//   - if end-of-file, the type is DONE
//   - if 'BEGIN' or 'END' operator, the type is BEGIN or END
//   - if a single character arithmetic operator, the type is the character
//     value of the operator

void lexer_init() {
   // initialize symbol table
   ;
}

// return current line number
int lexer_lineno() {
   return lineno;
}

// return the token type as an integer
// (the token attribute value is stored in global variable tokenval)
int lexan() {
   int t;
   while (1) {
      t = getchar();
      if (t == ' ' || t == '\t')
	 // skip over blanks and tabs
	 ;    
      else if (t == '\n')
	 lineno++;
      else if (t == '^' || t == '$' || t == '*' || t == '.')
	 return t;
      else if (isalnum(t)) 
	 return t;
      else if (t == EOF)
	 return DONE;
      else 
	 error("lexical error");
   }
} 
 
