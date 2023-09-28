CC = gcc
CFLAGS = -Wall -pedantic -ansi -w
FILES = main.c IdInput.c PrintTable.c
OUT_EXE = as1

build: $(FILES)
	$(CC) $(CFLAGS) -o $(OUT_EXE) $(FILES)

clean:
	rm -f *.o core *.exe *~

rebuild: clean build