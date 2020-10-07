NOM = guichets
CC = gcc
CFLAGS = -g -Wall -Wextra -Wdeclaration-after-statement -Werror=vla
LDFLAGS = -lm
OBJETS = $(NOM).o

all:$(NOM)

$(NOM):$(OBJETS)
	$(CC) $(CFLAGS) -o $@ $(OBJETS) $(LDFLAGS)

$(NOM).o:$(NOM).c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJETS)
