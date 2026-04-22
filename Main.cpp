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
    // ***** print adjacency matrix *****
    g->print_adjacency_matrix();

    // ***** task 2 *****
    // ***** list of all the nodes whose degree is an odd number *****
    int *odd_degrees = g->find_odd_degrees();
    int odd_degree_count = odd_degrees[0];
    g->print_odd_degrees(odd_degrees);

    // ***** task 3 *****
    // ***** executing dijkstras on nodes with an odd degree and printing a list of the shortest paths from source to each odd degree node *****
    for (int i = 1; i <= odd_degree_count; i++)
    {
        int starting_vertex = odd_degrees[i];
        Triplet **dijkstras_path = g->perform_dijkstras(starting_vertex);
        g->print_dijkstras(starting_vertex, dijkstras_path);

        // free the memory for each element in the array
        for (int j = 0; j < num_verticies; j++)
        {
            delete dijkstras_path[j];
        }
        // free the memory for the array
        delete[] dijkstras_path;
    }

    // free the memory for the array
    delete[] odd_degrees;
    
    // free the memory for the graph
    delete g;

    return 0;
}
