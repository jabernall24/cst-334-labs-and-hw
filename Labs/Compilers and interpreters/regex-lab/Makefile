
SOURCES = main.c charx.c regex.c parser.c lexer.c

run: regx
	./regx < test.txt

regx: $(SOURCES)
	gcc -o regx $(SOURCES)

clean:
	rm -f regx
