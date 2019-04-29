#include <stdlib.h>
#include "lexer.h"
#include "charx.h"
#include "regex.h"
#include "parser.h"

void test_regex(), test_objects();

void main(int argc, char *argv[]) {
   CHARX *charx;
   REGEX *regx;

   // parse regex from standard input
   lexer_init();
   regx = parse();
   regex_print(regx);
   printf("\n");

   // test the regex on a string
   test_regex(regx, "abc");
   test_regex(regx, "ab");
   test_regex(regx, "bcab");
   test_regex(regx, "");
   test_regex(regx, "aacc");
   test_regex(regx, "acacb");

   exit(EXIT_SUCCESS);
}

void test_regex() {
   // your code here
}

// create and test some REGEX objects
void test_objects() {
   CHARX *charx;
   REGEX *regx;

   CHARX *a = charx_create('a', NO_MOD);
   CHARX *b = charx_create('b', NO_MOD);
   CHARX *dot = charx_create('.', NO_MOD);
   CHARX *dot_star = charx_create('.', STAR);
   CHARX *a_star = charx_create('a', STAR);

   // regex a
   regx = regex_create(a, NULL, 0);
   test_regex(regx, "abc");

   // regex .
   regx = regex_create(dot, NULL, 0);
   test_regex(regx, "abc");

   // regex ab
   regx = regex_create(b, NULL, 0);
   regx = regex_create(a, regx, 0);
   test_regex(regx, "abc");

   // regex a.b
   regx = regex_create(b, NULL, 0);
   regx = regex_create(dot, regx, 0);
   regx = regex_create(a, regx, 0);
   test_regex(regx, "acb");
   test_regex(regx, "acc");

   // regex a*
   regx = regex_create(a_star, NULL, 0);
   test_regex(regx, "bcd");
   test_regex(regx, "abc");
   test_regex(regx, "aaa");

   // regex a.*b
   regx = regex_create(b, NULL, 0);
   regx = regex_create(dot_star, regx, 0);
   regx = regex_create(a, regx, 0);
   test_regex(regx, "abc");
   test_regex(regx, "accc");
   test_regex(regx, "accbcc");
   test_regex(regx, "ac");
}

