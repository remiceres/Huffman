CC=gcc
OBJECTS=main.o frequences.o constrcArbre.o codeBin.o generation.o
CFLAGS=-Wall -std=c99 -g
PROG=huff
$(PROG): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(PROG) -lm
main.o: main.c # dépendances de main.c = fichiers inclus
frequences.o: frequences.c # dépendances de frequences.c = fichiers inclus
constrcArbre.o: constrcArbre.c # dépendances de constrcArbre.c = fichiers inclus
codeBin.o: codeBin.c # dépendances de constrcArbre.c = fichiers inclus
generation.o: generation.c # dépendances de constrcArbre.c = fichiers inclus

clean:
	rm -f *.o $(PROG)
