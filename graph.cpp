/*
    implementation for set class
*/
#include "graph.h"
/*
    implementation
*/

//Constructor
Graph::Graph(){

}

//Destructor
Graph::~Graph(){

}

/*
    This function prompts the user for an integer. This number will
    be the number of vertices that are created.
*/
void Graph::getInput(){
    int input = -1;
    bool valid=false;
    while(!valid){
        std::cout<<"Please enter the number of vertices you would like to create:\n";
        std::cin>>input;//get input
        if(input<=0){//less than zero
            std::cout<<"Please enter a number greater than zero.\n";
            input=-1;
            continue;
        }
        valid=true;
    }
    numVertices=input;
}

/*
    This method adds a vertex to the graph
*/
void addVertex(){

}

/*
    This method adds an edge to the graph
*/
void addEdge(){

}

/*
    This method generates n random vertices where n is the integer
    the user inputed
*/
void createVertices(){
    int x, y;

}
