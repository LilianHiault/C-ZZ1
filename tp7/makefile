# compilateur
CC = gcc

# options
CFLAGS = -Wall -Wextra -Wdeclaration-after-statement -Werror=vla -g

LDFLAGS = -lm

# liste des fichiers objets
SRC = docu.c
OBJETS = $(SRC:%.c=%.o)

prog : $(OBJETS)
	$(CC) $(OBJETS) $(LDFLAGS) -o prog

docu.o: docu.c
	$(CC) -c docu.c $(CFLAGS)

clean:
	rm -f $(OBJETS)
