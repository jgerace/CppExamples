#ifndef HEAP_H
#define HEAP_H


class Heap
{
    int *array;
    int size;
    int numElements;

    Heap();
    void heapify(); // constructs a valid heap
    int rootDelete(); // returns root node, deletes from heap, re-heapifies

    public:
        Heap(int *arrayIn, int size);
        void print(); // print heapified array
        int *heapsort(); // returns array of size "size" of sorted (descending) elements. user deletes returned array.
        int getNumElements();
        ~Heap();
};

#endif // HEAP_H
