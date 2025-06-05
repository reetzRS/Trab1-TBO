all:
	gcc -g src/main.c src/graph/graph.c src/point/point.c src/io/io.c src/kruskal/kruskal.c src/union_find/union_find.c -o trab1 -lm

clean:
	rm -rf trab1

