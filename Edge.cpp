#include "Edge.h";

Edge::Edge()
{
    this->vertex1 = nullptr;
    this->vertex2 = nullptr;
    this->weight = INT_MAX;
}

Edge::Edge(Vertex *vertex1, Vertex *vertex2, int weight)
{
    this->vertex1 = vertex1;
    this->vertex2 = vertex2;
    this->weight = weight;
}
