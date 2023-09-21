#include"Multimedia.h"
using namespace std;

Multimedia::Multimedia(){}


Multimedia::Multimedia(string _objectName, string _filePath)
{
    objectName = _objectName;
    filePath = _filePath;
}


Multimedia::~Multimedia(){}


void Multimedia::writeToFile(std::ofstream& _file)
{
    _file << std::endl
          << objectName << endl
          << filePath   << endl;
}

void Multimedia::readFromFile(std::ifstream& _file)
{

    std::string s;
    getline(_file, s);
    setObject(s);
    getline(_file, s);
    setFilePath(s);

};



string Multimedia::getObject() const
{
    return objectName;
}


string Multimedia::getFilePath() const
{
    return filePath;
}


void Multimedia::setObject(string objName)
{
    objectName = objName;
}

void Multimedia::setFilePath(string fPath)
{
    filePath = fPath;
}

void Multimedia::print(ostream & where)
{
    where << "Object's name: " << objectName << ", ";
    where << "Object's path: " << filePath << ", ";
}
