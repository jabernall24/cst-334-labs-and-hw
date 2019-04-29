#ifndef REGEX_INC
#define REGEX_INC
#include <stdio.h>

// modifier values
#define NO_MOD 0
#define STAR   1

// anchor values
#define ANCHOR_NONE  0
#define ANCHOR_START 1

// a character pattern with an optional modifier
typedef struct charx {
   char c;
   int  mod;
} CHARX;

// a regular expression is a character expression followed by
// an optional regular expression (use NULL if absent)
typedef struct regex {
   int anchor;          // anchor value (see above)
   CHARX *charx; 
   struct regex *regx;
} REGEX;

REGEX *regex_create(CHARX *charx, REGEX *continuation, int anchored);
int regex_match_here(REGEX *regx, char *s);
int regex_match(REGEX *regx, char *s);
void regex_print(REGEX *regx);

#endif 
