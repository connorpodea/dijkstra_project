struct Triplet
{
    int vertex;
    int distance;
    int predecessor;

    Triplet(int vertex, int distance);
    int get_vertex();
    int get_distance();
    int get_predecessor();
    void update_distance(int new_distance);
    void update_predecessor(int new_predecessor);
};
struct MinHeap
{
    int pair_count;
    Triplet **vertex_distance_predecessor;

    MinHeap(int *vertices, int *distances);

    bool is_higher_priority(int index1, int index2);
    void heapify(int index);
    void build_heap();
    bool is_valid_heap(int index);
    void swap(int index1, int index2);
    Triplet *extract_min();
    void update_triplet(int vertex, int new_distance, int new_predecessor);
    void relax(int vertex, int new_distance, int new_predecessor);
    void push_up(int index);
};