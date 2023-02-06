CC = gcc
CFLAGS = -Wall -Wextra -g3

all: bin/main.exe

bin/union_find.o: lib/union_find.c
	$(CC) lib/union_find.c -o $@ $(CFLAGS) -c

bin/main.o: main.c
	$(CC) main.c -o $@ $(CFLAGS) -c

bin/avl.o: lib/avl.c
	$(CC) lib/avl.c -o $@ $(CFLAGS) -c

bin/main.exe: bin/union_find.o bin/main.o bin/avl.o
	$(CC) bin/main.o bin/union_find.o bin/avl.o -o $@ $(CFLAGS)

run: bin/main.exe
	./bin/main.exe

clear:
	rm *.o -rf
	rm *.exe -rf
	rm bin/*.o -rf
	rm bin/*.exe -rf