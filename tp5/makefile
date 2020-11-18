# compilateur
CC = gcc

# options
CFLAGS = -Wall -Wextra -Wdeclaration-after-statement -Werror=vla -g
LDFLAGS = -lm

# liste des fichiers objets
SRC =  flood_it.c
OBJETS = $(SRC:%.c=%.o)

prog : $(OBJETS)
	$(CC) $(OBJETS) $(LDFLAGS) -o prog

flood_it.o: flood_it.c
	$(CC) -c flood_it.c $(CFLAGS)

clean:
	rm -f $(OBJETS)
