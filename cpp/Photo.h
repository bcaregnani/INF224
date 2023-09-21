/**
 * 
 * 
 *  Defining subclass Photo
 * 
 * 
 * 
 **/




#ifndef PHOTO
#define PHOTO
#include "Multimedia.h"
#include <iostream>
#include <stdlib.h>


class Photo : public Multimedia
{

private :
    float longitude{}, latitude{};

public :
    Photo(){};
    Photo(std::string _objectName, std::string _filePath, float _longitude, float _latitude): Multimedia(_objectName, _filePath) {longitude = _longitude; this->latitude = _latitude;};
    ~Photo(){std::cout << "Photo terminated ";};
    std::string getClassName() const override { return "Photo";};
    void writeToFile(std::ofstream& _file) override;
    void readFromFile(std::ifstream& _file) override;
    float getLongitude() const {return longitude;};
    float getLatitude() const {return latitude;};
    void setLongitude(float _longitude) {longitude = _longitude;};
    void setLatitude(float _latitude) {latitude = _latitude;};
    void print(std::ostream & where) override;
    void displayMultimedia() override;


};


void Photo::writeToFile(std::ofstream& _file)
{
    Multimedia::writeToFile(_file);
    _file << longitude << std::endl
          << latitude  << std::endl;

};

void Photo::readFromFile(std::ifstream& _file)
{

    Multimedia::readFromFile(_file);
    std::string s;
    getline(_file, s);
    setLongitude(stof(s));
    getline(_file, s);
    setLatitude(stof(s));

 
};



void Photo::print(std::ostream & where)
{
    Multimedia::print(where);
    where << "Photo's longitude: " << longitude << ", ";
    where << "Photo's latitude: " << latitude << ". ";
};

void Photo::displayMultimedia()
{
    std::string vec =  "imagej " + getFilePath() + " &";
    system( vec.data() );
};



#endif