#include "robocop.h"

Robocop::Robocop()
{
    Humanic(4,30,40,"Robocop");
}


Robocop::Robocop(int newType, int newStrength, int newHit, string name)
{
    Humanic(newType, newStrength, newHit, name);
}

Robocop::Robocop(World *world, int x, int y, int Strenght, int hit, string name) : Humanic(world, x, y, Strenght, hit, name)
{
    
}



int Robocop::getDamage()
{
    int damage = Humanic::getDamage(); //call the base class getDamage()
    return damage;
}


string Robocop::getType()
{
    return "Robocop"; //return the type of the robot
}
