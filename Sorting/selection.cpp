#include <cstdlib>
#include <iostream>

using namespace std;

static const int NUM_ELEMENTS = 8;
static int list[NUM_ELEMENTS];

static void initList();
static void printList(int *list, int numElements);
static void selectionSort();

int main(int argc, char *argv[])
{
    initList();
    printList(list, NUM_ELEMENTS);

    cout << "running selection sort" << endl;
    selectionSort();
    printList(list, NUM_ELEMENTS);

    initList();

    return 0;
}

void selectionSort()
{
    for(int ii = 0; ii < NUM_ELEMENTS-1; ii++) {
        int min = ii;
        for(int jj = ii+1; jj < NUM_ELEMENTS; jj++) {
            if(list[jj] < list[min]) {
                min = jj;
            }
        }
        int temp = list[ii];
        list[ii] = list[min];
        list[min] = temp;
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

