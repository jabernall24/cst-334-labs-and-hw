#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "charx.h"
#include "regex.h"

// a simple regular expression

// constructor; second parameter is NULL if no continuation
REGEX *regex_create(CHARX *charx, REGEX *continuation, int anchor) {
   REGEX *regx = (REGEX *)malloc(sizeof(REGEX));
   regx->anchor = anchor;
   regx->charx = charx;
   regx->regx = continuation;
   return regx;
}

// print this
void regex_print(REGEX *regx) {
   if (regx->anchor == ANCHOR_START) {
      printf("%c", '^');
   }
   charx_print(regx->charx);
   if (regx->regx != NULL) {
      regex_print(regx->regx);
   }
}

