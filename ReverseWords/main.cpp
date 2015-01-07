#include <iostream>
#include <cstring>

using namespace std;

// reverse portion of a string between indexes start and end in place
void reverseString(char *str, int start, int end) {
    int ii = start;
    int jj = end;
    while(ii < jj) {
        char temp = str[ii];
        str[ii] = str[jj];
        str[jj] = temp;

        ii++; jj--;
    }
}

// reverse words in place - delimiter = ' '
// assume input is valid c string
// won't trim white space
void reverseWords(char *str)
{
    // reverse entire string
    reverseString(str, 0, strlen(str)-1);

    // reverse individual words
    int ii, jj;
    ii = jj = 0;
    while(1) {
        // find beginning of token
        while(str[ii] == ' ') {
            ii++;
        }

        if(str[ii] == '\0') {
            break;
        }

        // find end of token
        jj = ii;
        while(str[jj] != ' ' && str[jj] != '\0') {
            jj++;
        }
        int end = jj;
        jj--;

        // reverse the word
        reverseString(str, ii, jj);

        // advance pointer past end of token
        ii = end;
    }
}

int main()
{
    char str[51];
    strcpy(str, "Reverse these words!");
    //strcpy(str, "Odd number of chars");
    //strcpy(str, "");
    //strcpy(str, " ");

    reverseWords(str);

    cout << str << endl;

    return 0;
}
