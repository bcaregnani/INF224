/**
 * 
 * 
 *  Defining class Factory
 * 
 * 
 * 
 **/




#ifndef FACTORY
#define FACTORY
#include "Photo.h"
#include "Film.h"



class Factory
{

public :
    static std::shared_ptr<Multimedia> createMultimedia(std::string _objectName); // Object factory method

};


static std::shared_ptr<Multimedia> createMultimedia(std::string _objectName)
{


    if (_objectName == "Photo")
    {
        return std::make_shared<Photo>();
    };

    if (_objectName == "Video")
    {
        return std::make_shared<Video>();
    };
    
    if (_objectName == "Film")
    {
        return std::make_shared<Film>();
    };

    return nullptr;
    
};



#endif