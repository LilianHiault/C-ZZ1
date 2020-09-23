CC = gcc
FLAGS = -g -Wall -Wextra -Wdeclaration-after-statement -Werror=vla
OBJETS = sudoku.o

all:sudoku

sudoku:$(OBJETS)
	$(CC) $(FLAGS) -o $@ $(OBJETS)

sudoku.o:sudoku.c
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJETS)
