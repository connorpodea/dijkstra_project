all: Main.o Graph.o MinHeap.o
	g++ -g -Wall Main.o Graph.o MinHeap.o -o dijkstra

Main.o: Main.cpp Graph.h
	g++ -g -Wall -c Main.cpp

Graph.o: Graph.cpp Graph.h MinHeap.h
	g++ -g -Wall -c Graph.cpp

MinHeap.o: MinHeap.cpp MinHeap.h
	g++ -g -Wall -c MinHeap.cpp

clean:
	rm -rf *.o dijkstra