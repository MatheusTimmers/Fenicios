#ifndef _FILE_HPP_
#define _FILE_HPP_
#include <fstream>

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class File
{
private:
    string _name;
    fstream _file;
    void OpenRead();

public:
    File(string name);
    vector<string> GetLine();
    vector<string> GetLines();
    int GetLinesAmount();
};

#endif
