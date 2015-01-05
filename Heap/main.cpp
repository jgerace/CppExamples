#include <iostream>
#include "Heap.h"

using namespace std;

int main()
{
    int array[] = {1, 2, 3, 5, 4, 6, 7, 8, 9, 10};

    Heap h(array, sizeof(array)/sizeof(int));

    // show heapified array
    h.print();
    cout << endl;

    int *a = h.heapsort();

    // print sorted heap
    for(int ii = 0; ii < h.getNumElements(); ii ++) {
        cout << a[ii] << " ";
    }
    cout << endl;

    // show restored heap
    h.print();

    // cleanup
    delete [] a;

    return 0;
}
