# compilateur
CC = gcc
# options
CFLAGS = -Wall -Wextra -Wdeclaration-after-statement -Werror=vla -g
LDFLAGS = -lm
# liste des fichiers objets
SRC = hall_of_fame.c hall_of_tests.c teZZt.c
OBJETS = $(SRC:%.c=%.o)

prog : $(OBJETS)
	$(CC) $(OBJETS) $(LDFLAGS) -o prog

hall_of_fame.o: hall_of_fame.h hall_of_fame.c
	$(CC) -c hall_of_fame.c $(CFLAGS)

teZZt.o: teZZt.h teZZt.c
	$(CC) -c teZZt.c $(CFLAGS)

hall_of_tests.o: hall_of_tests.c teZZt.h hall_of_fame.h
	$(CC) -c hall_of_tests.c $(CFLAGS)

clean:
	rm -f $(OBJETS)
