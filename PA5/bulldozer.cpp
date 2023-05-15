#include "bulldozer.h"



Bulldozer::Bulldozer()
{
    Robot(1,50,200,"Bulldozer");
}


Bulldozer::Bulldozer(int newType, int newStrength, int newHit, string name)
{
    //use base class constructor
    Robot(newType, newStrength, newHit, name);
}


Bulldozer::Bulldozer(World *world, int x, int y,int strength,int hit, string name) : Robot(world, x, y, strength, hit, name)
{
}

int Bulldozer::getDamage()
{
    int damage = Robot::getDamage();
    return damage;
}


string Bulldozer::getType()
{
    return "Bulldozer";
}

