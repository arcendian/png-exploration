CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c11 -O2
BIN=png_exp
OFILES=png_utils.o main.o

all: $(BIN)

$(BIN): $(OFILES)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(BIN) $(OFILES)

main.o: main.c png_utils.h
png_utils.o: png_utils.c png_utils.h
