//Character class .h file for the star wars text based adventure game
//Alejandro Morel
//date started 08/20
//last edited 09/14

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <vector>
#include <string>

class Ability;




class Character {
    public:
    //character stats
    int health;    
    int maxHealth;    
    int stamina;    
    int maxStamina;    
    int strength;                       //impacts force attacks
    int dexterity;                      //impacts lightsaber moves and counter
    int intelligence;                   //impacts healing abilities
    int experience;    
    int SP;                             //Skill points used to upgrade stats
    int level;    
    bool counter;                       //changes value to decide if character will counter
    std::vector <Ability*> abilities;   //stores the users abilites
    std::string characterName;    
    
    //user character initializer 
    Character (std::string playerName); 
    

    //charcter functions
    void displayStats ();    
    
    void regenerateHealth (int amount);    
    
    void regenerateStamina (int amount);    

    void allocateSkillPoints ();                        //used to upgrade player

    void gainExperience(int amount);    
    
    void levelUp ();                                    //if enough xp is gained, used to level up
    
    void learnAbility (Ability* ability);               //used to add abilities
    
    void displayAbilities () const;    

    void useAbility (int index, Character& opponent);
};

#endif //CHARACTER_H

