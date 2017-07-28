/*
    implementation for set class
*/
#include "graph.h"
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <math.h>
#include <limits>

/*
    implementation
*/
//Constructor
Graph::Graph(){
    //set variables;
    numVertices=0;
    originCoord=0;
    endCoord=10;
    head=NULL;

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
    Adds the edges randomly
*/
void Graph::addRandomEdges(){
    std::cout<<"Building edges."<<std::endl;
    int min, max, x;
    min=2;
    max=numVertices-1;
    for(int i=1;i<numVertices/2;i++){
        for(int j=0;j<numVertices/2;j++){
            do{
                x = (min+1) + (rand() % static_cast<int>((max-1) - (min+1) + 1));
            }while(!addEdge(i,x));
            std::cout<<"from "<<i<<" to "<<x<<std::endl;

        }
    }
}
/*
    This method adds an edge to the graph
    edge goes both ways
*/
bool Graph::addEdge(int key1, int key2){
    if((key1>numVertices) or (key2>numVertices)){
        std::cout<<"Error adding edge."<<std::endl;
        return false;
    }
    if(key1==key2){
        std::cout<<"Cannot build edge to self."<<std::endl;
        return false;
    }
    for(int i=0;i<vertices[key1-1].adjacent.size();i++){
        if(key2==vertices[key1-1].adjacent[i].v->key){
            return false;
        }
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
    return true;
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
            matrix[i][j]=std::numeric_limits<double>::infinity();
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
                int m = vertices[i].adjacent[j].v->key;//get key
                //it's a symetric, hollow matrix so do this
                matrix[i][m-1]=k;
                matrix[m-1][i]=k;
        }
    }
}

/*
    Sets all the vertices to unvisited. I assume
    i will make use of this when running my algorithms all the time
*/
void Graph::unvisitVertices(){
    for(int i=0;i<vertices.size();i++){
        vertices[i].visited=false;
    }
}

/*
    This is an algorithm that makes use of the adjacency matrix
    to find the shortest path.
*/
void Graph::adjacencyMatrixAlgorithm(){

    //make the node for the path lists
    node* adj = new node();
    adj->name="Adjacency Matrix Algorithm";

    //if the list is empty, set this to the head
    if(head==NULL){
        head=adj;
    }

    //find end of list
    node* walker = head;
    while(walker->nextAlgorithm!=NULL){
        walker=walker->nextAlgorithm;
    }//walker is now on the last element
    walker->nextAlgorithm=adj;//set its next to this one

    //define what we can of the node
    std::vector<vertex> shortestPath;
    vertex *mover = &vertices[0];

    //TODO
    //actually implement this algorithm lol
}
/*
    print path
*/
void Graph::printPath(std::string name){
    if(head==NULL){
        std::cout<<"No paths defined yet."<<std::endl;
        return;
    }
    node *walker = head;
    while(walker->nextAlgorithm!=NULL){
        if((walker->name==name) or (name=="all")){
            std::cout<<"Algorithm used: "<<walker->name<<std::endl;
            std::cout<<"Path found: ";
            for(int i=0;i<walker->path.size();i++){
                if(walker->path[i].key==2){
                    std::cout<<walker->path[i].key;
                }else{
                    std::cout<<walker->path[i].key<<"->";
                }
            }
            std::cout<<std::endl;
            std::cout<<"Weight of path: "<<walker->weight<<std::endl;
        }
        std::cout<<walker->name<<std::endl;
        walker=walker->nextAlgorithm;
    }
}
/*
    Floyd's shortest path algorithm
*/
void Graph::floyd(){
    if(numVertices==2){
        std::cout<<"There are no vertices in this graph."<<std::endl;
        return;
    }
    //setting next matrix
    int path[100][100];//to store the paths taken
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            path[i][j]==-1;
        }
    }
    //set up temporary matrix so as to not alter the old one
    double temp[100][100];//to not alter the adj matrix
    for(int i=0;i<numVertices;i++){
        for(int j=0;j<numVertices;j++){
            path[i][j]=0;
            temp[i][j]=matrix[i][j];
        }
    }
    //initialize path array
    for(int i=0;i<vertices.size();i++){//loop through vertices
        for(int j=0;j<vertices[i].adjacent.size();j++){//loop through adjacent vector for each vertex
                int m = vertices[i].adjacent[j].v->key;//get key
                //it's a symetric, hollow matrix so do this
                path[i][m-1]=i+1;
                //path[m-1][i]=i+1;
        }
    }
    for(int i=0;i<numVertices;i++){
        path[i][i]=i;
    }

    //algorithm implementation
    for(int k=0;k<numVertices;k++){
        for(int i=0;i<numVertices;i++){
            for(int j=0;j<numVertices;j++){
                if(temp[i][k]+temp[k][j]<temp[i][j]){
                    temp[i][j]=temp[i][k]+temp[k][j];
                    path[i][j]=path[k][j];
                }
            }
        }
    }

    //finding path now
    node floyd;
    floyd.name="Floyds Algorithm";
    //path doesn't exist
    if(path[0][1]==-1){//Path doesn't exist
        floyd.weight=-1;//
        return;
    }
    //otherwise find the path
    int i=0, j=1;
    do{
        floyd.path.push_back(vertices[i]);
        i=path[j][i]-1;
    }while(i!=1);
    floyd.path.push_back(vertices[i]);

    floyd.weight = temp[0][1];//set the weight
    //add this node to the linked list of solutions
    if(head==NULL){//if the list is empty
        head=&floyd;
    }
    node *walker=head;
    while(walker->nextAlgorithm!=NULL){//iterate through list
        if(walker->name==floyd.name){//if this solution already exists
            return;
        }
        walker=walker->nextAlgorithm;
    }//walker is now on the last node
    walker->nextAlgorithm=&floyd;
    //finally print the output
    std::cout<<"\nPath found using floyds Algorithm with weight "<<floyd.weight<<": ";
    for(int i=0;i<floyd.path.size();i++){
        if(floyd.path[i].isEnd){
            std::cout<<floyd.path[i].key;
        }else{
            std::cout<<floyd.path[i].key<<"->";
        }
    }
    std::cout<<std::endl<<std::endl;
}

/*
    Implementing Dijstra's Algorithm
*/
void Graph::dijkstra(){
    if(numVertices==2){
        std::cout<<"There are no vertices in this graph."<<std::endl;
        return;
    }
    double dist[numVertices];//will hold the shortest distance for each point
    bool sptSet[numVertices];//to check if the vertex has been processed
    //creating node
    node dijkstra;
    dijkstra.name="Dijkstras Algorithm";
    //if this is the first one, add it to the list
    if(head==NULL){
        head=&dijkstra;
    }
    bool exists = false;
    node *walk=head;
    /*
    while(walk->nextAlgorithm!=NULL){
        if(walk->name=dijkstra.name){
            exists=true;
        }
        walk=walk->nextAlgorithm;
    }//now walker is the last one in the list
    */
    if(!exists){
        walk->nextAlgorithm=&dijkstra;//add dijkstra to it
    }
    //init these two arrays
    for (int i = 0; i < numVertices; i++){
        dist[i] = std::numeric_limits<double>::infinity(), sptSet[i] = false;
    }
    //set distance from start vertex to zero
    int parent[numVertices];//to store path
    dist[0]=0;
    parent[0]=-1;

    // Find shortest path for all vertices
    for (int count = 0; count < numVertices-1; count++){
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;//mark it as visited
        for (int v = 0; v < numVertices; v++){
            if (!sptSet[v] && matrix[u][v] && dist[u] != std::numeric_limits<double>::infinity() && dist[u]+matrix[u][v] < dist[v]){
                dist[v] = dist[u] + matrix[u][v];
                parent[v]=u;
            }
        }
     }

     //now more node work
     dijkstra.weight=dist[1];
     int j=1;
     while(j!=100){
         dijkstra.path.insert(dijkstra.path.begin(),vertices[j]);
         if(parent[j]==-1){
             break;
         }
         j=parent[j];
     }
     //finally print the output
     std::cout<<"\nPath found using Dijkstra's Algorithm with weight "<<dijkstra.weight<<": ";
     for(int i=0;i<dijkstra.path.size();i++){
         if(dijkstra.path[i].isEnd){
             std::cout<<dijkstra.path[i].key;
         }else{
             std::cout<<dijkstra.path[i].key<<"->";
         }
     }
     std::cout<<std::endl<<std::endl;
}
//minimum distance function to find minimum non visited vertex for dijkstra
int Graph::minDistance(double dist[], bool sptSet[])
{
   // Initialize min value
   int min = 10000, min_index;

   for (int v = 0; v < numVertices; v++){
       if (sptSet[v] == false && dist[v] <= min){
           min = dist[v], min_index = v;
       }
   }
   return min_index;
}
