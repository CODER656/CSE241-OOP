#include "robot.h"


class Roomba : public Robot
{
    public:
        Roomba();
        Roomba(int newType, int newStrength, int newHit,string name);
        Roomba(World* world,int x,int y,int newStrength,int newHit,string name);

        int getDamage() override; //override
        string getType() override; //override
};
