class Graph
{
private:
    int num_verticies;
    int size_of_adjacency_matrix;
    int *adjacency_matrix;

public:
    Graph(int num_verticies);

    void update_adjacency_matrix(int vertex1, int vertex2, int weight);
    int *find_odd_degrees();
    int *perform_dijkstras(int vertex);
    int *find_immediate_neighbors(int source_vertex);

    void print_adjacency_matrix();
    void print_odd_degrees(int *odd_degrees);
    void print_dijkstras(int starting_vertex, int *path);
};