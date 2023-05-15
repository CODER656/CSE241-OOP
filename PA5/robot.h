#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;


class World;

class Robot //base class
{
    friend class World; //world can access private members of robot

    public:
        Robot(); //default constructor
        //Diffrent constructors for diffrent needs
        Robot(int newType, int newStrength, int newHit,string name);
        Robot(World* world,int x,int y);
        Robot(World* wrld,int x,int y,string name);
        Robot(World *world,int x,int y, int newStrength, int newHit, string name);
        Robot(World *world, int newType, int newStrength, int newHit, string name);
        Robot(World *world, int newType, int newStrength, int newHit);

        //getters and setters
        string getName();
        int getStrength();
        int getHitpoints();
        int GetX();
        int GetY();

        void setStrength(int newStrength);
        void setType(int newType);
        void setHitpoints(int newHit);
        void setName(string newName);
        
        //other methods
        void move(); //moves the robot
        Robot* fight(Robot *attacker, Robot *victim); //returns winner
      

        virtual int getDamage(); //returns damage
        virtual string getType(); //returns type


    private:
        int type; // type of robot
        int strength; // strength of robot
        int hitpoints; // hitpoints of robot
        string name; // name of robot
        int x,y; // coordinates of robot
        bool moved; // if robot moved or not
        World* world; // pointer to world

};


#endif