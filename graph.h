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
    int key;
    int x;
    int y;
    bool isOrigin;
    bool isEnd;
    std::vector<adjVertex> adjacent;
    vertex(){
        isOrigin=false;
        isEnd=false;
        x=0;
        y=0;
        key=-1;
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
        void addEdge(int, int);//adds an edge to the graph
        void addVertex(vertex* v);//adds a vertex to the graph
        void displayVertices();//prints the coordinates of vertices
        void clearGraph();//deletes all vertices in the graph
        void addEndPoints();//adds origin and end
        double calculateWeight(int, int);//calcs the weights
        void displayEdges();//displays the edges of the graph

        void constructMatrix();//makes an adjacency matrix
        void resetMatrix();

    private:
        int numVertices;//user input for the desired number of vertices
        std::vector<vertex> vertices;//stores the vertices
        int originCoord;
        int endCoord;
        double matrix[100][100];

};
#endif
