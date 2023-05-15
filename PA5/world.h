#include "robot.h"

const int WORLDSIZE = 10;

class Robot;

class World{

    friend class Robot; //Robot class can access private members of World class

    public:
        World(); //constructor
        ~World(); //destructor
        Robot* getAt(int x, int y); //get the pointer at the given coordinates
        void setAt(int x, int y, Robot* rob); //set the pointer at the given coordinates
        void SimulateOneStep(); //simulate one step of the world
        void display(); //display the world
        void deleteRobot(int x, int y); //delete the robot at the given coordinates

    private:
        Robot* grid[WORLDSIZE][WORLDSIZE]; //2D array of pointers to robots


};