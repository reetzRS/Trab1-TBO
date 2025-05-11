CC = gcc
SRC = src/main.c src/point/point.c
OBJ = $(SRC:src/%.c=build/%.o)
BIN = build/trab1

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $@

build/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@

clean:
	rm -rf build/
