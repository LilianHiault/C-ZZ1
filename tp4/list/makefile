# compilateur
CC = gcc
# options
# CFLAGS = -Wall -Wextra -Wdeclaration-after-statement -Werror=vla -g
CFLAGS = -Wall -Wextra -Wdeclaration-after-statement -g
LDFLAGS = -lm
# liste des fichiers objets
SRC =  main.c list.c # hall_of_fame.c hall_of_tests.c teZZt.c 
OBJETS = $(SRC:%.c=%.o)

prog : $(OBJETS)
	$(CC) $(OBJETS) $(LDFLAGS) -o prog

# hall_of_fame.o: hall_of_fame.h hall_of_fame.c
# 	$(CC) -c hall_of_fame.c $(CFLAGS)

# teZZt.o: teZZt.h teZZt.c
# 	$(CC) -c teZZt.c $(CFLAGS)

# hall_of_tests.o: hall_of_tests.c teZZt.h hall_of_fame.h
# 	$(CC) -c hall_of_tests.c $(CFLAGS)

list.o: list.c list.h
	$(CC) -c list.c $(CFLAGS)

main.o: list.h list.c
	$(CC) -c main.c $(CFLAGS)

clean:
	rm -f $(OBJETS)
