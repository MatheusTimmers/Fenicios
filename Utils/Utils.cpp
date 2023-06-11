#include "Utils.hpp"

vector<string> split (string str, string delimiter) 
{
    size_t pos_start = 0;
    size_t delim_len = delimiter.length();
    size_t pos_end;
    string token;
    vector<string> res;

    while ((pos_end = str.find (delimiter, pos_start)) != string::npos) 
    {
        token = str.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (str.substr (pos_start));
    return res;
}


string center(int width, const string& str) {
    int len = str.length();
    if(width < len) { return str; }

    int diff = width - len;
    int pad1 = diff/2;
    int pad2 = diff - pad1;
    return string(pad1, ' ') + str + string(pad2, ' ');
}