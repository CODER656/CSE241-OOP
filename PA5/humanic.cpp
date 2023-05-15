#include "humanic.h"

Humanic::Humanic()
{
    //deliberately empty
}


Humanic::Humanic(int newType, int newStrength, int newHit, string name)
{
    Robot(newType, newStrength, newHit, name);
}


Humanic::Humanic(World *world, int x, int y,int strength,int hit, string name) : Robot(world, x, y, strength, hit, name)
{
}

int Humanic::getDamage()
{
    int damage = Robot::getDamage();

    //humanic robots have a 10% chance of inflicting a tactical 
    //nuke attack which is an additional 50 damage points.
    int chance = rand() % 10 + 1;

    if (chance == 1) 
        damage = damage + 50; //tactical nuke attack
    
    return damage; 
}


string Humanic::getType()
{
    return "Humanic";
}
