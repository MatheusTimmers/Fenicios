#include <iostream>
using namespace std;

// Estrutura de dados para armazenar nós da lista de adjacências
struct Node
{
    int val, cost;
    Node *next;
};

// Estrutura de dados para armazenar uma aresta do gráfico
struct Edge
{
    int src, dest, weight;
};

class Graph
{
    // Função para alocar um novo nó para a lista de adjacências
    Node *getAdjListNode(int value, int weight, Node *head);
    int N; // número total de nós no gráfico

public:
    // Um array de ponteiros para Node para representar o
    // lista de adjacências
    Node **head;
    Graph(Edge edges[], int n, int N);
    ~Graph();
};
