#include "MinHeap.h"
#include <climits>

Triplet::Triplet(int vertex, int distance)
{
    this->vertex = vertex;
    this->distance = INT_MAX;
    this->predecessor = -1;
}

int Triplet::get_vertex()
{
    return this->vertex;
}

int Triplet::get_distance()
{
    return this->distance;
}

int Triplet::get_predecessor()
{
    return this->predecessor;
}

void Triplet::update_distance(int new_distance)
{
    this->distance = new_distance;
}

void Triplet::update_predecessor(int new_predecessor)
{
    this->predecessor = new_predecessor;
}

MinHeap::MinHeap(int *verticies, int *distances)
{
    this->pair_count = verticies[0];

    // create and store each triplet
    for (int i = 1; i <= pair_count; i++)
    {
        vertex_distance_predecessor[i] = new Triplet(verticies[i], distances[i]);
    }

    // although initially all distances will be identical, must build heap
    // since the source will be zero, and its location is unknown
    build_heap();
}

bool MinHeap::is_higher_priority(int index1, int index2)
{
    return this->vertex_distance_predecessor[index1]->get_distance() < this->vertex_distance_predecessor[index2]->get_distance();
}

void MinHeap::heapify(int index)
{
    // base case 1: the item is now a leaf node
    if (index > this->pair_count / 2)
    {
        return;
    }

    int parent_index = index;
    int left_child_index = index << 1;
    int right_child_index = (index << 1) + 1;

    bool left_child_exits = left_child_index <= this->pair_count;
    bool right_child_exits = right_child_index <= this->pair_count;

    int priority_index = parent_index;

    // compare parent with left child
    if (left_child_exits && is_higher_priority(left_child_index, parent_index))
    {
        priority_index = left_child_index;
    }
    // compare right child to the current highest priority
    if (right_child_exits && is_higher_priority(right_child_index, priority_index))
    {
        priority_index = right_child_index;
    }

    // as long as the highest priority is not the parent, swap and heapify on the item with lower priority
    if (priority_index != parent_index)
    {
        swap(parent_index, priority_index);
        heapify(priority_index);
    }
}

void MinHeap::build_heap()
{
    // only iterate through size / 2 since by definition, all leaf nodes are valid heaps
    for (int i = pair_count / 2; i > 0; i--)
    {
        heapify(i);
    }
}

bool MinHeap::is_valid_heap(int index)
{
    int parent_index = index;
    int left_child_index = index << 1;
    int right_child_index = (index << 1) + 1;

    bool left_child_exists = left_child_index <= pair_count;
    bool right_child_exists = right_child_index <= pair_count;

    // check if left subtree is a valid heap
    if (left_child_exists)
    {
        if (!is_higher_priority(parent_index, left_child_index))
            return false;

        if (!is_valid_heap(left_child_index))
            return false;
    }

    // check if right subtree is a valid heap
    if (right_child_exists)
    {
        if (!is_higher_priority(parent_index, right_child_index))
            return false;

        if (!is_valid_heap(right_child_index))
            return false;
    }

    return true;
}

void MinHeap::swap(int index1, int index2)
{
    Triplet *temp = vertex_distance_predecessor[index1];
    vertex_distance_predecessor[index1] = vertex_distance_predecessor[index2];
    vertex_distance_predecessor[index2] = temp;
}

Triplet *MinHeap::extract_min()
{
    // case 1: swap head with tail, decrement size, heapify the new head, return old head
    if (pair_count > 1)
    {
        swap(1, this->pair_count);
        this->pair_count -= 1;
        heapify(1);
        return this->vertex_distance_predecessor[pair_count + 1];
    }

    // case 2: decrement size, return head
    if (pair_count == 1)
    {
        pair_count -= 1;
        return this->vertex_distance_predecessor[pair_count + 1];
    }

    // case 3: heap is empty
    return nullptr;
}

void MinHeap::update_triplet(int vertex, int new_distance, int new_predecessor)
{
    for (int i = 1; i <= pair_count; i++)
    {
        if (vertex_distance_predecessor[i]->get_vertex() == vertex)
        {
            vertex_distance_predecessor[i]->update_distance(new_distance);
            vertex_distance_predecessor[i]->update_predecessor(new_predecessor);
            // push it up the queue if necessary
            push_up(i);
            return;
        }
    }
}

void MinHeap::push_up(int index)
{
    // base case: the item is at the top of the heap
    if (index == 1)
    {
        return;
    }
    // else, check if the node at index has higher priority than the parent
    if (is_higher_priority(index, index / 2))
    {
        // swap these elements, and call push_up on the elements new index
        swap(index, index / 2);
        push_up(index / 2);
    }
}