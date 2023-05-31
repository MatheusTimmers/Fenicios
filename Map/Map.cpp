#include "Map.hpp"
using namespace std;
Map::Map(int size_x, int size_y, vector<string> *map)
{
    this->_size_x = size_x;
    this->_size_y = size_y;
    this->_map = map;
}

void Map::SearchBoat(int *x, int *y)
{
    for (int i = 1; i < this->_size_x; i++)
    {
        for (int j = 1; j < this->_size_y; j++)
        {
            // Procura o primeiro porto do Mapa;
            if (this->_map->at(i)[j] == '1')
            {
                *x = i;
                *y = j;
                cout << "Posicao do barquinho eh " << *x << " e " << *y << endl;
                return;
            }
        }
    }
}

void Map::CreateMap(vector<string> *map)
{
}

Graph *Map::ToGraph()
{
    int generalIndex = 0;
    int totalSize = this->_size_x * this->_size_y;
    Edge edges[totalSize * 4];
    //     =
    // {
    //     // (x, y, w) —> aresta de `x` a `y` tendo peso `w`
    //     {0, 1, 6}, {1, 2, 7}, {2, 0, 5}, {2, 1, 4}, {3, 2, 10}, {4, 5, 1}, {5, 4, 3}
    // };

    cout << "ToGraph" << endl;
    for (int i = 0; i <= this->_size_x; i++)
    {
        for (int j = 0; j <= this->_size_y; j++)
        {
            //@MatheusTimmers te vira pra entender
            // vou tentar
            // @GabiHert, não acredito que tu criou uma classe para o graph, vagabundo
            // copiei da internet
            // beleza, tava vendo, acho que realmente é necessario mesmo
            // man na real eu acho q n vai dar certo essa merda
            // Eu tava fazendo q cada ponto do mapa era um nodo do grafo. Dai se for terra tem peso infinito, se for agua ou porto tem peso 1. Ai depois fazemos o caminhento la da aula passada pra calcular o menor caminho de um porto ate o outro
            // tendi, faz sentido boa

            int weight = this->_map->at(i)[j] == '*' ? 100 : 1;
            if (generalIndex == totalSize)
            {
                break;
            }

            if (generalIndex > this->_size_x)
            {
                // todo: atribui edge ao nodo de cima
                edges[generalIndex] = {generalIndex, generalIndex - this->_size_x};
            }

            if (generalIndex % this->_size_x)
            {
                // todo: atribui edge da direita
                edges[generalIndex + 1] = {generalIndex, generalIndex + 1};
            }

            if ((generalIndex - 1) % this->_size_x)
            {
                edges[generalIndex - 1] = {generalIndex, generalIndex - 1};
            }
            edges[i * j] = {generalIndex, 0, 0};

            generalIndex++;
        }
        cout << endl;
    }

    return NULL;
}
