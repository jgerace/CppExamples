#ifndef GRAPH_H
#define GRAPH_H

// undirected graph
class Graph
{
    public:
        Graph(int size);
        void addEdge(int x, int y); // use 0 indexing to reference nodes
        bool isEdge(int x, int y); // returns true if x -> y is a valid edge
        void depthFirstSearch(int x); // where x is starting node
        void breadthFirstSearch(int x); // where x is starting node
        ~Graph();

    private:
        Graph();

        int size;
        int **edges;
};

#endif // GRAPH_H
