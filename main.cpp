#include "File/File.hpp"
#include <time.h>
#include "Barco/Barco.hpp"
#include "Map/Map.hpp"


int main()
{
    // Timer
    clock_t start, end;
    start = clock();
 
    File *file = new File("case0.map");
    infoLine = file->GetLine();
 
    vector<string> infoLine;
    Map *map = new Map(stoi(infoLine[0]),stoi(infoLine[1]));
    

    

    end = clock();
    double elapsed = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Tempo Total: " << fixed << elapsed << setprecision(5) << endl;

    return 0;
}
