#include "Graph.h"
#include <iostream>
#include <climits>

Graph::Graph(int num_verticies)
{
    // initialize graph attributes
    this->num_verticies = num_verticies;
    this->size_of_adjacency_matrix = num_verticies * num_verticies;
    this->adjacency_matrix = new int[this->size_of_adjacency_matrix];

    // note: although matricies are represented by two dimensional arrays,
    // a one dimensional array works the same with a little extra math (cache efficient!)

    // initialize the matrix with 0's
    for (int i = 0; i < this->size_of_adjacency_matrix; i++)
    {
        adjacency_matrix[i] = 0;
    }
}

Graph::~Graph()
{
    // destructor
    delete[] this->adjacency_matrix;
}

void Graph::update_adjacency_matrix(int vertex1, int vertex2, int weight)
{
    // verticies in the matrix are zero indexed
    int v1 = vertex1 - 1;
    int v2 = vertex2 - 1;

    // intialize both edges (v1 to v2 and v2 to v1)
    adjacency_matrix[v1 * this->num_verticies + v2] = weight;
    adjacency_matrix[v2 * this->num_verticies + v1] = weight;
}

int *Graph::find_odd_degrees()
{
    // the count of odd_degrees will be stored at index 1 of the resultant array
    int odd_degree_count = 0;
    int *odd_degrees = new int[this->num_verticies + 1];

    // store the degrees of each vertex to determine which ones are odd. also initalize the array with 0's
    int *degrees_of_each_vertex = new int[this->num_verticies + 1]();

    // current node keeps track of which vertex we are assesing (extra math beacuse of one dimensional array)
    int current_node = 0;

    for (int i = 0; i < this->size_of_adjacency_matrix; i++)
    {
        // this identifies the beginning of a new vertex (treated as a row in this case)
        if (i % this->num_verticies == 0)
        {
            current_node += 1;
        }

        // if non-zero, this implies an edge
        if (this->adjacency_matrix[i] != 0)
        {
            degrees_of_each_vertex[current_node] += 1;
        }
    }

    // loop through the degrees of each node and determine which ones are odd, storing them in the array to be returned
    // the size of the resultant array is stored at index 0 of the resultant array for access outside of the method
    for (int vertex = 1; vertex <= this->num_verticies; vertex++)
    {
        if (!(degrees_of_each_vertex[vertex] % 2 == 0))
        {
            odd_degrees[odd_degree_count + 1] = vertex;
            odd_degree_count += 1;
        }
    }
    odd_degrees[0] = odd_degree_count;

    // free the memory for the array
    delete[] degrees_of_each_vertex;

    return odd_degrees;
}

Triplet **Graph::perform_dijkstras(int starting_vertex)
{
    // triplets are a struct which include the node's name, the node's distance from its predecessor, and its predecessor
    Triplet **triplets = new Triplet *[this->num_verticies];

    // set of all nodes
    int *all_nodes = new int[this->num_verticies + 1];
    // not necessary to store the size, but helps with (index to node) name matching
    all_nodes[0] = this->num_verticies;

    // set of each nodes min distance from current source node
    int *distances = new int[this->num_verticies + 1];
    // not necessary to store the size, but helps with (index to node) name matching
    distances[0] = this->num_verticies;

    // initialize each array with their default values
    for (int i = 1; i <= this->num_verticies; i++)
    {
        all_nodes[i] = i;
        distances[i] = INT_MAX;
    }

    // distance from source vertex to source vertex = 0
    distances[starting_vertex] = 0;

    // create a min heap to simplify and reduce the time complexity of dijkstra's algorithm
    MinHeap *minheap = new MinHeap(all_nodes, distances);

    // while the heap is non empty, pop the vertex with minimum distance from its predecessor and "relax" the neighbors
    while (minheap->triplet_count > 0)
    {
        // pop the top of the minheap
        Triplet *min = minheap->extract_min();

        // store this in the array to return, at index[node number] so you dont have to sort based on node number later while printing
        triplets[min->get_vertex() - 1] = min;

        // find immediate neighbors
        int *immediate_neighbors = find_immediate_neighbors(min->get_vertex());
        int immediate_neighbor_count = immediate_neighbors[0];

        // for each immediate neighbor, "relax" the neighbor
        for (int i = 1; i <= immediate_neighbor_count; i++)
        {
            // compute the edge weight between the current neighbor in question and the vertex extracted from the min heap
            int vertex_extracted = min->get_vertex();
            int vertex_adjacent = immediate_neighbors[i];
            int edge_distance = this->adjacency_matrix[(vertex_extracted - 1) * this->num_verticies + (vertex_adjacent - 1)];

            // relax will compute wheter or not to update edge_distance and predecessor, as well as increasing priority if relaxed
            minheap->relax(vertex_adjacent, edge_distance + min->get_distance(), vertex_extracted);
        }
        // free the memory for the array
        delete[] immediate_neighbors;
    }
    // free the memory for the arrays
    delete[] all_nodes;
    delete[] distances;

    // free the memory for the minheap
    delete minheap;

    return triplets;
}

int *Graph::find_immediate_neighbors(int source_vertex)
{
    // at most num_verticies - 1 neighbors and the first index to store the number of neighbors, only need space for num_verticies elements
    int *neighbors = new int[this->num_verticies];
    int neighbor_count = 0;

    // row identifiers
    int offset = (source_vertex - 1) * this->num_verticies;
    int end_of_row = offset + this->num_verticies;

    // if a non-zero weight appears in this row at column c, c + 1 is an immediate neighbor
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
    std::cout << "}" << std::endl
              << std::endl;
}

void Graph::print_dijkstras(int starting_vertex, Triplet **triplets)
{
    std::cout << "The shortest path lengths from Node " << starting_vertex << " to all other nodes are:" << std::endl;

    for (int i = 0; i < this->num_verticies; i++)
    {
        std::cout << "   " << i + 1 << ": " << triplets[i]->get_distance() << " " << std::endl;
    }
    std::cout << std::endl;
}
