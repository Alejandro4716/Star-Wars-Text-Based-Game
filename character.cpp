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

    //used to increase the users health
    void Character::regenerateHealth (int amount) {
        health += amount;
        if (health > maxHealth)     //keeps health at/below max health
        health = maxHealth;

        std::cout<< "Health recovered : " << amount <<std::endl;
        std::cout<< "Current health   : " << health <<std::endl;
        std::cout<<std::endl;
        std::cout<<std::endl;
    }

    //used to increase the users stamina
    void Character::regenerateStamina (int amount) {
        stamina += amount;
        if (stamina > maxStamina)   //keeps stamina at/below max stamina
        stamina = maxStamina;

        std::cout<< "Stamina recovered : " << amount  <<std::endl;
        std::cout<< "Current stamina   : " << stamina <<std::endl;
        std::cout<<std::endl;
        std::cout<<std::endl;
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
                maxHealth += amount*10;
                std::cout<<"Max health increased by : "<< amount*10<<std::endl;
                std::cout<<std::endl;
            }
            if (stat == "stamina") {
                maxStamina += amount*10;
                std::cout<<"Max stamina increased by : "<< amount*10 <<std::endl;
                std::cout<<std::endl;
                std::cout<<std::endl;

                allowUpgrade = true;    //exits while loop if stat is sucessfully upgraded
            }
            else if (stat == "strength") {
                strength += amount;
                std::cout<<"Strength increased by : "<< amount <<std::endl;
                std::cout<<std::endl;
                std::cout<<std::endl;

                allowUpgrade = true;    //exits while loop if stat is sucessfully upgraded
            }
            else if (stat == "dexterity") {
                dexterity += amount;
                std::cout<<"Dexterity increased by : "<< amount <<std::endl;
                std::cout<<std::endl;
                std::cout<<std::endl;

                allowUpgrade = true;    //exits while loop if stat is sucessfully upgraded
            }
            else if (stat == "intelligence") {
                intelligence += amount;
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

    //updates the users experience points
    void Character::gainExperience (int amount) {
        experience += amount;
        std::cout<<"You gained " << amount << " experience" <<std::endl;

        //if user has enough xp, user levels up
        if (experience >= 10) {
            experience -= 10;
            levelUp();
        }
    }

    //when a certain amount of xp is gained, allows the user to level up
    void Character::levelUp () {
        level++;
        maxHealth += 10;            //leveling up increases stats
        health = maxHealth;
        maxStamina += 10;
        stamina = maxStamina;
        strength += 1;
        dexterity += 1;
        intelligence += 1;

        std::cout<< "Level Up! You are now level : " << level <<std::endl;

        displayStats();         //shows user their new stats
    }
    
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



