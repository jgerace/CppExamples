#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

// where delim is string of delimiters
bool isDelim(char c, const char *delim)
{
    while(*delim != '\0') {
        if(c == *delim) {
            return true;
        }
        delim++;
    }

    return false;
}

// clone of strtok()
char *tokenize(char *str, const char *delim) {
    static char *ptr;
    static bool isEnd = false;

    if(str != NULL) {
        ptr = str;
    }

    // find first non-delim char
    while(isDelim(*ptr, delim)) {
        ptr++;
    }

    if(*ptr == '\0' || isEnd) {
        return NULL;
    }

    char *start = ptr;

    // find the end of the token
    int ii = 0;
    while(*ptr != '\0' && !isDelim(*ptr, delim)) {
        ptr++; ii++;
    }

    // we've come to the end of the string. return NULL for any call after this. see above.
    if(*ptr == '\0') {
        isEnd = true;
    }
    *ptr = '\0';
    ptr++;

    return start;
}

int main()
{
    char str[51];
    //strcpy(str, "I want to tokenize this string.");
    //strcpy(str, "");
    //strcpy(str, "I  want to tokenize this string.");
    //strcpy(str, "I want to tokenize this string. ");
    //strcpy(str, " I want to tokenize this string.");
    strcpy(str, "   ");
    char *delim = " ";

    char *tok = tokenize(str, delim);
    while(tok != NULL) {
        cout << "token: " << tok << endl;
        tok = tokenize(NULL, delim);
    }

    return 0;
}
