#include <iostream>
#include "Graph.h"

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
        return -1;
    }

    // initialize the graph

    // *** testing out a different approach ***
    // Graph *g = new Graph(num_verticies, num_edges);

    Graph *g = new Graph(num_verticies);

    while (!std::cin.eof())
    {
        int vertex1;
        int vertex2;
        int weight;
        std::cin >> vertex1;
        std::cin >> vertex2;
        std::cin >> weight;

        // load up the Graph object

        // *** testing out a different approach ***
        // Vertex *start_vertex = new Vertex(vertex1);
        // Vertex *end_vertex = new Vertex(vertex2);

        // g->add_vertex(start_vertex);
        // g->add_vertex(end_vertex);
        // g->add_edge(new Edge(start_vertex, end_vertex, weight));

        g->update_adjacency_matrix(vertex1, vertex2, weight);
    }

    g->print_adjacency_matrix();

    return 0;
}
