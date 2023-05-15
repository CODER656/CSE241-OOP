#include "optimusprime.h"

OptimusPrime::OptimusPrime()
{
    Humanic(3,100,100,"OptimusPrime");
}

OptimusPrime::OptimusPrime(int newType, int newStrength, int newHit, string name)
{
    //use base class constructor
    Humanic(newType, newStrength, newHit, name);
}


OptimusPrime::OptimusPrime(World *world, int x, int y,int Strenght, int hit, string name) : Humanic(world, x, y, Strenght, hit, name)
{
}

int OptimusPrime::getDamage()
{
    int damage = Humanic::getDamage();
    //With a 15% chance optimusprime robots inflict a 
    //strong attack that doubles the normal amount of damage.
    int chance = rand() % 100 + 1;
    if (chance <= 15)
    {
        damage = damage * 2;
    }

    return damage;
}

string OptimusPrime::getType()
{
    return "OptimusPrime";
}
