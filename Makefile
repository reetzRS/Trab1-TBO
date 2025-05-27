CC = gcc
SRC = src/main.c src/point/point.c src/graph/graph.c src/kruskal/kruskal.c
OBJ = $(SRC:src/%.c=build/%.o)
BIN = build/trab1

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $@ -lm

build/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@

clean:
	rm -rf build/


test_graph:
	gcc -g src/main.c src/graph/graph.c src/point/point.c -o build/trab1 -lm

valgrind:
	valgrind --leak-check=full ./build/trab1
