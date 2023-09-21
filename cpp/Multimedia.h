/**
 * 
 * Class for Multimedia objects
 * 
 * 
 * 
 * 
 * 
 **/




#ifndef MULTIMEDIA
#define MULTIMEDIA
#include <iostream>
#include <fstream>
#include <memory>



class Multimedia
{

private:
    std::string objectName{};
    std::string filePath{};

public:
    Multimedia(); // Constructor without initialization
    Multimedia(std::string _objectName, std::string _filePath); //Constructor
    virtual ~Multimedia(); //Destructor
    virtual std::string getClassName() const = 0; // Method to return class name
    virtual void writeToFile(std::ofstream& _file); // Method to write object to file
    virtual void readFromFile(std::ifstream& _file); // Method to read object from file
    std::string getObject() const;
    std::string getFilePath() const;
    void setObject(std::string objectName);
    void setFilePath(std::string filePath);
    virtual void print(std::ostream & where);
    virtual void displayMultimedia() = 0;
    


};

#endif