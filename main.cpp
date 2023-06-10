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
    File *file = new File("caseTest.map");
    infoLine = file->GetLine();
    stringMap = file->GetLines();

    // Map
    Map *map = new Map(stoi(infoLine[0]), stoi(infoLine[1]), &stringMap);
    vector<pair<int, int>> q = map->search();
    print(q);
    Graph *g = map->ToGraph();

    vector<int> path;
    for (int i = 0; i < (q.size() - 1); i++)
    {
        // cout << "index " << q.at(i).second << " to " << q.at(i + 1).second << endl;
        // cout << "number " << q.at(i).first << " to " << q.at(i + 1).first << endl;

        vector<int> p = g->shortestPath(q.at(i).second, q.at(i + 1).second);
        for (int j = 0; j < p.size(); j++)
        {
            // cout << p.at(j) << endl;
            path.push_back(p.at(j));
        }
        cout << endl;
    }
    for (int j = (path.size() - 1); j >= 0; j--)
    {
        cout << " " << path.at(j);
    }
    cout << endl;

    // End Timer
    end = clock();
    double elapsed = double(end - start) / double(CLOCKS_PER_SEC);

    std::cout << "Tempo Total: " << fixed << elapsed << setprecision(5) << endl;

    return 0;
}
