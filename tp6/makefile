# compilateur
CC = gcc

# options
CFLAGS = -Wall -Wextra -g
# -Wdeclaration-after-statement -Werror=vla `sdl-config --cflags`
LDFLAGS = -lm -lSDL2 -lSDL2_gfx -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_net
# `sdl-config --libs`

# liste des fichiers objets
SRC = main.c
OBJETS = $(SRC:%.c=%.o)

prog : $(OBJETS)
	$(CC) $(OBJETS) $(LDFLAGS) -o prog

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

# hall_of_fame.o: hall_of_fame.h hall_of_fame.c
# 	$(CC) -c hall_of_fame.c $(CFLAGS)

# teZZt.o: teZZt.h teZZt.c
# 	$(CC) -c teZZt.c $(CFLAGS)

# hall_of_tests.o: hall_of_tests.c teZZt.h hall_of_fame.h
# 	$(CC) -c hall_of_tests.c $(CFLAGS)

clean:
	rm -f $(OBJETS)
