#include <iostream>

/*
Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

using namespace std;

int p2_main(int argc, char **argv)
{
    int sum = 2;
    int a = 1, b = 2;
    int fibNum = 0;

    while(fibNum < 4000000) {
        fibNum = a + b;
        if(fibNum % 2 == 0) {
            sum += fibNum;
        }
        a = b;
        b = fibNum;
    }

    cout << sum << endl;

    return 0;
}

