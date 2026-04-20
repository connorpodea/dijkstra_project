#include "Graph.h"
#include <iostream>

Graph::Graph(int num_verticies)
{
    this->num_verticies = num_verticies;
    this->size_of_adjacency_matrix = num_verticies * num_verticies;
    this->adjacency_matrix = new int[this->size_of_adjacency_matrix];

    for (int i = 0; i < this->size_of_adjacency_matrix; i++)
    {
        adjacency_matrix[i] = 0;
    }
}

void Graph::update_adjacency_matrix(int vertex1, int vertex2, int weight)
{
    int x = vertex1 - 1;
    int y = vertex2 - 1;

    adjacency_matrix[x * this->num_verticies + y] = weight;
    adjacency_matrix[y * this->num_verticies + x] = weight;
}

int *Graph::find_odd_degrees()
{
    // the count of odd_degrees will be stored at index 1 of the resultant array
    int odd_degree_count = 0;
    int *odd_degrees = new int[this->num_verticies + 1];
    int *degrees_of_each_vertex = new int[this->num_verticies];
    int current_node = 0;

    for (int i = 0; i < this->size_of_adjacency_matrix; i++)
    {
        if (i % this->num_verticies == 0)
        {
            current_node += 1;
        }

        if (this->adjacency_matrix[i] != 0)
        {
            degrees_of_each_vertex[current_node] += 1;
        }
    }

    for (int vertex = 1; vertex <= this->num_verticies; vertex++)
    {
        if (!(degrees_of_each_vertex[vertex] % 2 == 0))
        {
            odd_degrees[odd_degree_count + 1] = vertex;
            odd_degree_count += 1;
        }
    }
    odd_degrees[0] = odd_degree_count;
    return odd_degrees;
}

int Graph::*perform_dijkstras()
{
}

void Graph::print_adjacency_matrix()
{
    std::cout << "The adjacency matrix of G is:" << std::endl;

    for (int i = 0; i < this->size_of_adjacency_matrix; i++)
    {
        if (i % this->num_verticies == 0)
        {
            std::cout << std::endl;
        }
        std::cout << this->adjacency_matrix[i] << " ";
    }
    std::cout << std::endl
              << std::endl;
}

void Graph::print_odd_degrees(int *odd_degrees)
{
    int odd_degree_count = odd_degrees[0];

    std::cout << "The nodes with odd degrees in G are:\n";
    std::cout << "O = { ";
    for (int i = 1; i <= odd_degree_count; i++)
    {
        std::cout << odd_degrees[i] << " ";
    }
    std::cout << "}" << std::endl;
}

void Graph::print_dijkstras(int *vertecies)
{
}