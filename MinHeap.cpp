#include "MinHeap.h"

MinHeap::MinHeap(int *input_nodes)
{
    // size of input is stored at input_nodes[0]
    int size_of_input = input_nodes[0];
    // will also store the current size of the heap at heap[0]
    this->heap = new int[size_of_input + 1];
}

bool MinHeap::is_higher_priority(int index1, int index2)
{
    return this->heap[index1] < this->heap[index2];
}

void MinHeap::heapify(int index)
{
    // base case 1: the item is now a leaf node
    if (index > this->heap[0] / 2)
    {
        return;
    }

    int parent_index = index;
    int left_child_index = index << 1;
    int right_child_index = (index << 1) + 1;

    bool left_child_exits = left_child_index <= this->heap[0];
    bool right_child_exits = right_child_index <= this->heap[0];

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

bool MinHeap::is_valid_heap(int index)
{
    int parent_index = index;
    int left_child_index = index << 1;
    int right_child_index = (index << 1) + 1;

    bool left_child_exists = left_child_index <= current_size;
    bool right_child_exists = right_child_index <= current_size;

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
    int temp = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = temp;
}

int MinHeap::extract_min()
{
    // case 1: swap head with tail, decrement size, heapify the new head, return old head
    if (this->heap[0] > 1)
    {
        swap(1, this->heap[0]);
        this->heap[0] -= 1;
        heapify(1);
        return this->heap[this->heap[0] + 1];
    }

    // case 2: decrement size, return head
    if (current_size == 1)
    {
        this->heap[0] -= 1;
        return heap[this->heap[0] + 1];
    }

    // case 3: heap is empty
    return -1;
}