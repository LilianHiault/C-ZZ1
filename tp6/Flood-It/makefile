# compilateur
CC = gcc

# options
CFLAGS = -Wall -Wextra -Wdeclaration-after-statement -Werror=vla -g

LDFLAGS = -lm -lSDL2 -lSDL2_gfx -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_net

# liste des fichiers objets
SRC = flood_it.c
OBJETS = $(SRC:%.c=%.o)

prog : $(OBJETS)
	$(CC) $(OBJETS) $(LDFLAGS) -o prog

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

clean:
	rm -f $(OBJETS)
