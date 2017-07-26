/*
    defining my set class
*/
#ifndef GRAPH_H
#define GRAPH_H
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
class Graph{
    public:
        //constructors etc
        Graph();
        ~Graph();
        //methods
        void getInput();//gets input for number of points to create
        void createVertices();//creates vertices w/ random coordinates
        void addEdge();//adds an edge to the graph
        void addVertex();//adds a vertex to the graph
        void constructMatrix();//makes an adjacency matrix
        void displayVertices();//prints the coordinates of vertices

    private:
        int numVertices;//user input for the desired number of vertices
        std::vector<vertex> vertices;//stores the vertices

};
#endif
