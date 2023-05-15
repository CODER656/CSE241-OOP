#ifndef HUMANIC_H
#define HUMANIC_H


#include "robot.h"


//humanic robots have a 10% chance of inflicting a tactical 
//nuke attack which is an additional 50 damage points.
//Optimusprime and robocop are humanic.
//With a 15% chance optimusprime robots inflict a strong 
//attack that doubles the normal amount of damage.


class Humanic : public Robot
{
    public:
        Humanic();
        Humanic(int newType, int newStrength, int newHit,string name);
        Humanic(World* world,int x,int y,int strength,int hit,string name);

        int getDamage() override;
        string getType() override;
        
};

#endif
