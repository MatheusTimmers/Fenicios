#include <iostream>
using namespace std;

struct Edge
{
    int weight;
    Node *node;
};

struct Node
{
    Edge *left, *right, *top, *bottom;
};

class Graph
{

private:
    Edge **_edge;
    int _size;

public:
    Edge *getEdge(int index);
    int dijkstra(int startIndex, int endIndex);
    Graph(Edge *edges[], int size);
};
