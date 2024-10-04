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
    private:
    //character stats
    int health;         	
    int maxHealth;      	
    int stamina;        	
    int maxStamina;     		
    int strength;       		//impacts force attacks
    int dexterity;      		//impacts lightsaber moves and counter
    int intelligence;   		//impacts healing abilities
    int experience;     		
    int SP;            		 	//Skill points used to upgrade stats
    int level;          		
    bool counter;         		//changes value to decide if character will counter
    std::vector <Ability*> abilities; 	//stores the users abilites
    std::string characterName;  	
    
    public:
    //user character initializer 
    Character (std::string playerName);	
    

    //charcter functions

    //get functions 
    int getHealth () const; 
    int getMaxHealth () const; 
    int getStamina () const; 
    int getMaxStamina () const; 
    int getStrength () const; 
    int getIntelligence () const; 
    int getDexterity () const; 
    int getLevel () const; 
    int getSP() const; 
    int getExperience () const;
    bool getCounter () const;  
    int getNumOfAbilities () const; 
    std::string getName () const; 
    
    //upgrade functions 
    void upgradeMaxHealth (int amount); 
    void upgradeMaxStamina (int amount); 
    void upgradeStrength (int amount); 
    void upgradeIntelligence (int amount); 
    void upgradeDexterity (int amount); 
    void upgradeSP (int amount);   	
			
    //regenerative functions       
    void regenerateHealth (int amount);			
    void restoreHealth ();  
    void depleteHealth (int amount); 
    void regenerateStamina (int amount); 		
    void restoreStamina ();
    void depleteStamina (int amount);  

    //menu functions
    void displayStats (); 
    void allocateSkillPoints ();			//used to upgrade player

    //xp and leveling up functions
    void gainExperience(int amount);			
    void levelUp ();					//if enough xp is gained, used to level up
    
    //ability usage functions
    void learnAbility (Ability* ability);		//used to add abilities
    void displayAbilities () const;		
    void useAbility (int index, Character& opponent); 
    void setCounterOn (); 
    void setCounterOff (); 
};

#endif //CHARACTER_H
