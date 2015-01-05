#include "Heap.h"
#include <iostream>

using namespace std;

// no input validation - you could throw an exception for invalid input
Heap::Heap(int *arrayIn, int numElements)
{
    size = numElements+1;
    array = new int[numElements+1];
    this->numElements = numElements;

    for(int ii = 0; ii < numElements; ii++) {
        array[ii+1] = arrayIn[ii];
    }

    heapify();
}

// bottom up
void Heap::heapify()
{
    for(int ii = (numElements)/2; ii > 0; ii--) {
        int rootIdx = ii;
        while(2*rootIdx <= numElements) {

            // pick largest child
            int childL = 2 * rootIdx;
            int largerChild = childL;
            if(childL < numElements) {
                // there are 2 children
                int childR = childL + 1;
                if(array[childL] < array[childR]) {
                    largerChild = childR;
                }
            }

            // if the larger child is larger than the parent node, swap
            if(array[largerChild] > array[rootIdx]) {
                int temp = array[largerChild];
                array[largerChild] = array[rootIdx];
                array[rootIdx] = temp;

                // ensure the parental dominance requirement for heap under new child node
                rootIdx = largerChild;
            }
            else {
                break;
            }
        }
    }
}

int *Heap::heapsort()
{
    // save our original heap so we can restore it after sorting since rootDelete() destroys the heap
    int *temp = new int[size];
    for(int ii = 0; ii < size; ii++) {
        temp[ii] = array[ii];
    }
    int numEls = numElements; // for later when we "resize" the heap back to what it was before sorting

    // heapsort
    int *a = new int[numElements];

    for(int ii = 0; ii < numEls; ii++) {
        a[ii] = rootDelete();
    }

    // restore heap
    for(int ii = 0; ii < size; ii++) {
        array[ii] = temp[ii];
    }
    numElements = numEls; // resize heap so it doesn't look all deleted

    return a;
}

int Heap::rootDelete()
{
    int temp = array[1]; // root
    array[1] = array[numElements];
    array[numElements] = temp;

    numElements--;

    heapify();

    return temp;
}

void Heap::print()
{
    // note heap starts at index 1
    for(int ii = 1; ii <= numElements; ii++) {
        cout << array[ii] << " ";
    }
}

int Heap::getNumElements()
{
    return numElements;
}

Heap::~Heap()
{
    delete[] array;
}
