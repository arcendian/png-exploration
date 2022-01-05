CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c11 -O2
BIN=png_exp
SRC=main.c

all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(BIN)
