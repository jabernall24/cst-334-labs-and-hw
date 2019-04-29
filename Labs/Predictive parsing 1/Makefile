#
# predictive parser lab
#

SOURCES = error.c lexer.c main.c parser.c symbol.c 

run: parser 
	./parser < input.txt

parser: $(SOURCES)
	gcc -o parser $(SOURCES)

pred-parser.tar:
	tar cf pred-parser.tar *.c *.h *.txt Makefile

clean:
	rm -f *~ temp* *.o parser

