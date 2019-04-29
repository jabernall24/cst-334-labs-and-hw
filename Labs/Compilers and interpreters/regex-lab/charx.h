#ifndef CHARX_INC
#define CHARX_INC
#include <stdio.h>
#include "regex.h"

CHARX *charx_create(char c, int mod);
int charx_match(CHARX *charx, REGEX *regx, char *s);
void charx_print(CHARX *charx);

#endif 
