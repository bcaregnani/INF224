/**
 * 
 * 
 *  Defining subclass Video
 * 
 * 
 * 
 **/




#ifndef VIDEO
#define VIDEO
#include "Multimedia.h"
#include <stdlib.h>


class Video : public Multimedia
{

private :
    int duration{};

public :
    Video(){};
    Video(std::string _objectName, std::string _filePath, int _duration): Multimedia(_objectName, _filePath) {duration = _duration;};
    virtual ~Video(){std::cout << "Video terminated ";};
    std::string getClassName() const override { return "Video";};
    void writeToFile(std::ofstream& _file) override;
    void readFromFile(std::ifstream& _file) override;
    float getDuration() const {return duration;};
    void setDuration(int _duration) {duration = _duration;};
    void print(std::ostream & where) override;
    void displayMultimedia() override;


};

void Video::writeToFile(std::ofstream& _file)
{
    Multimedia::writeToFile(_file);
    _file << duration << std::endl;
};

void Video::readFromFile(std::ifstream& _file)
{
    Multimedia::readFromFile(_file);
    std::string s;
    getline(_file, s);
    setDuration( stoi(s)) ;
};


void Video::print(std::ostream & where)
{
    Multimedia::print(where);
    where << "Video's duration: " << duration << "s" << ". ";
};

void Video::displayMultimedia()
{
    std::string vec =  "mpv " + getFilePath() + " &";
    system( vec.data() );
};



#endif