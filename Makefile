CFLAGS=-std=gnu99 -g -O2 -Wall

.PHONY: clean test

minilisp: minilisp.c main.c

clean:
	rm -f minilisp *~

test: minilisp
	@./test.sh
