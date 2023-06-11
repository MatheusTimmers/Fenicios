#ifndef UTILS
#define UTILS
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split (string str, string delimiter);
int GetListPos(int x, int y, int size_x);
string center(int width, const string& str);
#endif