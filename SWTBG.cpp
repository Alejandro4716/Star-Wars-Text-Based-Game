//text based adventure game inspired by the star wars universe 
//Alejandro Morel
//date started 08/20
//last edited 09/14


#include "character.h"
#include "abilities.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

// function prototypes
//function used to simulate a fight between 2 characters
void duel (Character& user, Character& opponenet);




int main () {
    //allows random numbers to be generated
    //used to randomize opponent moves
    srand(static_cast <unsigned int> (time(0)));

    std::string username;       //player can pick a username

    std::cout<<"Enter your name..."<<std::endl;
    std::cin>> username;

    Character MyPlayer(username);           //creates user's character
    Character Vader("Darth Vader");         //creates Darth Vader

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
    int turnCounter=0;      //turn based battles require turns to be tracked
    int index;              //used to choose ability
    bool validity = false;  //ensures user picks a valid ability

    //while loop ensures duel ends when user or opponent dies
    while (user.health > 0 && opponent.health > 0) {

        //user goes when turn counter is even
        //turn counter starts at 0 allowing user to go first
        if (turnCounter%2 == 0) {

            while (!validity) {
                user.displayAbilities();        //helps user choose ability
                std::cout<< "Choose Ability: ";
                std::cin>> index;               //user's chosen ability

                //verifies index is valid
                if (index > 0 && index <= user.abilities.size()) {
                    validity = true;  //ends loop if valid ability is chosen
                }
                else {
                    std::cout<<"Invalid selection. Choose Ability"<<std::endl;
                }

                std::cout<<std::endl;
                std::cout<<std::endl;

            }
            validity = false;       //allows loop to restart next turn
            user.useAbility(index, opponent);   //uses chosen ability

            turnCounter++;          //gives opponent the next turn
        }
        else {          //opponent moves
            index = 1 + rand() % 1;     //random number generate chooses move

            opponent.useAbility(index, user);   //uses move

            turnCounter++;              //next turn
        }

    }

    if (user.health <= 0) {                     //message when user is defeated
        std::cout<<"You died!"<<std::endl;
        std::cout<<std::endl;
        std::cout<<std::endl;
    }
    else {              //message when opponent is defeated
        std::cout<<opponent.characterName<< " died!"<<std::endl;
        std::cout<<std::endl;
        std::cout<<std::endl;
    }
};
                                         
