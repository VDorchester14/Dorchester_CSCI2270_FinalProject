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
    int key;//for easy calling and organization
    int x;//x coordinates
    int y;//y coordinate
    bool isOrigin;//is this point the origin?
    bool isEnd;//is this point the end point?
    bool visited;//to see if the node has been visited. used in my algorithms
    std::vector<adjVertex> adjacent;//vector of adjacent points
    //constructor
    vertex(){
        isOrigin=false;//probably not the origin
        isEnd=false;//or the end for that matter
        visited=false;
        x=0;
        y=0;
        key=-1;
    }
};

//node struct to make a linked list
//each node will have the name of the algorithm used
//a pointer to the next node, and a pointer to the first
//vertex in the
struct node{
    std::string name;
    node *nextAlgorithm;
    std::vector<vertex> path;
    double weight;
    node(){
        nextAlgorithm=NULL;
        weight=0.0;
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
        //user interaction functions
        void getInput();//gets input for number of points to create
        //graph functions
        void createVertices();//creates vertices w/ random coordinates
        bool addEdge(int, int);//adds an edge to the graph
        void addVertex(vertex* v);//adds a vertex to the graph
        void displayVertices();//prints the coordinates of vertices
        void clearGraph();//deletes all vertices in the graph
        void addEndPoints();//adds origin and end
        double calculateWeight(int, int);//calcs the weights
        void displayEdges();//displays the edges of the graph
        void unvisitVertices();//unvisits all the vertices
        void addRandomEdges();
        //matrix functions
        void constructMatrix();//makes an adjacency matrix
        void resetMatrix();
        //shortest path algorithms
        void adjacencyMatrixAlgorithm();
        void dijkstra();
        int minDistance(double[], bool[]);
        void floyd();//Floyd's shortest path algorithm
        void printPath(std::string);

    private:
        int numVertices;//user input for the desired number of vertices
        std::vector<vertex> vertices;//stores the vertices
        int originCoord;//origin coordinates
        int endCoord;//end point coordinates
        double matrix[100][100];//adjacency matrix
        node *head;//head of linked list containing shortest paths

};
#endif
