//ability class and derived classes function defintions
//Alejandro Morel
//date started 08/20
//last edited 09/14

#include "abilities.h"
#include "character.h"

    //ability intializer
    Ability::Ability (std::string name, int cost, int dAmount, int hAmount) 
	: abilityName(name), staminaCost(cost), damage(dAmount), heal(hAmount) {}
        
    //displays an abilities name
    void Ability::display() {
        std::cout<<  this->abilityName <<std::endl; 
    } 






    //force meditation class definitions
    ForceMeditation::ForceMeditation () : Ability("Force Meditation", 15, 0, 10) {}
    
    void ForceMeditation::use(Character& user, Character& opponent) {

	int healingAmt = heal * user.getIntelligence(); 

        if (user.getStamina() >= staminaCost) {          //ensures user has sufficient stamina
            user.regenerateHealth (healingAmt);      //heals player
            user.depleteStamina (staminaCost);            //depletes stamina
 
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

	int damageAmt = damage * user.getStrength(); 

        if (user.getStamina() >= staminaCost) {      //ensure sufficient stamina
            opponent.depleteHealth (damageAmt);     //deals damage
            user.depleteStamina (staminaCost);        //depletes stamina

           
            std::cout<< "RAAAAAAAAHHHHHHHHHHHHH!"<<std::endl;
            std::cout<< user.getName() << " electrocuted "<< opponent.getName() << std::endl;
            std::cout<< "Damage dealt: "<< damageAmt <<std::endl;
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

        if (user.getStamina() >= staminaCost) {  //ensure sufficient stamina
            
            if (opponent.getCounter()) {       //verifies if opponent will counter

		int damageAmt = damage * opponent.getDexterity(); 

                std::cout<< user.getName() << " used Saber Strike..."<<std::endl; 
                std::cout<< opponent.getName() << " dodged the attack! And countered with Saber Slash dealing "<< damageAmt << " damage" <<std::endl;
                std::cout<<std::endl; 
                std::cout<<std::endl;
                
                user.depleteHealth (damageAmt); //opponent counters

                opponent.setCounterOff();     //prevents infinite countering
            }
            else {

		int damageAmt = damage * user.getDexterity(); 

                opponent.depleteHealth (damageAmt); //deals damage
                user.depleteStamina (staminaCost);    //depletes stamina
        

                    std::cout<< "Saber Strike!"<<std::endl;
                    std::cout<< user.getName() << " struck "<< opponent.getName() << std::endl;
                    std::cout<< "Damage dealt: " << damageAmt <<std::endl;
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
        if (user.getDexterity() >= 3) {

            if (user.getStamina() >= staminaCost) {      //ensures sufficient stamina

                user.depleteStamina (staminaCost);        //depletes stamina
            
                std::cout<< "Next attack will be countered!"<<std::endl; 
                std::cout<<std::endl; 
                std::cout<<std::endl;
                user.setCounterOn();   //turns counter TRUE, allowing opponent's next attack to be countered
        
            }
            else {
                std::cout<< "Not enough stamina!"<<std::endl;
                std::cout<<std::endl; 
                std::cout<<std::endl;
            }
        }
    }
