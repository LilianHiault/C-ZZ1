CC = gcc
CFLAGS = -g -Wall -Wextra -Wdeclaration-after-statement -Werror=vla
LDFLAGS = -lm
OBJETS = sudoku.o

all:sudoku

sudoku:$(OBJETS)
	$(CC) $(CFLAGS) -o $@ $(OBJETS) $(LDFLAGS)

sudoku.o:sudoku.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJETS)
