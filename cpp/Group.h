/**
 * 
 * 
 *  Defining class Group
 * 
 * 
 * 
 **/




#ifndef GROUP
#define GROUP
#include "Film.h"
#include "Photo.h"
#include <stdlib.h>
#include <list>
#include <memory>



/**
 * 
 * @brief Named group of shared pointers to Multimedia objects
 * 
*/

class Group : public std::list< std::shared_ptr<Multimedia> >
{

private :
    std::string groupName{};

public :
    Group(){};
    Group(std::string _groupName ) {groupName = _groupName;};
    

    std::string getGroupName() const {return groupName;};
    void print(std::ostream & where) const {for (auto & it : * this) it->print(where);};

};






#endif