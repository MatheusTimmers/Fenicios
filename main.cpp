#include "File/File.hpp"
#include <time.h>
#include <iomanip>
#include "Boat/Boat.hpp"
#include "Map/Map.hpp"
#include "Utils/Utils.hpp"
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
    Map *map = new Map(stoi(infoLine[1]), stoi(infoLine[0]), &stringMap);
    map->SearchBoat(&x, &y);

    // Boat TODO: Não precisa mais
    Boat *boat = new Boat(x, y);

    // Controller
    Navigation *nav = new Navigation(map->ToGraph(), boat);

    // Como o trabalho foi feito com uma lista de adjacencias, tranforma a pos x e y para um array Unidimensional
    // Caronte o barqueiro de Hades
    // TODO: Passar o nome Caronte ao inves de Navigation, e essa função colocar outro como pathfinding ou algo do tipo
    nav->Caronte(GetListPos(x, y, map->GetSizeX()));

    // Reverte a lista para pegar o caminho partindo da pos do barco
    // FIXME: Por algum motivo além da minha compreensão, isso aqui está quebrando o código 
    //reverse(nav->GetParent()->begin(), nav->GetParent()->end());

    // Printa o resultado
    // TODO: Passar para uma função 
    // TODO: Arrumar o index do Map/Graph, pensar se é melhor começar em 0 ou em 1
    // TODO: Fazer agora mostrar para cada porto, ele já pega o caminho só falta o print 
    cout << "O Vertex " << 5 << " esta " << nav->GetDist(5) << " de distancia do " << GetListPos(x + 1, y, map->GetSizeX()) << endl;
    int aux = 1.014;
    cout << "Menor Caminho --> (";
    
    // TODO: Fazer com que se não tiver como chegar avisar
    while (nav->GetParent(aux) + 1 != GetListPos(x + 1, y, map->GetSizeX()))
    {
        cout << nav->GetParent(aux);
        aux = nav->GetParent(aux);
        if (nav->GetParent(aux) + 1 != GetListPos(x + 1, y, map->GetSizeX())) cout << ", "; 
    }
    cout << ") " << endl;

    // End Timer
    end = clock();
    double elapsed = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Tempo Total: " << fixed << elapsed << setprecision(5) << endl;

    // Gostou sor, agora temos consciência de memoria (Já tinhamos que ter :P) 
    delete file;
    delete map;

    return 0;
}
