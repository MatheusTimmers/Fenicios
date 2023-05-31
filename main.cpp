#include "File/File.hpp"
#include <time.h>
#include <iomanip>
#include "Boat/Boat.hpp"
#include "Map/Map.hpp"
#include "Controller/Navigation.hpp"

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
    File *file = new File("case0.map");
    infoLine = file->GetLine();
    stringMap = file->GetLines();

    // Map
    Map *map = new Map(stoi(infoLine[0]), stoi(infoLine[1]), &stringMap);
    map->SearchBoat(&x, &y);
    map->ToGraph();

    // Boat
    Boat *boat = new Boat(x, y);

    // Controller
    // Navigation *nav = new Navigation(map, boat);

    // End Timer
    end = clock();
    double elapsed = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Tempo Total: " << fixed << elapsed << setprecision(5) << endl;

    return 0;
}
