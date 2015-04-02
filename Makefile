CC=gcc -O2 -g -Wall -Werror -Wextra -std=c99 -pedantic-errors
prefix=/usr
executable=fibo
%.o: %.c
	$(CC) -c $< -o $@ -lgmp

all: fibo

fibo: fibo.o
	$(CC) -o $(executable) fibo.o -lgmp

install: fibo
	install -m 0755 $(executable) $(prefix)/bin

.PHONY: install

clean:
	rm -f *.o $(executable)
