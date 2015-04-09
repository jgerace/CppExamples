#include <cstdlib>
#include <iostream>

using namespace std;

static const int NUM_ELEMENTS = 8;
static int list[NUM_ELEMENTS];

static void initList();
static void printList(int *list, int numElements);
static void mergeSort(int *list, int numElems);
static void merge(int *leftList, int numLeft, int *rightList, int numRight, int *origList, int numOrig);

int main(int argc, char *argv[])
{
    initList();
    printList(list, NUM_ELEMENTS);

    cout << "running merge sort" << endl;
    mergeSort(list, NUM_ELEMENTS);
    printList(list, NUM_ELEMENTS);

    return 0;
}

void mergeSort(int *origList, int numElems)
{
    if(numElems <= 1) {
        return;
    }

    // allocate space for two arrays in which we will copy the two halves of the original
    int leftListSize = numElems/2;
    int rightListSize = numElems - leftListSize;
    int *leftList = new int[leftListSize];
    int *rightList = new int[rightListSize];

    // copy the two halves of the original list into "left" and "right" arrays
    for(int ii = 0; ii < leftListSize; ii++) {
        leftList[ii] = origList[ii];
    }

    int jj = 0;
    for(int ii = leftListSize; ii < numElems; ii++, jj++) {
        rightList[jj] = origList[ii];
    }

    // recursively sort the left and right arrays
    mergeSort(leftList, leftListSize);
    mergeSort(rightList, rightListSize);

    // merge the results
    merge(leftList, leftListSize, rightList, rightListSize, origList, numElems);

    free(leftList);
    free(rightList);
}

void merge(int *leftList, int numLeft, int *rightList, int numRight, int *origList, int numOrig)
{
    int ii=0, jj=0, kk=0;

    // copy the larger number from either list into the original array
    while(ii < numLeft && jj < numRight) {
        if(leftList[ii] <= rightList[jj]) {
            origList[kk] = leftList[ii];
            ii++;
        }
        else {
            origList[kk] = rightList[jj];
            jj++;
        }
        kk++;
    }

    // whatever leftover elements we have, copy those into the original array
    if(ii == numLeft) {
        for(jj; jj < numRight; jj++, kk++) {
            origList[kk] = rightList[jj];
        }
    }
    else {
        for(ii; ii < numLeft; ii++, kk++) {
            origList[kk] = leftList[ii];
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

