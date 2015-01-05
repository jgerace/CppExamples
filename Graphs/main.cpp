#include <iostream>
#include "Graph.h"

using namespace std;

/* graph looks something like this:
*        0
*      / | \
*     1  2   3
*      /   \   \
*     4     5   6
*     |   / | \
*     7  8  9 10
*/

int main()
{
    Graph g(11);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 6);
    g.addEdge(4, 7);
    g.addEdge(5, 8);
    g.addEdge(5, 9);
    g.addEdge(5, 10);

    g.depthFirstSearch(0);
    g.breadthFirstSearch(0);

    return 0;
}
