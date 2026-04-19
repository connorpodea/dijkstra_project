all: Main.o Graph.o
	g++ -g -Wall Main.o Graph.o -o dijkstra

Main.o: Main.cpp Graph.h
	g++ -g -Wall -c Main.cpp

Graph.o: Graph.cpp Graph.h
	g++ -g -Wall -c Graph.cpp

clean:
	rm -rf *.o dijkstra