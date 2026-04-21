#include "Graph.h"
#include "MinHeap.h"
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
    Triplet **triplets = new Triplet *[this->num_verticies];
    int triplet_count = 0;

    // set of all nodes
    int *all_nodes = new int[this->num_verticies + 1];
    all_nodes[0] = this->num_verticies;

    // set of each nodes min distance from current source node
    int *distances = new int[this->num_verticies + 1];
    distances[0] = this->num_verticies;

    int *predecessors = new int[this->num_verticies + 1];
    predecessors[0] = this->num_verticies;

    // initialize each array
    for (int i = 1; i <= this->num_verticies; i++)
    {
        all_nodes[i] = i;
        distances[i] = INT_MAX;
        predecessors[i] = -1;
    }

    // distance from source vertex to source vertex = 0
    distances[starting_vertex] = 0;

    MinHeap *minheap = new MinHeap(all_nodes, distances);
    int cumulative_distance_from_source = 0;

    while (minheap->pair_count > 0)
    {
        Triplet *min = minheap->extract_min();
        triplets[triplet_count] = min;
        triplet_count += 1;

        int *immediate_neighbors = find_immediate_neighbors(min->get_vertex());
        int immediate_neighbor_count = immediate_neighbors[0];

        for (int i = 1; i <= immediate_neighbor_count; i++)
        {
            
        }
    }
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