#include "File.hpp"
#include "../Utils/Utils.hpp"

File::File(string name)
{
    this->_name = "./Data/" + name;
    this->OpenRead();
    this->_file.close();
}

void File::OpenRead()
{
    this->_file.open(this->_name, fstream::in);
    if (!this->_file.is_open())
    {
        cout << "Erro ao abrir arquivo";
        exit(1);
    }
}

// Usado para pegar ptimeira linha com tamanho do Map
vector<string> File::GetLine()
{
    string buffer;
    vector<string> result;
    this->OpenRead();

    // Pega a linha até o final
    getline(this->_file, buffer, '\n');

    // Separa ela em colunas de acordo com espacos em brancos
    result = split(buffer, " ");

    this->_file.close();
    return result;
}

vector<string> File::GetLines()
{
    vector<string> result;
    string line;
    this->OpenRead();

    // posiciona na linha 1, pois é quando começa o mapa
    this->_file.seekg(1);
    while (getline(this->_file, line))
    {
        result.push_back(line);
    }
    this->_file.close();
    return result;
}

int File::GetLinesAmount()
{
    int count = 0;
    string line;
    this->OpenRead();

    this->_file.seekg(0);
    while (getline(this->_file, line))
    {
        count++;
    }
    this->_file.close();
    return count;
}

void File::write(string s)
{
}