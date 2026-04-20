class Graph
{
private:
    int num_verticies;
    int num_edges;
    int size_of_adjacency_matrix;
    int *adjacency_matrix;

public:
    Graph(int num_verticies);

    void update_adjacency_matrix(int vertex1, int vertex2, int weight);
    int *find_odd_degrees();
    int *perform_dijkstras();

    void print_adjacency_matrix();
    void print_odd_degrees(int *odd_degrees);
    void print_dijkstras(int *vertecies);
};