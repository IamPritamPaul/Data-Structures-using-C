#include <iostream>
using namespace std;

class MaxHeap
{
    int *arr;
    int max_size;
    int heap_size;

public:
    MaxHeap(int maxSize);

    void max_heapify(int);

    int parent_of(int i)
    {
        return (i - 1) / 2;
    }

    int left_child_of(int i)
    {
        return i * 2 + 1;
    }

    int right_child_of(int i)
    {
        return 2 * i + 2;
    }

    int gex_max()
    {
        return *arr;
    }

    int current_size()
    {
        return this->heap_size;
    }

    void delete_key();

    void insert_key();
};

int main()
{
}