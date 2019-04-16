
FLAGS = -Wall -pthread -g

test:	counter
	./counter

test-many: counter
	for i in {1..100}; do ./counter; done

counter: counter.c
	gcc -o counter counter.c $(FLAGS)

test-locks:
	gcc -o counter counter-with-locks.c
	./counter

clean:
	rm -f counter

