#include "Graph.h"
#include <iostream>
#include <climits>

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
    int v1 = vertex1 - 1;
    int v2 = vertex2 - 1;

    adjacency_matrix[v1 * this->num_verticies + v2] = weight;
    adjacency_matrix[v2 * this->num_verticies + v1] = weight;
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

// ********** LAST METHOD TO UPLOAD **********
int *Graph::perform_dijkstras(int starting_vertex)
{
    // int num_verticies = this->num_verticies;
    // int *weights = new int[num_verticies + 1];

    // // initialize the first element as the number of verticies stored
    // weights[0] = num_verticies;

    // // initialize all weights to +inf
    // for (int i = 0; i < num_verticies; i++)
    // {
    //     weights[i] = INT_MAX;
    // }

    // // the weight from starting_vertex to starting_vertex will always be 0
    // weights[starting_vertex] = 0;

    // int *immediate_neighbors = find_immediate_neighbors(starting_vertex);
    // int neighbor_count = immediate_neighbors[0];

    // // if the immediate neighbor's access distance is less
    // for (int i = 1; i <= neighbor_count; i++)
    // {
    //     int position_in_matrix = ((starting_vertex - 1) * (this->num_verticies)) + (immediate_neighbors[i] - 1);
    //     if (adjacency_matrix[position_in_matrix] < weights[immediate_neighbors[i]])
    //     {
    //         weights[immediate_neighbors[i]] = adjacency_matrix[position_in_matrix];
    //     }
    // }
}

int *Graph::find_immediate_neighbors(int source_vertex)
{
    int *neighbors = new int[this->num_verticies];
    int neighbor_count = 0;

    int offset = (source_vertex - 1) * this->num_verticies;
    int end_of_row = offset + this->num_verticies;

    for (int i = offset; i < end_of_row; i++)
    {
        if (this->adjacency_matrix[i] != 0)
        {
            neighbors[neighbor_count + 1] = (i % this->num_verticies) + 1;
            neighbor_count += 1;
        }
    }
    neighbors[0] = neighbor_count;
    return neighbors;
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

void Graph::print_dijkstras(int starting_vertex, int *path)
{
    std::cout << "The shortest path lengths from Node " << starting_vertex << " to all other nodes are:" << std::endl;

    int path_length = path[0];
    for (int i = 1; i <= path_length; i++)
    {
        std::cout << i << " " << path[i] << " " << std::endl;
    }
}