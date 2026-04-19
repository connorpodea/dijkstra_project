#include "Vertex.h"
#include <climits>

struct Edge
{
    Vertex *vertex1;
    Vertex *vertex2;
    int weight;

    Edge();
    Edge(Vertex *vertex1, Vertex *vertex2, int weight);
};