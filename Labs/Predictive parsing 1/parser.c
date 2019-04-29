#include "lexer.h"
#include "error.h"

int lookahead;
void nums();

void match(int t) { 
    if (lookahead == t)
	lookahead = lexan();
    else error("syntax error");
} 

// main parsing function
void parse() {
   lookahead = lexan();
   nums();
   match(DONE);
}

// a list of one or more numbers, where each number is followed by ;
// nums ::= num ; nums
//        | ""
void nums() {
   switch(lookahead) {
   case NUM:
      match(NUM);
      match(';');
      nums();
      break;
   default:
      ; // empty production
   }
}

void vars() {
    switch (lookahead) {
        case 'var':
            printf("var");
//            match(ID);
//            vars2();
            break;
            
        default:
            break;
    }
}

//void vars2() {
//    switch (lookahead) {
//        case ",":
//            <#statements#>
//            break;
//
//        default:
//            break;
//    }
//}
