/**
 * 
 * @brief Macro for choosing STAGES10 or SERVER
 * 
*/
#define SERVER

#include <unistd.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "Mapping.h"
#include "tcpserver.h"
#include "Factory.h"
#include <fstream>
using namespace std;



bool saveAll(const std::string & filename, const std::vector< shared_ptr<Multimedia> > & objects)
{
    std::ofstream file(filename);
    if (!file)
    {
        cerr << "Can't open file " << filename << endl;
        return false;
    }

    for (auto it : objects)
    {
        file << it->getClassName();
        it->writeToFile(file);
        if (file.fail())
        {
            cerr << "Write error in " << filename << endl;
            return false;
        }
    }
    return true;
};


bool readAll(const std::string & filename, std::vector< shared_ptr<Multimedia> > & objects)
{
    std::ifstream file(filename);
    if (!file)
    {
        cerr << "Can't open file " << filename << endl;
        return false;
    };

    while (file.is_open() & (file.peek() != EOF))
    {
        std::string classname;
        getline(file, classname);
        shared_ptr<Multimedia> obj = createMultimedia(classname);
        if (obj != nullptr) obj->readFromFile(file);


        if (file.fail())
        {
            cerr << "Read error in " << filename << endl;
            return false;
        }
        else objects.push_back(obj);

    };


    return true;
} 





const int PORT = 3331;

int main(int argc, const char* argv[])
{

    #ifdef STAGES10

    // Stage 1
    //std::cout << "Hello brave new world" << std::endl;

    /** Stage 3

    Video * m = new Video();
    m->setObject("Video");
    m->setFilePath("Fede.mp4");
    m->print(cout);
    m->displayMultimedia();
    delete m;

    **/


    
    /** Stage 5

    Multimedia * arrayAUX[2];
    arrayAUX[0] = new Photo("Photo", "DOG.jpeg", 1, 10);
    arrayAUX[1] = new Video("Video", "Fede.mp4", 20);

    for (int i = 0; i < 2; i++)
    {
        arrayAUX[i]->print(cout);
        arrayAUX[i]->displayMultimedia();
        sleep(5);
        delete arrayAUX[i];
    };
    

    **/


    /** Stages 6 and 7

    int * durations = new int [3];
    durations[0] = 4;
    durations[1] = 5;
    durations[2] = 6;

    int * durations1 = new int [2];
    durations1[0] = 7;
    durations1[1] = 8;


    Film * film1 = new Film();
    Film * film2 = new Film("Film", "path", 10, 3, durations);
    *film1 = *film2;


    film2->setChapters(2,durations1);

    delete [] durations;
    delete [] durations1;

    film1->print(cout);
    film2->print(cout);
    
    delete film1;
    delete film2;


    **/

    /** Stages 8 and 9

    typedef std::shared_ptr<Multimedia> MultimediaPtr;

    int * durations = new int [3];
    durations[0] = 4;
    durations[1] = 5;
    durations[2] = 6;

    Group * group1 = new Group("Group1");
    Group * group2 = new Group("Group2");
    MultimediaPtr film1 (new Film("Film", "path", 10, 3, durations));
    MultimediaPtr photo1 = make_shared<Photo>("Photo", "DOG.jpeg", 1, 10);


    group1->push_back(film1);
    group1->push_back(photo1);

    group2->push_back(photo1);

    // To make the pointer point to nothing
    film1.reset();
    photo1.reset();

    cout << group1->getGroupName() << endl;

    group1->print(cout);

    cout << endl;

    group1->pop_front(); // for removing film1 that is only in group1 and checking that the object is deleted
    // group1->pop_back(); // for removing photo1 that is in both groups and checking that the object is not deleted because it is in group 2

    
    cout << group1->getGroupName() << endl;

    group1->print(cout);

    cout << endl;


    cout << group2->getGroupName() << endl;

    group2->print(cout);


    delete group1;
    delete group2;

    **/


    /** Stage 11

    int * durations = new int [3];
    durations[0] = 4;
    durations[1] = 5;
    durations[2] = 6;

    shared_ptr<Mapping> newMap = make_shared<Mapping>();
    auto photo1 =  newMap->createPhoto("Photo", "DOG.jpeg", 1, 10);
    auto film1 = newMap->createFilm("Film", "path", 10, 3, durations);
    newMap->createVideo("Video", "Fede.mp4", 20);
    auto group1 = newMap->createGroup("Group1");

    newMap->print("Photo", cout);
    newMap->display("Photop");

    cout << endl;

    photo1->setFilePath("new_path", cout);

    cout << endl;
    photo1->print(cout);

    cout << endl;
    newMap->print("Photo", cout);

    cout << endl;

    group1->push_back(film1);
    newMap->print("Film", cout);


    **/


    // Stage 12

    int * durations = new int [3];
    durations[0] = 4;
    durations[1] = 5;
    durations[2] = 6;

    std::vector< shared_ptr<Multimedia> > table;
    std::vector< shared_ptr<Multimedia> > table2;
    shared_ptr<Photo> photo1 = make_shared<Photo>("Photo1", "DOG.jpeg", 1, 10);
    table.push_back(photo1);
    auto film1 = make_shared<Film>("Film1", "Fede.mp4", 10, 3, durations );
    table.push_back(film1);


    saveAll("Test1", table );

    readAll("Test1", table2 );
    
    for (auto it : table2 )
    { if (it != nullptr ) it->print(cout); };
    



    return 0;

    #endif

    #ifdef SERVER

    int * durations = new int [3];
    durations[0] = 4;
    durations[1] = 5;
    durations[2] = 6;
    
    shared_ptr<Mapping> newMap = make_shared<Mapping>();
    auto photo1 = newMap->createPhoto("Photo", "DOG.jpeg", 1, 10);
    auto film1 = newMap->createFilm("Film", "Fede.mp4", 10, 3, durations );
    auto video1 = newMap->createVideo("Video", "Fede.mp4", 20);
    auto group1 = newMap->createGroup("Group1");
    group1->push_back(photo1);
    group1->push_back(film1);
    group1->push_back(video1);


    /**
     * 
     * SERVER
     * 
    */

    // Create the TCPServer
    auto* server =
    new TCPServer( [&](std::string const& request, std::string& response) {

        // the request sent by the client to the server
        std::cout << "request: " << request << std::endl;

        istringstream ss(request);
        vector <string> split(istream_iterator<std::string>{ss}, istream_iterator<string>());


        if (split[0] == "print")
        {
        try
        {
            stringstream out;
            newMap->print(split[1], out );
            response = out.str();
        }
        catch(const char* e)
        {
            cerr << e << '\n';
        }
        
        }

        else if (split[0] == "display")
        {
            newMap->display(split[1]);
            response = "OK";
        }

        else
        {
            response = "Error in the arguments passed";
        };
        

        

        // return false would close the connection with the client
        return true;
    });


    // Launch the infinite boucle of the server
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    return 0;

    #endif


    
}
