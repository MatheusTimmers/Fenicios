#include "Graph.hpp"
#include <iostream>
#include <queue>
using namespace std;

// Constructor
Graph::Graph(int vertexes)
{
    size = vertexes;
    this->adjacencyList.resize(vertexes);
}

// Add an edge to the graph
void Graph::addEdge(int source, int destination, char destinationValue)
{
    // std::cout << "(" << source << ", " << destination << ", " << destinationValue << ") " << endl;
    Edge edge = {source, destination, destinationValue};
    adjacencyList[source].push_back(edge);
}

vector<Edge> Graph::getEdges(int vertex)
{

    if (vertex < size)
    {
        return this->adjacencyList.at(vertex);
    }

    return vector<Edge>();
}

// Print the graph
void Graph::printGraph()
{

    for (int i = 0; i < this->size; i++)
    {
        std::cout << "Vertex " << i << " --> ";

        for (const Edge &edge : this->adjacencyList.at(i))
        {
            std::cout << "(" << edge.destination << ", " << edge.destinationValue << ") ";

            std::cout << endl;
        }
        std::cout << endl;
    }
}

vector<int> Graph::shortestPath(int src, int dest)
{
    vector<int> path;
    vector<int> pred(size);
    vector<int> dist(size);
    // a queue to maintain queue of vertices whose
    // adjacency list is to be scanned as per normal
    // DFS algorithm
    queue<int> q;

    // boolean array visited[] which stores the
    // information whether ith vertex is reached
    // at least once in the Breadth first search
    vector<bool> visited(size);

    // initially all vertices are unvisited
    // so v[i] for all i is false
    // and as no path is yet constructed
    // dist[i] for all i set to infinity
    for (int i = 0; i < size; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    // now source is first to be visited and
    // distance from source to itself should be 0
    visited[src] = true;
    dist[src] = 0;
    q.push(src);

    // standard BFS algorithm
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < this->adjacencyList[u].size(); i++)
        {
            int destination = getEdges(u)[i].destination;
            if (visited[destination] == false)
            {
                // std::cout << "Visiting - " << u << "->" << destination << endl;
                visited[destination] = true;
                dist[destination] = dist[u] + 1;
                pred[destination] = u;
                q.push(destination);

                // We stop BFS when we find
                // destination.
                if (destination == dest)
                {
                    int crawl = dest;
                    path.push_back(crawl);
                    while (pred[crawl] != -1)
                    {
                        path.push_back(pred[crawl]);
                        crawl = pred[crawl];
                    }
                    return path;
                }
            }
        }
    }

    return path;
}