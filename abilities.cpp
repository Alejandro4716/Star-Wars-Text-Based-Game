//ability class and derived classes function defintions
//Alejandro Morel
//date started 08/20
//last edited 09/14

#include "abilities.h"
#include "character.h"

    //ability intializer
    Ability::Ability (std::string name, int cost, int damage, int healing) 
        : abilityName(name), staminaCost(cost), damageDealt(damage), healthRegen(healing) {}
    
    //displays an abilities name
    void Ability::display() {
        std::cout<<  this->abilityName <<std::endl; 
    }   


    //force meditation class definitions
    ForceMeditation::ForceMeditation () : Ability("Force Meditation", 15, 0, 10) {}
    
    void ForceMeditation::use(Character& user, Character& opponent) {
        if (user.stamina >= staminaCost) {          //ensures user has sufficient stamina
            user.regenerateHealth(healthRegen*user.intelligence);      //heals player
            user.stamina -= staminaCost;            //depletes stamina
        if (user.health > user.maxHealth)
            user.health = user.maxHealth; 
            std::cout<<std::endl; 
            std::cout<<std::endl;
        }   
        else {
            std::cout<< "Not enough stamina!"<<std::endl;
            std::cout<<std::endl; 
            std::cout<<std::endl;
        }   
    }   

    //force lightning class def
    ForceLightning::ForceLightning () : Ability("Force Lightning", 40, 10, 0) {}
    
    void ForceLightning::use (Character& user, Character& opponent) {
        if (user.stamina >= staminaCost) {      //ensure sufficient stamina
            opponent.health -= damageDealt*user.strength;     //deals damage
            user.stamina -= staminaCost;        //depletes stamina
        if (opponent.health < 0)    
            opponent.health = 0;    //ensures opponent health is not negative
    
            std::cout<< "RAAAAAAAAHHHHHHHHHHHHH!"<<std::endl;
            std::cout<< user.characterName << " electrocuted "<< opponent.characterName << std::endl;
            std::cout<< "Damage dealt: "<< damageDealt*user.strength<<std::endl;
            std::cout<<std::endl; 
            std::cout<<std::endl;
        }   
        else {
            std::cout<< "Not enough stamina!"<<std::endl;
            std::cout<<std::endl;
            std::cout<<std::endl;
        }
    }


   //saber strike class def
   SaberStrike::SaberStrike () : Ability("Saber Strike", 20, 10, 0) {}

    void SaberStrike::use (Character& user, Character& opponent) {
        if (user.stamina >= staminaCost) {  //ensure sufficient stamina

            if (opponent.counter) {       //verifies if opponent will counter
                std::cout<< user.characterName << " used Saber Strike..."<<std::endl;
                std::cout<< opponent.characterName << " dodged the attack! And countered with Saber Slash dealing "<< damageDealt*opponent.dexterity << " damage" <<std::endl;
                std::cout<<std::endl;
                std::cout<<std::endl;

                user.health -= damageDealt*opponent.dexterity; //opponent counters
                opponent.counter = false;     //prevents infinite countering
            }
            else {
                opponent.health -= damageDealt*user.strength; //deals damage
                user.stamina -= staminaCost;    //depletes stamina

                if (opponent.health < 0)
                    opponent.health = 0;    //ensures opponenet health >= 0

                    std::cout<< "Saber Strike!"<<std::endl;
                    std::cout<< user.characterName << " struck "<< opponent.characterName << std::endl;
                    std::cout<< "Damage dealt: " << damageDealt*user.dexterity <<std::endl;
                    std::cout<<std::endl;
                    std::cout<<std::endl;
            }
        }
        else {
            std::cout<< "Not enough stamina!"<<std::endl;
            std::cout<<std::endl;
            std::cout<<std::endl;
        }
    }

    //coutner class def
    Counter::Counter () : Ability("Counter", 10, 0, 0) {}

    void Counter::use (Character& user, Character& opponent) {
        if (user.dexterity >= 3) {
            if (user.stamina >= staminaCost) {      //ensures sufficient stamina
                user.stamina -= staminaCost;        //depletes stamina

                if (opponent.health < 0)
                    opponent.health = 0;    //ensures opponenet health >= 0

                    std::cout<< "Saber Strike!"<<std::endl;
                    std::cout<< user.characterName << " struck "<< opponent.characterName << std::endl;
                    std::cout<< "Damage dealt: " << damageDealt*user.dexterity <<std::endl;
                    std::cout<<std::endl;
                    std::cout<<std::endl;
            }
        }
        else {
            std::cout<< "Not enough stamina!"<<std::endl;
            std::cout<<std::endl;
            std::cout<<std::endl;
        }
    }

    //coutner class def
    Counter::Counter () : Ability("Counter", 10, 0, 0) {}

    void Counter::use (Character& user, Character& opponent) {
        if (user.dexterity >= 3) {
            if (user.stamina >= staminaCost) {      //ensures sufficient stamina
                user.stamina -= staminaCost;        //depletes stamina

                std::cout<< "Next attack will be countered!"<<std::endl;
                std::cout<<std::endl;
                std::cout<<std::endl;
                user.counter = true;        //turns counter TRUE, allowing opponent's next attack to be countered

            }
            else {
                std::cout<< "Not enough stamina!"<<std::endl;
                std::cout<<std::endl;
                std::cout<<std::endl;
            }
        }
    }
                                                                                                                       118,5         Bot

