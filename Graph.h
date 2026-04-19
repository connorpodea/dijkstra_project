class Graph
{
private:
    int num_verticies;
    int num_edges;
    int *adjacency_matrix;

public:
    Graph(int num_verticies);

    void update_adjacency_matrix(int vertex1, int vertex2, int weight);
    void print_adjacency_matrix();
    void print_odd_degrees();
};