#include "Graph.h"
#include <iostream>
#include <stack> // stl objects for simplicity
#include <queue>

using namespace std;

// does not check input
Graph::Graph(int size)
{
    this->size = size;
    edges = new int*[size];
    for(int ii = 0; ii < size; ii++) {
        edges[ii] = new int[size];
    }
}

// if you want to change to directed graph, remove multiple assignment so the use case would be
// addEdge(from, to);
void Graph::addEdge(int x, int y)
{
    edges[x][y] = 1;
    edges[y][x] = 1;
}

bool Graph::isEdge(int x, int y)
{
    return (edges[x][y] == 1);
}

// will only visit the nodes connected to node x
void Graph::depthFirstSearch(int x)
{
    bool *visited = new bool[size](); // default constructor initializes all to false

    stack<int> s;
    visited[x] = true;
    s.push(x);
    while(!s.empty()) {
        int node = s.top();
        s.pop();
        cout << node << " ";
        for(int ii = 0; ii < size; ii++) {
            if(isEdge(node, ii) && !visited[ii]) {
                s.push(ii);
                visited[ii] = true;
            }
        }
    }
    cout << endl;
    // one could, at this point, look at all elements of 'visited' to see if graph is connected
    delete [] visited;
}

// same as depth first search, except implemented with a queue
void Graph::breadthFirstSearch(int x)
{
    bool *visited = new bool[size](); // default constructor initializes all to false

    queue<int> q;
    visited[x] = true;
    q.push(x);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int ii = 0; ii < size; ii++) {
            if(isEdge(node, ii) && !visited[ii]) {
                q.push(ii);
                visited[ii] = true;
            }
        }
    }
    cout << endl;
    // one could, at this point, look at all elements of 'visited' to see if graph is connected
    delete [] visited;
}

Graph::~Graph()
{
    for(int ii = 0; ii < size; ii++) {
        delete[] edges[ii];
    }
    delete[] edges;
}
