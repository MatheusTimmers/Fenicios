#include "Graph.hpp"

// Constructor
Graph::Graph(int vertexes)
{
    size = vertexes;
    this->adjacencyList.resize(vertexes);
}

// Adiciona edge ao grafo
void Graph::addEdge(int source, int destination, char destinationValue)
{
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

// Printa o grafo
void Graph::printGraph()
{
    for (int i = 0; i < this->size; i++)
    {
        cout << "Vertex " << i << " --> ";

        for (const Edge &edge : this->adjacencyList.at(i))
        {
            cout << "(" << edge.destination << ", " << edge.destinationValue << ") ";

            cout << endl;
        }
        cout << endl;
    }
}

vector<int> Graph::shortestPath(int src, int dest)
{
    vector<int> path;
    vector<int> pred(size);
    vector<int> dist(size);
    // uma fila para manter os vértices cuja
    // lista de adjacência deve ser verificada conforme o
    // algoritmo DFS normal
    queue<int> q;

    // vetor booleano visited[], que armazena a
    // informação se o vértice i foi alcançado
    // pelo menos uma vez na busca em largura
    vector<bool> visited(size);

    // inicialmente todos os vértices são não visitados
    // então v[i] para todos os i é false
    // e como nenhum caminho foi construído ainda
    // dist[i] para todos os i é definido como infinito
    for (int i = 0; i < size; i++)
    {
        visited[i] = false;
        dist[i] = MAX;
        pred[i] = -1;
    }

    // agora a origem é o primeiro a ser visitado e
    // a distância da origem para ela mesma deve ser 0
    visited[src] = true;
    dist[src] = 0;
    q.push(src);

    // algoritmo BFS padrão
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < this->adjacencyList[u].size(); i++)
        {
            int destination = getEdges(u)[i].destination;
            if (visited[destination] == false)
            {
                // cout << "Visitando - " << u << "->" << destination << endl;
                visited[destination] = true;
                dist[destination] = dist[u] + 1;
                pred[destination] = u;
                q.push(destination);

                // Paramos o BFS quando encontramos
                // o destination.
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