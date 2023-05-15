#include "robot.h"
#include "world.h"
#include <iostream>


// default constructor
Robot::Robot() 
{
    world = NULL; //set the world pointer to NULL
    moved = false;
    x = 0;
    y = 0;
    type = 0;
    strength = 0;
    hitpoints = 0;
    name = "";
}

// constructor
Robot::Robot(int newType, int newStrength, int newHit, string name)
{
    type = newType;
    strength = newStrength;
    hitpoints = newHit;
    this->name = name;
}

Robot::Robot(World *wrld, int x, int y)
{
    this->world = wrld;
    this->x = x;
    this->y = y;
    moved = false;
    wrld->setAt(x, y, this); //put the robot in the world
}

Robot::Robot(World *wrld, int x, int y, string name)
{
    this->world = wrld;
    this->x = x;
    this->y = y;
    moved = false;
    wrld->setAt(x, y, this);
    this->name = name;
}

Robot::Robot(World *wrld, int x, int y, int newStrength, int newHit, string name)
{
    this->world = wrld;
    moved = false;
    this->x = x;
    this->y = y;
    this->name = name;
    strength = newStrength;
    hitpoints = newHit;
    wrld->setAt(x, y, this);
}

Robot::Robot(World *world, int newType, int newStrength, int newHit, string name)
{
    this->world = world;
    type = newType;
    strength = newStrength;
    hitpoints = newHit;
    this->name = name;
}

Robot::Robot(World *world, int newType, int newStrength, int newHit)
{
    this->world = world;
    type = newType;
    strength = newStrength;
    hitpoints = newHit;
}

// getters and setters
string Robot::getName()
{
    return name;
}

int Robot::getStrength()
{
    return strength;
}

int Robot::getHitpoints()
{
    return hitpoints;
}

int Robot::GetX()
{
    return x;
}

int Robot::GetY()
{
    return y;
}

void Robot::setStrength(int newStrength)
{
    strength = newStrength;
}

void Robot::setType(int newType)
{
    type = newType;
}

void Robot::setHitpoints(int newHit)
{
    hitpoints = newHit;
}

void Robot::setName(string newName)
{
    name = newName;
}


void Robot::move()
{
    // if it is not null and it is a robot ,move up
    if ((y>0) && (world->getAt(x,y-1)!=NULL))// one above is robot
    {
        Robot* winner_robot = fight(this, world->getAt(x,y-1)); // robots will fight
        if (winner_robot == this) // if the current robot wins
        {
            world->setAt(x, y-1, this); // set the current robot to the upper cell
            world->setAt(x, y, NULL); // set the current cell to NULL
            y--; // update the y coordinate of the current robot to the upper cell
            this->y = y;    // update the y coordinate of the current robot to the upper cell
            return;
        }
        else
        {  //if the other robot wins replaces the current robot
            world->setAt(x, y-1, NULL); // set the upper cell to NULL
            world->setAt(x, y,world->getAt(x,y-1)); // set the current cell to the upper cell
            return;
        }
    }
    else if ((y<WORLDSIZE-1) && (world->getAt(x,y+1)!=NULL)) //one below is robot
    {
        Robot* winner_robot = fight(this, world->getAt(x,y+1)); // robots will fight
        if (winner_robot == this) // if the current robot wins
        {
            world->setAt(x, y+1, this); // set the current robot to the lower cell
            world->setAt(x, y, NULL); // set the current cell to NULL
            y++; // update the y coordinate of the current robot to the lower cell
            this->y=y;
            return;
        }
        else
        {  //if the other robot wins replaces the current robot
            world->setAt(x, y+1, NULL); // set the lower cell to NULL
            world->setAt(x, y,world->getAt(x,y+1)); // set the current cell to the lower cell
            return;
        }
    }
    else if ((x>0) && (world->getAt(x-1,y)!=NULL)) //one left is robot
    {
        Robot* winner_robot = fight(this, world->getAt(x-1,y)); // robots will fight
        if (winner_robot == this) // if the current robot wins
        {
            world->setAt(x-1, y, this); // set the current robot to the left cell
            world->setAt(x, y, NULL);   // set the current cell to NULL
            x--; // update the x coordinate of the current robot to the left cell
            this->x=x; // update the x coordinate of the current robot to the left cell
            return; 
        }
        else
        {  //if the other robot wins replaces the current robot
            world->setAt(x-1, y, NULL); // set the left cell to NULL
            world->setAt(x, y,world->getAt(x-1,y)); // set the current cell to the left cell
            return;
        }
    }
    else if ((x<WORLDSIZE-1) && (world->getAt(x+1,y)!=NULL)) //one right is robot
    {
        Robot* winner_robot = fight(this, world->getAt(x+1,y)); // robots will fight
        if (winner_robot == this) // if the current robot wins
        {
            world->setAt(x+1, y, this); // set the current robot to the right cell
            world->setAt(x, y, NULL); // set the current cell to NULL
            x++;
            this->x=x; // update the x coordinate of the current robot to the right cell
            return;
        }
        else
        {  //if the other robot wins replaces the current robot
            world->setAt(x+1, y, NULL);
            world->setAt(x, y,world->getAt(x+1,y));
            return;
        }
    }




    //if we got here and we didn't find any robot
    //move to a random spot if we can find one
    int dir = rand() % 4; // 0 up, 1 down, 2 left, 3 right

    if (dir==0) //move up
    {
        if ((y>0) && (world->getAt(x,y-1)==NULL)) //if the upper cell is empty
        {
            world->setAt(x, y-1, this); // set the current robot to the upper cell
            world->setAt(x, y, NULL); // set the current cell to NULL
            y--; // update the y coordinate of the current robot to the upper cell
            this->y=y; // update the y coordinate of the current robot to the upper cell
        } 
    }
    else if (dir==1) //move down
    {
        if ((y<WORLDSIZE-1) && (world->getAt(x,y+1)==NULL)) //if the lower cell is empty
        {
            world->setAt(x, y+1, this); // set the current robot to the lower cell
            world->setAt(x, y, NULL); // set the current cell to NULL
            y++; 
            this->y=y;
        }
    }
    else if (dir==2) //move left
    {
        if ((x>0) && (world->getAt(x-1,y)==NULL))
        {
            world->setAt(x-1, y, this);
            world->setAt(x, y, NULL);
            x--;
            this->x=x;
        }
    }
    else if (dir==3) //move right
    {
        if ((x<WORLDSIZE-1) && (world->getAt(x+1,y)==NULL))
        {
            world->setAt(x+1, y, this);
            world->setAt(x, y, NULL);
            x++;
            this->x=x;
        }
    }

} //end of move function



/*Lets say, robot R(attacker) tries to fight with robot S(victim). Here is the algorithm:
Repeat until R or S dies:
• R calls getDamage(). getDamage() returns d_r.
• hitpoints of S is decremented by d_r.
• print hit_message(see hit_message for details)
• If S is dead, return.
• S calls getDamage(). getDamage() returns d_s.
• hitpoints of R is decremented by d_s.
• print hit_message(see hit_message for details)*/
Robot* Robot::fight(Robot *attacker, Robot *victim) //returns winner
{
    if (attacker != NULL || victim != NULL) //check pointers are not NULL
    {
        cout << "\n";
        
        while (attacker->getHitpoints() > 0 || victim->getHitpoints() > 0) //while both robots are alive
        {
            cout << "\n";
            int d_r = attacker->getDamage(); //get damage of attacker
            victim->setHitpoints(victim->getHitpoints() - d_r); //decrement hitpoints of victim by damage of attacker

            //Hit message
            cout << attacker->getName() << "(" << attacker->getHitpoints() << ")" << " hits " <<
            victim->getName() << "(" << victim->getHitpoints() + d_r << ")" << " with " << d_r << endl;
            cout << "The new hitpoints of " << victim->getName() << " is " << victim->getHitpoints() << endl;

            if (victim->getHitpoints() <= 0) //if victim is dead
            {
                //Dead robots should be removed from the grid.
                world->deleteRobot(victim->GetX(), victim->GetY());
                //print the death message
                cout << victim->getName() << " is dead. Goodbye!" << endl;
                return attacker;
            }

            int d_s = victim->getDamage(); //get damage of victim
            attacker->setHitpoints(attacker->getHitpoints() - d_s); //decrement hitpoints of attacker by damage of victim

            //Hit message
            cout << victim->getName() << "(" << victim->getHitpoints() << ")" << " hits " <<
            attacker->getName() << "(" << attacker->getHitpoints() +d_s << ")" << " with " << d_s << endl;
            cout << "The new hitpoints of " << attacker->getName() << " is " << attacker->getHitpoints() << endl;

            if (attacker->getHitpoints() <= 0) //if attacker is dead
            {
                //Dead robots should be removed from the grid.
                world->deleteRobot(attacker->GetX(), attacker->GetY());
                //print the death message
                cout << attacker->getName() << " is dead. Goodbye!" << endl;
                return victim;
            }
        }
    }
    else if (attacker == NULL || victim == NULL) //if one of the robots is NULL
    {
        cout << "One of the robots is NULL" << endl;
    }
    
    return NULL; //if both robots are NULL
}


int Robot::getDamage()
{
    // All robots inflict damage which is a random number up to their strength
    int damage = (rand() % strength) + 1; 

    return damage;
}

string Robot::getType()
{
    //return empty string
    return "";
}
