#include <cstdlib>
#include <iostream>

using namespace std;

static const int NUM_ELEMENTS = 8;
static int list[NUM_ELEMENTS];

static void initList();
static void printList(int *list, int numElements);
static void bubbleSort();

int main(int argc, char *argv[])
{
    initList();
    printList(list, NUM_ELEMENTS);

    cout << "running bubble sort" << endl;
    bubbleSort();
    printList(list, NUM_ELEMENTS);

    initList();

    return 0;
}

void bubbleSort()
{
    for(int ii = 0; ii < NUM_ELEMENTS-2; ii++) {
        for(int jj = 0; jj < NUM_ELEMENTS-1-ii; jj++) {
            if(list[jj+1] < list[jj]) {
                int temp = list[jj];
                list[jj] = list[jj+1];
                list[jj+1] = temp;
            }
        }
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

