//C++ code to create a text based, star wars, adventure game
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

//forward declaration of Character class
class Character; 

//ability class as the base class for "abilites" or combat moves such as counter and saber strike
class Ability { 
    protected:
    //ability variables
    std::string abilityName;
    int staminaCost;        //how much stamina is required to perform ability
    int damageDealt;        //how much damage ability deals
    int healthRegen;        //how much health ability regenerates

    public:
    //constructor
    Ability (std::string name, int cost, int damage, int healing) : abilityName(name), staminaCost(cost), damageDealt(damage), healthRegen(healing) {}
    
    //deconstructor
    virtual ~Ability() = default; 
    
    //virtual function to use an ability
    virtual void use (Character& user, Character& opponent) = 0;
    
    //displays an abilities name
    void display() const {
        std::cout<< abilityName <<std::endl; 
    }
};

class Character {
    public:
    //character stats
    int health;                           //current health points of character
    int maxHealth;                        //maximum health points of character
    int stamina;                          //current stamina points of character
    int maxStamina;                       //maximum stamina points of character
    int strength;                         //strength of character
    int damage;                           //how much damage character does
    int dexterity;                        //how skillful a character is with a weapon/ability
    int intelligence;                     //intelligence level of character 
    int experience;                       //exp level used to increase character level
    int SP;                               //Skill points used to upgrade stats
    int level;                            //character level
    bool counter;                         //changes value to decide if character will counter
    std::vector <Ability*> abilities;     //stores the users abilites
    std::string characterName;            //name of character
    
    //initializer to create character
    Character (std::string playerName) {
        characterName = playerName; 
        health = 100; 
        maxHealth = health; 
        stamina = 300; 
        maxStamina = stamina; 
        strength = 10;
        damage = 1;
        dexterity = 10; 
        intelligence = 10; 
        experience = 0; 
        SP = 0;
        level = 0;
        counter = false; 
        abilities = {}; 
    };
    
    
    //displays users stats
    void displayStats () {
        
        std::cout<< "Name         : " << characterName << "\n";
        std::cout<< "Level        : " << level         << "\n"; 
        std::cout<< "Health       : " << health        << "\n";
        std::cout<< "Max Health   : " << maxHealth     << "\n"; 
        std::cout<< "Stamina      : " << stamina       << "\n"; 
        std::cout<< "Max Stamina  : " << maxStamina    << "\n";
        std::cout<< "Strength     : " << strength      << "\n";
        std::cout<< "Damage       : " << damage        << "\n";
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
    void regenerateHealth (int amount) {
        health += amount;
        if (health > maxHealth)               //keeps health at/below max health
        health = maxHealth; 
        
        std::cout<< "Health recovered : " << amount <<std::endl;
        std::cout<< "Current health   : " << health <<std::endl;
        std::cout<<std::endl; 
        std::cout<<std::endl;
    }
    
    //used to increase the users stamina
    void regenerateStamina (int amount) {
        stamina += amount;
        if (stamina > maxStamina)             //keeps stamina at/below max stamina
        stamina = maxStamina; 
        
        std::cout<< "Stamina recovered : " << amount  <<std::endl; 
        std::cout<< "Current stamina   : " << stamina <<std::endl;
        std::cout<<std::endl; 
        std::cout<<std::endl;
    }
    
    
    //used to upgrade the users stats via allocating skill points
    void allocateSkillPoints () {
        std::string stat;                     //which stat will be improved
        int amount;                           //how many skill points will be used
        bool allowUpgrade = false;            //validates stat to upgrade

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
                
                continue;                      //restarts loop if player has insufficient points
            }

            SP -= amount;                     //skill points are used
        
            if (stat == "stamina") {
                maxStamina += amount; 
                std::cout<<"Max stamina increased by : "<< amount <<std::endl;
                std::cout<<std::endl; 
                std::cout<<std::endl;
                
                allowUpgrade = true;          //exits while loop if stat is sucessfully upgraded
            }
            else if (stat == "strength") {
                strength += amount; 
                std::cout<<"Strength increased by : "<< amount <<std::endl;
                std::cout<<std::endl; 
                std::cout<<std::endl;
                
                allowUpgrade = true;          //exits while loop if stat is sucessfully upgraded
            }
            else if (stat == "dexterity") {
                dexterity += amount; 
                std::cout<<"Dexterity increased by : "<< amount <<std::endl;
                std::cout<<std::endl; 
                std::cout<<std::endl;
                
                allowUpgrade = true;          //exits while loop if stat is sucessfully upgraded
            }
            else if (stat == "intelligence") {
                intelligence += amount; 
                std::cout<<"intelligence increased by : "<< amount <<std::endl;
                std::cout<<std::endl; 
                std::cout<<std::endl;
                
                allowUpgrade = true;          //exits while loop if stat is sucessfully upgraded
            }
            else {
                std::cout<< "Invalid stat" <<std::endl;
                std::cout<<std::endl; 
                std::cout<<std::endl;
                SP += amount;                 //returns skill points if upgrade is invalid
            }
        }
        displayStats();                       //allows the user to upgrade another stat
    }
    
    //updates the users experience points
    void gainExperience (int amount) {
        experience += amount; 
        std::cout<<"You gained " << amount << " experience" <<std::endl;  
        
        //if user has enough xp, user levels up
        if (experience >= 10) {
            experience -= 10; 
            levelUp();
        }
    }
    
    //when a certain amount of xp is gained, allows the user to level up
    void levelUp () {
        level++; 
          maxHealth += 10;            //leveling up increases stats
        health = maxHealth; 
        maxStamina += 10;
        stamina = maxStamina; 
        strength += 5; 
        dexterity += 5; 
        intelligence += 5;
        
        std::cout<< "Level Up! You are now level : " << level <<std::endl;
        
        displayStats();             //shows user their new stats
    }
    
    //adds an ability to the character
    void learnAbility (Ability* ability) {
        abilities.push_back(ability); 
    }
    
    //displays a character's abilities
    void displayAbilities () const {
        for (int i=0; i < abilities.size(); i++){
            std::cout<< i+1 <<". "; 
            abilities[i] -> display();
        }
    }
    
    //function used during combat to execute an ability
    void useAbility (int index, Character& opponent) {
        int zeroBasedIndex = index -1; 
            abilities[zeroBasedIndex]->use(*this, opponent);
    }
};

//ability that can heal a player 
class ForceMeditation : public Ability {
    public:
       
    ForceMeditation () : Ability("Force Meditation", 15, 0, 30) {}
    
    void use(Character& user, Character& opponent) override {
        if (user.stamina >= staminaCost) {                      //ensures user has sufficient stamina
            user.regenerateHealth(healthRegen);                 //heals player
            user.stamina -= staminaCost;                        //depletes stamina
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
};

//combat ability, user shoot lightning at opponent, dealing damage
class ForceLightning : public Ability {
    public:

    ForceLightning () : Ability("Force Lightning", 20, 30, 0) {}
    
    void use (Character& user, Character& opponent) override {
        if (user.stamina >= staminaCost) {                      //ensure sufficient stamina
            opponent.health -= damageDealt;                     //deals damage
            user.stamina -= staminaCost;                        //depletes stamina
        if (opponent.health < 0)                
            opponent.health = 0;                                //ensures opponent health is not negative
            
            std::cout<< "RAAAAAAAAHHHHHHHHHHHHH!"<<std::endl;
            std::cout<< user.characterName << " electrocuted "<< opponent.characterName << std::endl;
            std::cout<< "Damage dealt: 30"<<std::endl;
            std::cout<<std::endl; 
            std::cout<<std::endl;
        }
        else {
            std::cout<< "Not enough stamina!"<<std::endl;
            std::cout<<std::endl; 
            std::cout<<std::endl;
        }
    }
};

//combat ability, user strikes opponent with lightsaber
class SaberStrike : public Ability {
    public: 

    SaberStrike () : Ability("Saber Strike", 10, 40, 0) {}
    
    void use (Character& user, Character& opponent) override {
        if (user.stamina >= staminaCost) {                        //ensure sufficient stamina
            
            if (opponent.counter) {                               //verifies if opponent will counter
                std::cout<< user.characterName << " used Saber Strike..."<<std::endl; 
                std::cout<< opponent.characterName << " dodged the attack! And countered with Saber Slash dealing "<< damageDealt << " damage" <<std::endl;
                std::cout<<std::endl; 
                std::cout<<std::endl;
                
                user.health -= damageDealt;                        //opponent counters
                opponent.counter = false;                          //prevents infinite countering
            }
            else {
                opponent.health -= damageDealt;                    //deals damage
                user.stamina -= staminaCost;                       //depletes stamina
        
                if (opponent.health < 0)
                    opponent.health = 0;                           //ensures opponenet health >= 0
            
                    std::cout<< "Saber Strike!"<<std::endl;
                    std::cout<< user.characterName << " struck "<< opponent.characterName << std::endl;
                    std::cout<< "Damage dealt: " << damageDealt <<std::endl;
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
};


class Counter : public Ability {
    public: 
        
    Counter () : Ability("Counter", 10, 0, 0) {}
    
    void use (Character& user, Character& opponent) override {
        if (user.stamina >= staminaCost) {                        //ensures sufficient stamina
            user.stamina -= staminaCost;                          //depletes stamina
            
            std::cout<< "Next attack will be countered!"<<std::endl; 
            std::cout<<std::endl; 
            std::cout<<std::endl;
            user.counter = true;                                  //turns counter TRUE, allowing opponent's next attack to be countered
        
        }
        else {
            std::cout<< "Not enough stamina!"<<std::endl;
            std::cout<<std::endl; 
            std::cout<<std::endl;
        }
    }
};


// function prototypes
//function used to simulate a fight between 2 characters
void duel (Character& user, Character& opponenet); 




int main () {
    //allows random numbers to be generated
    //used to randomize opponent moves
    srand(static_cast <unsigned int> (time(0)));
    
    std::string username;                                   //player can pick a username
    
    std::cout<<"Enter your name..."<<std::endl;
    std::cin>> username; 
    
    Character MyPlayer(username);                           //creates user's character
    Character Vader("Darth Vader");                         //creates Darth Vader
    
    //sets pointers to dynamically allocated abilities
    Ability* meditation = new ForceMeditation(); 
    Ability* strike = new SaberStrike(); 
    Ability* lightning = new ForceLightning();
    Ability* counter = new Counter(); 

    //characters learn abilities
    MyPlayer.learnAbility(strike); 
    MyPlayer.learnAbility(lightning);
    MyPlayer.learnAbility(counter);
    MyPlayer.learnAbility(meditation);
    Vader.learnAbility(strike);

    //shows the user their stats
    MyPlayer.displayStats();
    
    //text art of Darth vader
    std::cout<<".                     .-.                   "<<std::endl; 
    std::cout<<"                     |_:_|                  "<<std::endl;
    std::cout<<"                    /(_Y_)\\                "<<std::endl;
    std::cout<<"                   ( \\/M\\/ )              "<<std::endl;
    std::cout<<" '.              _.'-/'-'-\\-'._            "<<std::endl;
    std::cout<<"  ':           _/.--'[[[[]'--. \\_          "<<std::endl;
    std::cout<<"    ':       /_'  : |:::| :  '.  \\         "<<std::endl;
    std::cout<<"      ':    //   ./ |oUU| \\.  :  \\        "<<std::endl;
    std::cout<<"        ':  _:'..' \\_|___|_/ :    :|       "<<std::endl;
    std::cout<<"          ':.  .'  |_[___]_|  :.':  \\      "<<std::endl;
    std::cout<<"           [::\\ |  :  | |  :   ; :   \\    "<<std::endl;
    std::cout<<".           '-'   \\/'.| |.' \\  .;.'  |    "<<std::endl;
    std::cout<<"           |\\_    \\  '-'   :         |    "<<std::endl;
    std::cout<<"           |  \\    \\ .:    :   |     |    "<<std::endl;
    std::cout<<"           |   \\    | '.   :    \\    |    "<<std::endl;
    std::cout<<".          /       \\   :. .;          |    "<<std::endl;
    std::cout<<"          /     |   |  :__/     :  \\ \\    "<<std::endl;
    std::cout<<"         |  |   |    \\:   | \\   |    ||   "<<std::endl;
    std::cout<<"        /    \\  : :  |:   /  |__|   / |    "<<std::endl;
    std::cout<<".      |     : : :_/_|  /'._\\  '--|_ \\    "<<std::endl;
    std::cout<<"       /___.-/_|-'   \\  \\                 "<<std::endl;
    std::cout<<"                     '-'                    "<<std::endl;


    //simulates a duel between the user and darth vader
    duel (MyPlayer, Vader); 
    
    
    
    
    
    
    //deallocates memory of abilities
    delete meditation; 
    delete strike; 
    delete lightning; 
    

    return 0; 
}

//function definitions
//duel function simulates a fight
void duel (Character& user, Character& opponent) {
    int turnCounter=0;                                 //turn based battles require turns to be tracked
    int index;                                         //used to choose ability
    bool validity = false;                             //ensures user picks a valid ability

    //while loop ensures duel ends when user or opponent dies
    while (user.health > 0 && opponent.health > 0) { 
    
        //user goes when turn counter is even
        //turn counter starts at 0 allowing user to go first
        if (turnCounter%2 == 0) {
           
            while (!validity) {
                user.displayAbilities();                //helps user choose ability
                std::cout<< "Choose Ability: "; 
                std::cin>> index;                       //user's chosen ability
                
                //verifies index is valid
                if (index > 0 && index <= user.abilities.size()) {
                    validity = true;                    //ends loop if valid ability is chosen
                }
                else {
                    std::cout<<"Invalid selection. Choose Ability"<<std::endl;
                }
                
                std::cout<<std::endl; 
                std::cout<<std::endl;
                
            }
            validity = false;                           //allows loop to restart next turn
            user.useAbility(index, opponent);   //uses chosen ability
           
            turnCounter++;                              //gives opponent the next turn
        }
        else {          //opponent moves
            index = 1 + rand() % 1;                     //random number generate chooses move
            
            opponent.useAbility(index, user);   //uses move
            
            turnCounter++;                              //next turn
        }
        
    }
    
    if (user.health <= 0) {                                           //message when user is defeated
        std::cout<<"You died!"<<std::endl;
        std::cout<<std::endl; 
        std::cout<<std::endl;
    }
    else {                                                            //message when opponent is defeated
        std::cout<<opponent.characterName<< " died!"<<std::endl;
        std::cout<<std::endl; 
        std::cout<<std::endl;
    }
};


   
