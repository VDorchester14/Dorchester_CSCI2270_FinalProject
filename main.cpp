/*
Vail Dorchester
7.25.17
Final Project
*/

//includes
#include <iostream>
#include <string>
#include "graph.cpp"


//prototypes
void menu();
void about();

//main methods
int main(){
    menu();
}

//implementation
void menu(){

    int input=-1;//input variable
    Graph graph;
    //menu loop
    while(input!=9){//while exit is not selected
        //print menu
        std::cout<<"======Main Menu======"<<std::endl;
        std::cout<<"0. About this program"<<std::endl;
        std::cout<<"1. Build a set of n random points in 2D"<<std::endl;
        std::cout<<"2. Print vertices of graph"<<std::endl;
        std::cout<<"3. Display edges of graph"<<std::endl;
        std::cout<<"4. Clear the graph"<<std::endl;
        std::cout<<"-------Algorithms-------"<<std::endl;
        std::cout<<"5. Use The Adjacency Matrix Algorithm"<<std::endl;
        std::cout<<"6. Use Floyd's Algorithm"<<std::endl;
        std::cout<<"7. Use Dijkstra's Algorithm"<<std::endl;
        std::cout<<"9. Quit"<<std::endl;

        //get input
        std::cin>>input;
        std::cin.ignore();
        //do stuff with input
        switch(input){
            case 0:
                about();
                break;
            case 1://build 2d set7
                //add function to ask for how many points
                //graph.clearGraph();
                //graph.addEndPoints();
                //graph.getInput();
                //graph.createVertices();
                //graph.constructMatrix();
                std::cout<<"Function currently not available."<<std::endl;
                break;
            case 2:
                graph.displayVertices();
                break;

            case 3:
                graph.displayEdges();
                break;
            case 4:
                graph.clearGraph();
                graph.addEndPoints();
                break;
            case 5:
                //graph.adjacencyMatrixAlgorithm();
                std::cout<<"Function has yet to be implemented"<<std::endl;
                break;
            case 6:
                graph.floyd();
                graph.printPath("Floyd's Algorithm");
                break;
            case 7:
                graph.dijkstra();
                break;
            case 9://Quit
                std::cout<<"Goodbye!"<<std::endl;
                return;
        }
    }
}

//Just prints some info about the program and how to use it
void about(){
    std::cout<<"This program is designed to find the shortest path between a list of vertices.\n";
    std::cout<<"Right now, the list is pre-made, but, in the future, you will be able to use option 1\n";
    std::cout<<"to create a list of n random points. Select an alrogithm in order to view the shortest\n";
    std::cout<<"path found using it, or select the all option to view the shortest path for all alrogithms."<<std::endl;
}
