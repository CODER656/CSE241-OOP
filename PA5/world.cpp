#include "world.h"


World::World()
{
    for (int i = 0; i < WORLDSIZE; i++)
    {
        for (int j = 0; j < WORLDSIZE; j++)
        {
            grid[i][j] = NULL; //initialize all pointers to NULL
        }
        
    }
    
}


World::~World()
{
    for (int i = 0; i < WORLDSIZE; i++)
    {
        for (int j = 0; j < WORLDSIZE; j++)
        {
            if(grid[i][j] != NULL)
            {
                delete (grid[i][j]); //delete all robots
            }
        }
        
    }
}


Robot* World::getAt(int x, int y)
{
    if ((x >= 0) && (x < WORLDSIZE)  && (y >= 0) && (y < WORLDSIZE)) //check if x and y are in range
    {
        return grid[x][y]; //return the pointer at the given coordinates
    }
    return NULL; //if x and y are not in range return NULL
}


void World::setAt(int x, int y, Robot* rob) //set the pointer at the given coordinates
{
    if ( (x < WORLDSIZE) && (x >= 0) && (y < WORLDSIZE) && (y >= 0) ) //check if x and y are in range
    {
        grid[x][y] = rob; //put the robot into the grid
    }
}

void World::deleteRobot(int x, int y)
{
    if ( (x >= 0) && (x < WORLDSIZE) && (y>=0) && (y < WORLDSIZE) ) //check if x and y are in range
    {
        if (grid[x][y] != NULL) //if there is a robot at the given coordinates
        {
            delete grid[x][y]; //delete the robot
            grid[x][y] = NULL; //set the pointer to NULL
        }
    }
}


// simulates the game for only one step
void World::SimulateOneStep() 
{
    srand(time(NULL)); //initialize random seed

    for (int i = 0; i < WORLDSIZE; i++)
    {
        for (int j = 0; j < WORLDSIZE; j++)
        {
            if (grid[i][j] != NULL) //if there is a robot at the given coordinates
            {
                grid[i][j]->moved = false; //make sure all robots are not moved
            } 
        }
    }


    for (int i = 0; i < WORLDSIZE; i++)
    {
        for (int j = 0; j < WORLDSIZE; j++)
        { 
            if (grid[i][j] != NULL ) //if there is a robot at the given coordinates
            {
                if (grid[i][j]->moved == false) //if the robot is not moved
                {
                    grid[i][j]->moved = true; //set moved to true
                    grid[i][j]->move(); // moves the robot if cell is empty
                }
            }
            
        }
        
    }


    //if one robot is left print out the winner and exit
    int counter = 0;
    for (int i = 0; i < WORLDSIZE; i++)
    {
        for (int j = 0; j < WORLDSIZE; j++)
        {
            if (grid[i][j] != NULL)
            {
                counter++; //count the number of robots
            }
        }
    }
    if (counter == 1)
    {
        for (int i = 0; i < WORLDSIZE; i++)
        {
            for (int j = 0; j < WORLDSIZE; j++)
            {
                if (grid[i][j] != NULL)
                {
                    cout << grid[i][j]->getName() << " is the winner!" << endl; //print out the winner
                    exit(0);
                }
            }
        }
    }
    






}//end of SimulateOneStep()



void World::display()
{
    int counter = 0;    
    for (int i = 0; i < WORLDSIZE; i++)
    {
        for (int j = 0; j < WORLDSIZE; j++)
        {
            if (grid[i][j] != NULL )
            {
                cout << "R "; //print out R if there is a robot
                counter++;
            }
            else if (grid[i][j] == NULL)
            {
                cout << ". "; //print out . if there is no robot
            }
            
        }
        cout << endl;
    }
    
}