//ability base class and derived classes
//Alejandro Morel
//started 08/20
//last editied 09/14

#ifndef ABILITY_H
#define ABILITY_H

#include <iostream>
#include <string>

class Character; 

//ability class as the base class for abilites or combat moves such as counter and saber strike
class Ability { 
    protected:
    //ability variables
    std::string abilityName;
    int staminaCost;        //how much stamina is required to perform ability
    int damage;        //how much damage ability deals
    int heal;        //how much health ability regenerates

    public:
    //constructor
    Ability (std::string name, int cost, int damage, int healing); 
    
    //deconstructor
    virtual ~Ability() = default; 
    
    //virtual function to use an ability
    virtual void use (Character& user, Character& opponent) = 0;
    
    //displays an abilities name
    void display(); 
};






//ability that can heal a player 
class ForceMeditation : public Ability {
    public:
    ForceMeditation ();
    void use(Character& user, Character& opponent) override;
};




//combat ability, user shoot lightning at opponent, dealing damage
class ForceLightning : public Ability {
    public:
    ForceLightning ();
    void use (Character& user, Character& opponent) override;
};




//combat ability, user strikes opponent with lightsaber
class SaberStrike : public Ability {
    public: 
    SaberStrike ();
    void use (Character& user, Character& opponent) override;
};




//counters negates damage and strikes opponents if non force ability is used
class Counter : public Ability {
    public:     
    Counter ();
    void use (Character& user, Character& opponent) override;    
};

#endif //ABILITY_H
