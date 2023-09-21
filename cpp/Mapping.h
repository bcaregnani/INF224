/**
 * 
 * 
 *  @brief Mapping a database of Multimedia objects or Group(s) of Multimedia objects
 * 
 * 
 * 
 **/




#ifndef MAPPING
#define MAPPING
#include "Film.h"
#include "Photo.h"
#include "Group.h"
#include <stdlib.h>
#include <map>


class Mapping
{

private :
    std::map< std::string, std::shared_ptr <Multimedia> > mapMultimedia;
	std::map< std::string, std::shared_ptr<Group> > mapGroup;

public :

Mapping(){};

std::shared_ptr<Photo> createPhoto(std::string _objectName, std::string _filePath, float _longitude, float _latitude);
std::shared_ptr<Video> createVideo(std::string _objectName, std::string _filePath, int _duration);
std::shared_ptr<Film> createFilm(std::string _objectName, std::string _filePath, int _duration, int _nbrChapters, int * _durationChapters);
std::shared_ptr<Group> createGroup(std::string _groupName);

void print(std::string const & name, std::ostream & where);
void display(std::string const & name);


};

std::shared_ptr<Photo> Mapping::createPhoto(std::string _objectName, std::string _filePath, float _longitude, float _latitude)
{
    std::shared_ptr<Photo> _photo = std::make_shared<Photo>( _objectName, _filePath, _longitude, _latitude);
    mapMultimedia[_photo->getObject()] = _photo;
    return _photo;
};

std::shared_ptr<Video> Mapping::createVideo(std::string _objectName, std::string _filePath, int _duration)
{
    std::shared_ptr<Video> _video = std::make_shared<Video>(_objectName, _filePath, _duration);
    mapMultimedia[_video->getObject()] = _video;
    return _video;
};

std::shared_ptr<Film> Mapping::createFilm(std::string _objectName, std::string _filePath, int _duration, int _nbrChapters, int * _durationChapters)
{
    std::shared_ptr<Film> _film = std::make_shared<Film>(_objectName, _filePath, _duration, _nbrChapters, _durationChapters);
    mapMultimedia[_film->getObject()] = _film;
    return _film;
};

std::shared_ptr<Group> Mapping::createGroup(std::string _groupName)
{
    std::shared_ptr<Group> _group = std::make_shared<Group>(_groupName);
    mapGroup[_group->getGroupName()] = _group;
    return _group;
};





void Mapping::print(std::string const & name, std::ostream & where)
{
    auto itGroup = mapGroup.find(name);
    auto itMultimedia = mapMultimedia.find(name);

    if ((itGroup != mapGroup.end()) & (itMultimedia != mapMultimedia.end()))
    {
        throw "Error, at least one group and one multimedia element with same name";
    };
    
    if (itGroup != mapGroup.end())
    {
        itGroup->second->print(where);
    };

    if (itMultimedia != mapMultimedia.end())
    {
        itMultimedia->second->print(where);
    };    

    if ((itGroup == mapGroup.end()) & (itMultimedia == mapMultimedia.end()) )
    {
        where << "Nothing matches the name";
    }
    
    return ;
};

void Mapping::display(std::string const & name)
{
    auto itMultimedia = mapMultimedia.find(name);

    if (itMultimedia != mapMultimedia.end())
    {
        itMultimedia->second->displayMultimedia();
    }
    else std::cout <<"Nothing matches the name"  <<std::endl;
    
    return ;
}




#endif