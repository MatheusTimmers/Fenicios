#include <iostream>
#include "Graph.hpp"
using namespace std;

// Função para alocar um novo nó para a lista de adjacências
Node *Graph::getAdjListNode(int value, int weight, Node *head)
{
    Node *newNode = new Node;
    newNode->val = value;
    newNode->cost = weight;

    // aponta novo nó para a cabeça atual
    newNode->next = head;

    return newNode;
}

// Construtor
Graph::Graph(Edge edges[], int n, int N)
{
    // aloca memoria
    head = new Node *[N]();
    this->N = N;

    // inicializa o ponteiro de cabeça para todos os vértices
    for (int i = 0; i < N; i++)
    {
        head[i] = nullptr;
    }

    // adiciona arestas ao grafo direcionado
    for (unsigned i = 0; i < n; i++)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;

        // insere no início
        Node *newNode = getAdjListNode(dest, weight, head[src]);

        // aponta o ponteiro principal para o novo nó
        head[src] = newNode;

        // descomente o seguinte código para gráfico não direcionado

        /*
        newNode = getAdjListNode(src, weight, head[dest]);

        // altera o ponteiro de cabeça para apontar para o novo nó
        head[dest] = newNode;
        */
    }
}

// Destruidor
Graph::~Graph()
{
    for (int i = 0; i < N; i++)
    {
        delete[] head[i];
    }

    delete[] head;
}
