#include "File/File.hpp"
#include <time.h>


int main()
{
    clock_t start, end;
    vector<string> infoLine;
    
    start = clock();

    File *file = new File("case0.map");
    infoLine = file->GetLine();

    char map[stoi(infoLine[0])][stoi(infoLine[1])];



    end = clock();
    double elapsed = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Tempo Total: " << fixed << elapsed << setprecision(5) << endl;

    return 0;
}
