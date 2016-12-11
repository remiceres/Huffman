CC=gcc
OBJECTS=src/decompresseur.o src/main.o
CFLAGS=-Wall -std=c99 -g
PROG=dehuf

$(PROG): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(PROG)


clean:
	rm -f src\/*.o $(PROG) Résultat
