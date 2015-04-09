#include <cstdlib>
#include <iostream>

using namespace std;

static const int NUM_ELEMENTS = 8;
static int list[NUM_ELEMENTS];

static void initList();
static void printList(int *list, int numElements);
static void insertionSort();

int main2(int argc, char *argv[])
{
    initList();
    printList(list, NUM_ELEMENTS);

    cout << "running insertion sort" << endl;
    insertionSort();
    printList(list, NUM_ELEMENTS);

    initList();

    return 0;
}

void insertionSort()
{
    for(int ii = 1; ii < NUM_ELEMENTS; ii++) {
        int targetNum = list[ii]; // target number we are trying to sort into correct position
        int jj = ii - 1;  // last element of the already-sorted list

        // iterate through the already-sorted list until we find where the target
        // number is supposed to live
        while(jj >= 0 && list[jj] > targetNum) {
            // move larger numbers to the next element to make room for the target num
            list[jj+1] = list[jj];
            jj--;
        }
        list[jj+1] = targetNum; // we've found a home for target num.
     }
}

void initList()
{
     list[0] = 8;
     list[1] = 4;
     list[2] = 7;
     list[3] = 3;
     list[4] = 2;
     list[5] = 6;
     list[6] = 1;
     list[7] = 5;
}

void printList(int *list, int numElements)
{
     for(int ii=0; ii < numElements; ii++) {
             cout << list[ii] << " ";
     }
     cout << endl;
}
