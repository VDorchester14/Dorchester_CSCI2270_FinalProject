/*
    defining my set class
*/
#ifndef SET_H
#define NUM_H
#include <vector>

//prototypes
struct vertex;
struct adjVertex;

//defining a struct for each data point
struct vertex{
    int x;
    int y;
    std::vector<adjVertex> adjacent;
    vertex(){
        x=0;
        y=0;
    }
};

//struct for each adjacent vertex
struct adjVertex{
    vertex *v;//pointer to next vertex
    double weight;//weight to that vertex
};

//defining my set class that will hold the data points
class Set{
    public:
        //constructors etc
        Set();
        ~Set();
        //methods
        int getInput();

};
#endif
