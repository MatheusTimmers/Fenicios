#include "File/File.hpp"
#include <time.h>
#include <iomanip>
#include "Boat/Boat.hpp"
#include "Map/Map.hpp"
#include "Controller/Navigation.hpp"
#include <queue>

void print(vector<pair<int, int>> edges)
{
    for (int i = 0; i < edges.size(); i++)
    {

        std::cout << " - number: " << edges.at(i).first << ", index:  " << edges.at(i).second << endl;
    }

    std::cout << endl;
}

int main()
{
    // Timer
    clock_t start, end;
    start = clock();

    // Init
    vector<string> infoLine;
    int x = 0;
    int y = 0;
    vector<string> stringMap;

    // Pega o Arquivo
    File *file = new File("case1.map");
    infoLine = file->GetLine();
    stringMap = file->GetLines();

    // Map
    Map *map = new Map(stoi(infoLine[0]), stoi(infoLine[1]), &stringMap);
    vector<pair<int, int>> q = map->search();
    q.push_back(make_pair(q.at(0).first, q.at(0).second));
    Graph *g = map->ToGraph();
    vector<int> path;
    for (int i = 0; i < (q.size() - 1); i++)
    {

        // cout << "Caminho porto " << q.at(i).first << " para porto " << q.at(i + 1).first << endl;

        vector<int> p = g->shortestPath(q.at(i).second, q.at(i + 1).second);
        if (p.size())
        {
            for (int j = p.size() - 1; j >= 0; j--)
            {
                // cout << p.at(j) << " ";
                path.push_back(p.at(j));
            }
        }
        else
        {
            // cout << "Não é possível alcançar este porto." << endl;
        }
        // cout << endl
        //      << endl;
    }

    cout << "Combustível necessário para a jornada: " << path.size() << endl;

    // End Timer
    end = clock();
    double elapsed = double(end - start) / double(CLOCKS_PER_SEC);

    std::cout << endl;
    std::cout << "Tempo de processamento: " << fixed << elapsed << setprecision(5) << endl;

    // for (int j = 0; j < path.size(); j++)
    // {
    //     cout << " " << path.at(j);
    // }

    cout << endl;

    // int generalIndex = 0;
    // for (int y = 1; y < stringMap.size(); y++)
    // {
    //     for (int x = 0; x < stringMap.at(y).size(); x++)
    //     {
    //         bool included = false;
    //         for (int i = 0; i < path.size(); i++)
    //         {
    //             if (path.at(i) == generalIndex)
    //             {
    //                 included = true;
    //             }
    //         }

    //         if (included)
    //         {
    //             if (atoi(string(1, stringMap.at(y).at(x)).c_str()))
    //             {
    //                 cout << stringMap.at(y).at(x);
    //             }
    //             else
    //             {
    //                 cout << ">";
    //             }
    //         }
    //         else
    //         {
    //             cout << stringMap.at(y).at(x);
    //         }

    //         generalIndex++;
    //     }
    //     cout << endl;
    // }

    return 0;
}
