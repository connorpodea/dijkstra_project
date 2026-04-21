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
        g->update_adjacency_matrix(vertex1, vertex2, weight);
    }

    // ***** task 1 *****
    g->print_adjacency_matrix();

    // ***** task 2 *****
    int *odd_degrees = g->find_odd_degrees();
    int odd_degree_count = odd_degrees[0];
    g->print_odd_degrees(odd_degrees);

    // ***** task 3 *****
    // loop through each odd-degree vertex, calling perform dijkstras and print dijkstras
    for (int i = 1; i <= odd_degree_count; i++)
    {
        int starting_vertex = odd_degrees[i];
        Triplet **dijkstras_path = g->perform_dijkstras(starting_vertex);
        g->print_dijkstras(starting_vertex, dijkstras_path);
    }

    return 0;
}
