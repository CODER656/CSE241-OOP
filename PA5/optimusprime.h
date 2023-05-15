#include "humanic.h"


class OptimusPrime : public Humanic //inherit from Humanic
{
    public:
        OptimusPrime();
        OptimusPrime(int newType, int newStrength, int newHit,string name);
        OptimusPrime(World* world,int x,int y,int Strenght, int hit,string name);

        int getDamage() override;
        string getType() override;
        
};