CC=gcc
OBJECTS=src/main.o src/frequences.o src/constrcArbre.o src/codeBin.o src/generation.o
CFLAGS=-Wall -std=c99 -g
PROG=huf

$(PROG): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(PROG) -lm
main.o: src/main.c # dépendances de main.c = fichiers inclus
frequences.o: src/frequences.c # dépendances de frequences.c = fichiers inclus
constrcArbre.o: src/constrcArbre.c # dépendances de constrcArbre.c = fichiers inclus
codeBin.o: src/codeBin.c # dépendances de constrcArbre.c = fichiers inclus
generation.o: src/generation.c # dépendances de constrcArbre.c = fichiers inclus

clean:
	rm -f src\/*.o $(PROG) *.huf
