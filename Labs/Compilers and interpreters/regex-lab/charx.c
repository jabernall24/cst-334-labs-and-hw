#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "charx.h"
#include "regex.h"

// a character pattern with an optional modifier

// constructor
CHARX *charx_create(char c, int mod) {
   CHARX *charx = (CHARX *)malloc(sizeof(CHARX));
   charx->c = c;
   charx->mod = mod;
   return charx;
}

void charx_print(CHARX *charx) {
   printf("%c",charx->c);
   if (charx->mod == STAR) {
      printf("%c", '*');
   }
}

