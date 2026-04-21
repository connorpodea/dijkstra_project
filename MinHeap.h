struct MinHeap
{
    int *heap;
    int current_size;

    MinHeap(int *nodes);

    bool is_higher_priority(int index1, int index2);
    void heapify(int index);
    bool is_valid_heap(int index);
    void swap(int index1, int index2);
    int extract_min();
};