/*
    implementation for set class
*/
#include "graph.h"
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <math.h>

/*
    implementation
*/
//Constructor
Graph::Graph(){
    //set variables;
    numVertices=0;
    originCoord=0;
    endCoord=10;

    //initialize graph
    clearGraph();
    addEndPoints();

    //initialize the matrix
    resetMatrix();

    //hard coding points so i can test
    vertex b,c,d,e,f;
    b.x=2;
    b.y=5;
    b.key=3;
    c.x=5;
    c.y=2;
    c.key=4;
    d.x=4;
    d.y=5;
    d.key=5;
    e.x=8;
    e.y=6;
    e.key=6;
    f.x=3;
    f.y=8;
    f.key=7;
    vertices.push_back(b);
    vertices.push_back(c);
    vertices.push_back(d);
    vertices.push_back(e);
    vertices.push_back(f);
    numVertices+=5;
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(3, 7);
    addEdge(3, 5);
    addEdge(4, 5);
    addEdge(4, 6);
    addEdge(6, 2);
    addEdge(7, 2);
    constructMatrix();
}

//Destructor
Graph::~Graph(){
    clearGraph();
}

/*
    This function prompts the user for an integer. This number will
    be the number of vertices that are created.
*/
void Graph::getInput(){
    int input = -1;
    bool valid=false;
    while(!valid){
        std::cout<<"Please enter the number of vertices you would like to create.\n";
        std::cout<<"The number should be between 1 and 100.\n";
        std::cin>>input;//get input
        if(input<=0){//less than zero
            std::cout<<"Please enter a number greater than zero.\n";
            input=-1;
            continue;
        }
        valid=true;
    }
    numVertices+=input;
}

/*
    This method adds a vertex to the graph
*/
void Graph::addVertex(vertex* v){
    vertices.push_back(*v);
}

/*
    Calculates the weight between two edges
*/
double Graph::calculateWeight(int key1, int key2){
    //variables
    double weight;
    int xDiff;
    int yDiff;

    //calculations
    xDiff=(vertices[key1-1].x - vertices[key2-1].x);
    yDiff=(vertices[key1-1].y - vertices[key2-1].y);
    weight = sqrt((xDiff*xDiff)+(yDiff*yDiff));

    //return
    return weight;
}

/*
    This method adds an edge to the graph
    edge goes both ways
*/
void Graph::addEdge(int key1, int key2){
    if((key1>numVertices) or (key2>numVertices)){
        std::cout<<"Error adding edge."<<std::endl;
        return;
    }
    //from key1 to key2
    double weight = calculateWeight(key1, key2);
    adjVertex k;
    k.weight=weight;
    k.v=&vertices[key2-1];
    vertices[key1-1].adjacent.push_back(k);
    //from key2 to key1
    adjVertex j;
    j.weight=weight;
    j.v=&vertices[key1-1];
    vertices[key2-1].adjacent.push_back(j);
}

/*
    This method generates n random vertices where n is the integer
    the user inputed
*/
void Graph::createVertices(){
    //variables
    int x, y, min, max;
    //create the vertices
    std::cout<<"Creating vertices."<<std::endl;
    for(int i=0;i<numVertices;i++){
        //randomize x and y
        x = (originCoord+1) + (rand() % static_cast<int>((endCoord-1) - (originCoord+1) + 1));
        y = (originCoord+1) + (rand() % static_cast<int>((endCoord-1) - (originCoord+1) + 1));
        //create a vertex struct
        vertex v;
        v.x=x;
        v.y=y;
        v.key=i+3;
        //pass it to the addVertex function
        addVertex(&v);
    }
}

/*
    displays the vertices of the Graph
*/
void Graph::displayVertices(){
    for(int i=0;i<numVertices;i++){
        std::cout<<"Vertex "<<vertices[i].key<<" at ("<<vertices[i].x<<", "<<vertices[i].y<<")"<<std::endl;
    }
}

/*
    Displays the edges of the Graph
*/
void Graph::displayEdges(){
    for(int i=0;i<numVertices;i++){
        for(int k=0;k<vertices[i].adjacent.size();k++){
            std::cout<<"Vertex "<<i+1<<" points to vertex "<<vertices[i].adjacent[k].v->key<<std::endl;
            std::cout<<"Edge has weight "<<vertices[i].adjacent[k].weight<<std::endl;
        }
    }
}

/*
    Adds origin and final points
*/
void Graph::addEndPoints(){
    //creating vertices
    vertex origin, end;
    int o=originCoord;
    int e=endCoord;
    origin.x=originCoord;
    origin.y=originCoord;
    origin.isOrigin=true;
    origin.key=1;
    end.x=endCoord;
    end.y=endCoord;
    end.isEnd=true;
    end.key=2;
    //adding the two to the list
    vertices.push_back(origin);
    vertices.push_back(end);
    numVertices+=2;//increment vertices count;
}

/*
    Empties the vector
*/
void Graph::clearGraph(){
    vertices.clear();
    numVertices=0;
    resetMatrix();
}

/*
    Resets the adjacen matrix
*/
void Graph::resetMatrix(){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            matrix[i][j]=0;
        }
    }
}
/*
    Constructs an adjacency matrix out of the set graph
*/
void Graph::constructMatrix(){
    resetMatrix();
    double k;
    for(int i=0;i<vertices.size();i++){//loop through vertices
        for(int j=0;j<vertices[i].adjacent.size();j++){//loop through adjacent vector for each vertex
                k=vertices[i].adjacent[j].weight;//get weight
                int m = vertices[i].adjacent[j].v->key;
                matrix[i][m-1]=k;
                matrix[m-1][i]=k;
        }
    }
    for(int i=0;i<vertices.size();i++){
        for(int j=0;j<vertices.size();j++){
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}
