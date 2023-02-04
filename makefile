CC = gcc
CFLAGS = -Wall -Wextra -g3

all: bin/main.exe

bin/union_find.o: lib/union_find.c
	$(CC) lib/union_find.c -o bin/union_find.o $(CFLAGS)

bin/main.o: main.c
	$(CC) main.c -o bin/main.o $(CFLAGS)

bin/main.exe: bin/union_find.o bin/main.o
	$(CC) bin/main.o bin/union_find.o -o bin/main.exe $(CFLAGS)

run: bin/main.exe
	./bin/main.exe

clear:
	rm *.o -rf
	rm *.exe -rf
	rm bin/*.o -rf
	rm bin/*.exe -rf