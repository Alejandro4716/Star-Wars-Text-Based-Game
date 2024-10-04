//character class definition
//Alejndro Morel
//started 08/20
//last edited 09/14

#include "character.h"
#include "abilities.h"


//initializer to create character
    Character::Character (std::string playerName) {
        characterName = playerName; 
        health = 100; 
        maxHealth = health; 
        stamina = 300; 
        maxStamina = stamina; 
        strength = 1;
        dexterity = 1; 
        intelligence = 1; 
        experience = 0; 
        SP = 0;
        level = 0;
        counter = false; 
        abilities = {}; 
    }



    
    //getter functions 
    int Character::getHealth () const { return health; }
    int Character::getMaxHealth () const { return maxHealth; }
    
    int Character::getStamina () const { return stamina; }
    int Character::getMaxStamina () const { return maxStamina; }
    
    int Character::getStrength () const { return strength; }
    int Character::getIntelligence () const { return intelligence; }
    int Character::getDexterity () const { return dexterity; }
    
    int Character::getLevel () const { return level; }
    int Character::getSP () const { return SP; } 
    int Character::getExperience () const { return experience; }
    
    bool Character::getCounter () const { return counter; }
    int Character::getNumOfAbilities () const { return abilities.size(); }
    std::string Character::getName () const { return characterName; }


    //upgrade functions 
    void Character::upgradeMaxHealth (int amount) { maxHealth += amount*10; }
    void Character::upgradeMaxStamina (int amount) { maxStamina += amount*10; }
    
    void Character::upgradeStrength (int amount) { strength += amount; }
    void Character::upgradeIntelligence (int amount) { intelligence += amount; }
    void Character::upgradeDexterity (int amount) { dexterity += amount; }
    
    void Character::upgradeSP (int amount) { SP += amount; }



    //stamina and health functions 
    //used to increase the users health
    void Character::regenerateHealth (int amount) {
        health += amount;
        if (health > maxHealth)     //keeps health from being above max health
        	restoreHealth();  
    
        std::cout<< "Health recovered : " << amount <<std::endl;
        std::cout<< "Current health   : " << health <<std::endl;
        std::cout<<std::endl; 
        std::cout<<std::endl;
    }

    //restores user health 
    void Character::restoreHealth() {
	health = maxHealth; 
    }

    //depletes heatlh
    void Character::depleteHealth(int amount) {
	health -= amount;
 	
	if (health < 0)	//incase of character death
		health = 0; 
    }

    //used to increase the users stamina
    void Character::regenerateStamina (int amount) {
        stamina += amount;
        if (stamina > maxStamina)   //keeps stamina at/below max stamina
        	restoreStamina();
    
        std::cout<< "Stamina recovered : " << amount  <<std::endl; 
        std::cout<< "Current stamina   : " << stamina <<std::endl;
        std::cout<<std::endl; 
        std::cout<<std::endl;
    }

    //restores user stamina
    void Character::restoreStamina() { 
	stamina = maxStamina; 
    }

    //depletes stamina
    void Character::depleteStamina (int amount) { 
	stamina -= amount; 

	if (stamina < 0)		//incase stamina falls below 0 
		stamina = 0; 
    }



    //menu functions 
    //displays users stats
    void Character::displayStats () {
        
        std::cout<< "Name         : " << characterName << "\n";
        std::cout<< "Level        : " << level         << "\n"; 
        std::cout<< "Health       : " << health        << "\n";
        std::cout<< "Max Health   : " << maxHealth     << "\n"; 
        std::cout<< "Stamina      : " << stamina       << "\n"; 
        std::cout<< "Max Stamina  : " << maxStamina    << "\n";
        std::cout<< "Strength     : " << strength      << "\n";
        std::cout<< "Dexterity    : " << dexterity     << "\n"; 
        std::cout<< "Intelligence : " << intelligence  << "\n"; 
        std::cout<< "Experience   : " << experience    << "\n"; 
        std::cout<< "Skill Points : " << SP            << "\n"; 
        std::cout<<std::endl; 
        
        std::string input;   //used to ask user to exit display screen or upgrade stats
        std::cout<< "exit or upgrade?"<<std::endl; 
        std::cin>> input; 
        std::cout<<std::endl; 
        std::cout<<std::endl;        
        
        //calls function to upgrade stats
        if (input == "upgrade")
        allocateSkillPoints (); 
    }
    
    
    //used to upgrade the users stats via allocating skill points
    void Character::allocateSkillPoints () {
        std::string stat;               //which stat will be improved
        int amount;                     //how many skill points will be used
        bool allowUpgrade = false;      //validates stat to upgrade

        //while loop ensures an invalid entry allows the user to retry
        while (!allowUpgrade) {
            std::cout<< "Which stat would you like to increase?"<<std::endl; 
            std::cin>> stat;
            std::cout<< "Increase " << stat << " by ";
            std::cin>> amount;
            std::cout<<std::endl; 
            std::cout<<std::endl;
        
            if (amount > SP || amount < 0) {
                std::cout<< "Invalid amount used!"<<std::endl;
                std::cout<<std::endl; 
                std::cout<<std::endl;
                
                continue; //restarts loop if player has insufficient points
            }

            SP -= amount;   //skill points are used
        
            if (stat == "health") {
		upgradeMaxHealth (amount); 
		std::cout<<"Max health increased by : "<< amount*10<<std::endl;
		std::cout<<std::endl;
	    }
            if (stat == "stamina") {
                upgradeMaxStamina (amount); 
                std::cout<<"Max stamina increased by : "<< amount*10 <<std::endl;
                std::cout<<std::endl; 
                std::cout<<std::endl;
                
                allowUpgrade = true;    //exits while loop if stat is sucessfully upgraded
            }
            else if (stat == "strength") {
                upgradeStrength (amount); 
                std::cout<<"Strength increased by : "<< amount <<std::endl;
                std::cout<<std::endl; 
                std::cout<<std::endl;
                
                allowUpgrade = true;    //exits while loop if stat is sucessfully upgraded
            }
            else if (stat == "dexterity") {
                upgradeDexterity (amount); 
                std::cout<<"Dexterity increased by : "<< amount <<std::endl;
                std::cout<<std::endl; 
                std::cout<<std::endl;
                
                allowUpgrade = true;    //exits while loop if stat is sucessfully upgraded
            }
            else if (stat == "intelligence") {
                upgradeIntelligence (amount); 
                std::cout<<"intelligence increased by : "<< amount <<std::endl;
                std::cout<<std::endl; 
                std::cout<<std::endl;
                
                allowUpgrade = true;    //exits while loop if stat is sucessfully upgraded
            }
            else {
                std::cout<< "Invalid stat" <<std::endl;
                std::cout<<std::endl; 
                std::cout<<std::endl;
                SP += amount;   //returns skill points if upgrade is invalid
            }
        }
        displayStats();     //allows the user to upgrade another stat
    }





    //xp and leveling upc functions    
    //updates the users experience points
    void Character::gainExperience (int amount) {
        experience += amount; 
        std::cout<<"You gained " << amount << " experience" <<std::endl;  
        
        //if user has enough xp, user levels up
        if (experience >= 10) { 
            levelUp();
        }
    }
    
    //when a certain amount of xp is gained, allows the user to level up
    void Character::levelUp () {
        level++; 
	experience -= 10; 

        upgradeMaxHealth (1);            //leveling up increases stats
        upgradeMaxStamina (1);
        upgradeStrength (1); 
        upgradeDexterity(1); 
        upgradeIntelligence (1);

	restoreHealth(); 		//leveling up restores health/stamina
	restoreStamina();         

        std::cout<< "Level Up! You are now level : " << level <<std::endl;
        
        displayStats();         //shows user their new stats
    }
    



    //ability usage functions 
    //adds an ability to the character
    void Character::learnAbility (Ability* ability) {
        abilities.push_back(ability); 
    }
    
    //displays a character's abilities
    void Character::displayAbilities () const {
        for (int i=0; i < abilities.size(); i++){
            std::cout<< i+1 <<". "; 
            abilities[i] -> display();
        }
    }
    
    //function used during combat to execute an ability
    void Character::useAbility (int index, Character& opponent) {
        int zeroBasedIndex = index -1; 
            abilities[zeroBasedIndex]->use(*this, opponent);
    }

    //these functions turn counter on/off
    void Character::setCounterOn () { 
	counter = true; 
    }

    void Character::setCounterOff () {
	counter = false; 
    }
