#ifndef UTILS
#define UTILS
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string str, string delimiter);

void quickSort(vector<pair<int, int>> &arr, int low, int high);

string center(int width, const string &str);
#endif