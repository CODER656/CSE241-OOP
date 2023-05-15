#include "robot.h"




class Bulldozer : public Robot
{
    public:
        Bulldozer();
        Bulldozer(int newType, int newStrength, int newHit,string name);
        Bulldozer(World* world,int x,int y,int strength,int hit,string name);

        int getDamage() override;
        string getType() override;

};
