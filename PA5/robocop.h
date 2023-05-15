#include "humanic.h"


class Robocop : public Humanic //inherit from Humanic
{
    public:
        Robocop();
        Robocop(int newType, int newStrength, int newHit,string name);
        Robocop(World* world,int x,int y,int Strenght,int hit,string name);

        int getDamage() override; //override
        string getType() override;
        
};