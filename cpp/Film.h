/**
 * 
 * 
 *  Defining subclass Film
 * 
 * 
 * 
 **/




#ifndef FILM
#define FILM
#include "Video.h"
#include <stdlib.h>


class Film : public Video
{

    private:
    int nbrChapters{};
    int *durationChapters=nullptr;

    public:
    Film(){};
    Film(std::string _objectName, std::string _filePath, int _duration, int _nbrChapters, int * _durationChapters): 
        Video(_objectName, _filePath, _duration) {setChapters(_nbrChapters, _durationChapters);};
    ~Film(){delete [] durationChapters; std::cout << "Film terminated ";};
    std::string getClassName() const override { return "Film";};
    void writeToFile(std::ofstream& _file) override;
    void readFromFile(std::ifstream& _file) override;
    Film(const Film& from);
    Film& operator=(const Film& from);

    int getnbrChapters() const {return nbrChapters;};
    const int * getdurationChapters() const {return durationChapters;};
    void setChapters(int _nbrChapters, const int * _durationChapters);
    void print(std::ostream & where) override;


};


void Film::writeToFile(std::ofstream& _file)
{
    Video::writeToFile(_file);
    _file << nbrChapters << std::endl;
    for (int i = 0; i < nbrChapters; i++) 
    {
        _file << durationChapters[i];
        if (i != nbrChapters-1)
        {
            _file << std::endl;
        };
        
        
    };

};

void Film::readFromFile(std::ifstream& _file)
{
    Video::readFromFile(_file);
    std::string s;
    getline(_file, s);
    int nbr = stoi(s);
    int * _durationChapters = new int[nbr];
    for (int i = 0; i < nbrChapters; i++) 
    {
        getline(_file, s);
        _durationChapters[i] = stoi(s);
    };
    setChapters(nbr, _durationChapters);
    delete _durationChapters;
};





Film::Film(const Film& from): Video(from)
{
    nbrChapters = from.nbrChapters;
    if (from.durationChapters)
    {
        durationChapters =  new int[from.nbrChapters];
        for (int i = 0; i < nbrChapters; i++) 
        {
            durationChapters[i] = from.durationChapters[i];
        };
    }
    else
    {
        durationChapters = nullptr;
    };
    
};


Film& Film::operator=(const Film& film) {
	
	Video::operator=(film);
	nbrChapters = film.nbrChapters;
	delete [] durationChapters;
	durationChapters = new int[nbrChapters];
	for (int i = 0; i < nbrChapters; i++) {
		durationChapters[i] = film.durationChapters[i];
	}
	return *this;
};


void Film::setChapters(int _nbrChapters, const int * _durationChapters)
{
    if (nbrChapters != _nbrChapters)
    {
        nbrChapters = _nbrChapters;
        delete [] durationChapters;
        durationChapters = new int[nbrChapters];
    };

    for (int i = 0; i < nbrChapters; i++) 
    {
        durationChapters[i] = _durationChapters[i];
    };

};

void Film::print(std::ostream & where)
{
    Video::print(where);
    where << "Number of chapters: " << nbrChapters << ", ";
    for (int i = 0; i < nbrChapters; i++) 
    {
        where << "Duration of Chapter " << i << ": " << durationChapters[i] << " ";
    };
    where << ". ";
};

#endif



