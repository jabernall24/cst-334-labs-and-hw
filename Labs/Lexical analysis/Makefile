
# code to test lexers

VERSION = parser4.c
SOURCES = lexer.c main.c symbol.c $(VERSION)

test1: parser 
	./parser <<< "x = 10"

test2: parser 
	./parser <<< "adj = 3"

test3: parser
	./parser <<< "y=5"

parser: $(SOURCES)
	gcc -o parser $(SOURCES)

clean:
	rm -f *~ temp* *.o parser

