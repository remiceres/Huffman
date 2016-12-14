CC=gcc
OBJECTS=src/main.o src/frequences.o src/constrcArbre.o src/codeBin.o src/generation.o
CFLAGS=-Wall -std=c99 -g
PROG=huf

$(PROG): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(PROG)

clean:
	rm -f src\/*.o $(PROG) *.huf
