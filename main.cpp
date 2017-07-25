/*
Vail Dorchester
7.25.17
Final Project
*/

//includes
#include <iostream>
#include <string>

//prototypes
void menu();

//main methods
int main(){
    menu();
}

//implementation
void menu(){
    int input=-1;//input variable

    //menu loop
    while(input!=9){//while exit is not selected
        //print menu
        std::cout<<"======Main Menu======"<<std::endl;
        std::cout<<"1. Build a set of n random points in 2D"<<std::endl;
        std::cout<<"9. Quit"<<std::endl;

        //get input
        std::cin>>input;
        std::cin.ignore();
        //do stuff with input
        switch(input){
            case 1://build 2d set
                //add function to ask for how many points
            case 9://Quit
                std::cout<<"Goodbye!"<<std::endl;
                return;
        }
    }
}
