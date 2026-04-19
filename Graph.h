#include "Vertex.h";
#include "Edge.h";

class Graph
{
private:
    int num_verticies;
    Vertex **vertices;

    int num_edges;
    Edge **edges;

public:
    Graph(int num_verticies, int num_edges);

    void add_vertex(Vertex *vertex);
    void add_edge(Edge *edge);
};