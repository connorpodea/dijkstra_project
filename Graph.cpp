#include "Graph.h";

Graph::Graph(int num_verticies, int num_edges)
{
    this->num_verticies = num_verticies;
    this->vertices = new Vertex *[num_verticies];

    this->num_edges = num_edges;
    this->edges = new Edge *[num_edges];

    // initialize both arrays to null objects

    for (int i = 0; i < num_verticies; i++)
    {
        vertices[i] = nullptr;
    }

    for (int i = 0; i < num_edges; i++)
    {
        edges[i] = nullptr;
    }
}

void Graph::add_vertex(Vertex *vertex)
{
    // given a vertex, identify its position within the array using label % num_verticies
    vertices[(vertex->label) % num_verticies];
}

void Graph::add_edge(Edge *edge)
{
    // given a edge, identify its position within the array using label % num_edges
    
}