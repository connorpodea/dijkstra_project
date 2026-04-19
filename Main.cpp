#include <iostream>
#include "Graph.h";
#include "Vertex.h"
#include "Edge.h";

int main()
{

    // start of the initial pipeline that loads the test case file stream from std::cin
    int num_verticies;
    int num_edges;

    if (!std::cin.eof())
    {
        std::cin >> num_verticies;
        std::cin >> num_edges;
    }
    else
    {
        std::cout << "Input not found!" << std::endl;
        return NULL;
    }

    // initialize the graph
    Graph *g = new Graph(num_verticies, num_edges);
    int insertion_index = 0;

    while (!std::cin.eof())
    {
        int startVertice;
        int endVertice;
        int weight;
        std::cin >> startVertice;
        std::cin >> endVertice;
        std::cin >> weight;

        // load up the Graph object
        Vertex *startVertice = new Vertex(startVertice);
        Vertex *endVertice = new Vertex(endVertice);
    }

    return 0;
}
