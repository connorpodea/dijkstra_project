#include "Graph.h"
#include <iostream>

Graph::Graph(int num_verticies)
{
    this->num_verticies = num_verticies;
    int size_of_matrix = num_verticies * num_verticies;
    this->adjacency_matrix = new int[size_of_matrix];

    for (int i = 0; i < size_of_matrix; i++)
    {
        adjacency_matrix[i] = 0;
    }
}

void Graph::update_adjacency_matrix(int vertex1, int vertex2, int weight)
{
    int x = vertex1 - 1;
    int y = vertex2 - 1;

    adjacency_matrix[x * num_verticies + y] = weight;
    adjacency_matrix[y * num_verticies + x] = weight;
}

void Graph::print_adjacency_matrix()
{
    std::cout << "The adjacency matrix of G is:";

    int size_of_matrix = num_verticies * num_verticies;

    for (int i = 0; i < size_of_matrix; i++)
    {
        if (i % this->num_verticies == 0)
        {
            std::cout << "\n";
        }
        std::cout << this->adjacency_matrix[i] << " ";
    }
    std::cout << "\n\n";
}

void Graph::print_odd_degrees()
{
}