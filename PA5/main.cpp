#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include "robot.h"
#include "world.h"
#include "roomba.h"
#include "bulldozer.h"
#include "optimusprime.h"
#include "robocop.h"


using namespace std;

const int INITIAL_COUNT = 5; //initial number of robots

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    World world; //create a world
    string input; //user input
 
    int roombaCount = 0;
    int bulldozerCount = 0;
    int optimusPrimeCount = 0;
    int robocopCount = 0;

    while (roombaCount < INITIAL_COUNT) //create initial number of roombas
    {
        int x = rand() % WORLDSIZE; //random x coordinate
        int y = rand() % WORLDSIZE;
        if (world.getAt(x,y)==NULL) //if there is no robot at the given coordinates
        {
            roombaCount++; //increment count
            string robotName = "robocop_" + to_string(roombaCount); //create a name for the robot
            Roomba *roomba = new Roomba(&world, x, y,3,10,robotName); //create a new robot
        }
    }
    

    while (bulldozerCount < INITIAL_COUNT) //create initial number of bulldozers
    {
        int x = rand() % WORLDSIZE; //random x coordinate
        int y = rand() % WORLDSIZE;
        if (world.getAt(x,y)==NULL)
        {
            string robotName = "bulldozer_" + to_string(bulldozerCount); //create a name for the robot
            Bulldozer *bulldozer = new Bulldozer(&world, x, y,50,200,robotName); //create a new robot
            bulldozerCount++;
        }
    }

    while (optimusPrimeCount < INITIAL_COUNT) //create initial number of optimus primes
    {
        int x = rand() % WORLDSIZE;
        int y = rand() % WORLDSIZE;
        if (world.getAt(x,y)==NULL)
        {
            string robotName = "optimusPrime_" + to_string(optimusPrimeCount); //create a name for the robot
            OptimusPrime *optimusPrime = new OptimusPrime(&world, x, y,100,100,robotName); //create a new robot
            optimusPrimeCount++;
        }
    }


    while (robocopCount < INITIAL_COUNT)
    {
        int x = rand() % WORLDSIZE;
        int y = rand() % WORLDSIZE;
        if (world.getAt(x,y)==NULL)
        {
            string robotName = "robocop_" + to_string(robocopCount); //create a name for the robot
            Robocop *robocop = new Robocop(&world, x, y,30,40,robotName); //create a new robot
            robocopCount++;
        }
    }
    //robots randomly placed to grid now



    while (true) //game loop
    {
        //world.display();
        world.SimulateOneStep(); //simulate one step
        cout << "Press enter to continue" << endl; //prompt user to continue
        getline(cin, input); //get user input

    }
    

    
    return 0;
}
