#include "Map.hpp"

using namespace std;
#ifndef MAP
#define MAP

// Construtor 
Map::Map(int size_x, int size_y, vector<string> *map)
{
    this->_size_x = size_x;
    this->_size_y = size_y;
    this->_map = map;
}

// TODO: Verificar se ta certo, pelo que eu encontrei na net, vector<string> já faz destructor sozinho
Map::~Map()
{
    delete this->_map;
}

// Procura o Barco dentro do mapa
void Map::SearchBoat(int *x, int *y)
{
    for (int i = 0; i < this->_size_x; i++)
    {
        for (int j = 0; j < this->_size_y; j++)
        {
            // Procura o primeiro porto do Mapa;
            if (this->_map->at(j)[i] == '1')
            {
                // +1, pois vetores começam em 0
                *x = i + 1;
                *y = j;
                cout << "Posicao do barquinho eh " << *x << " e " << *y << endl;
                return;
            }
        }
    }
}

int Map::IsWater(int x, int y)
{
    if (this->_map->at(y)[x] == '.')
        return 1;
    
    // FIXME: Acho que isso aqui não ta certo
    return (int)INFINITY;
}

WeightedGraph *Map::ToGraph()
{
    int total = this->_size_x * this->_size_y;
    int aux_x = 0;
    int aux_y = 0;
    WeightedGraph *graph = new WeightedGraph(total);
    for (int i = 0; i < total; i++)
    {
        // Se o i não for o ultimo nodo, adiciona o próximo
        if (i+1 <= total)
            graph->InsertArc(i, i+1);
         
        // Se o i não for o primeiro nodo, adiciona o anterior
        if (i-1 >= 0)
            graph->InsertArc(i, i-1);
        
        // Se o i não for da primeira linha, adiciona o de cima
        if (i - this->_size_x >= 0)
            graph->InsertArc(i, i - this->_size_x);
        
        // Se o i não for da ultima linha, adiciona o de baixo
        if (i + this->_size_x <= total)
            graph->InsertArc(i, i + this->_size_x);

        graph->AddWeight(i, this->IsWater(aux_x, aux_y));

        // TODO: Achar uma forma melhor
        aux_x++;
        if (aux_x == this->_size_x)
        {
            aux_x = 0;
            aux_y++;
        }
    }
    graph->printGraph();
    return graph;
}
#endif