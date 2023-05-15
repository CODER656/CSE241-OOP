#include "roomba.h"

Roomba::Roomba()
{
    Robot(2, 3, 10, "Roomba"); //type, strength, hit, name
}

Roomba::Roomba(int newType, int newStrength, int newHit, string name)
{
    Robot(newType, newStrength, newHit, name); //type, strength, hit, name
}


//constructor
Roomba::Roomba(World *world, int x, int y, int newStrength,int newHit,string name) : Robot(world, x, y, newStrength, newHit, name)
{
}


//getDamage function overrides base class getDamage function
int Roomba::getDamage()
{
    int damage = Robot::getDamage();

    //roomba robots are very fast, so they get to attack twice.
    damage = damage * 2;
    
    return damage;
}


//getType function overrides base class getType function
string Roomba::getType()
{
    return "Roomba";
}
