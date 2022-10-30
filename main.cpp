#include <iostream>
#include "string"

#include "Character.h"
#include "Ability.h"
#include "Game.h"

int main()
{
    std::cout << "Hello and welcome to Bryce's Game" << std::endl;

    //gets the users name and sets it for the player
    std::string name;
    std::cout << "Please enter your name: ";
    std::cin >> name;
    //creates the game
    Game game(name);
    std::cout<<std::endl;

    //allows the user to select their class
    std::cout<<"Select Class:"<<std::endl;
    std::cout<<"Assassin: '1'    Warrior: '2'    Tank: '3'    Marksman: '4'"<<std::endl;
    char c;
    std::cin>>c;
    std::cout<<std::endl;


    //creates the player from the selected class
    int j=1;
    while (j==1)
    {
        if(game.CreatePlayer(c))
        {
            j=0;
        }
        else
        {
            std::cout<<"Invalid entry. Please enter a valid class: ";
            std::cin>>c;
        }
    }


    //adds the enemies to the game
    Character enemy1("Judge the Farmer",500,40);
    //creates the ability and adds it to the player
    std::string a="Pitchfork Thrust";
    int dmg=80;
    int cost=2;
    auto ability=std::make_shared<Ability>(a,dmg,cost);
    enemy1.SetAbility(ability);
    game.AddEnemy(&enemy1);
    Character enemy2("Danny the Great",650,65);
    a="Headbutt";
    dmg=90;
    cost=2;
    ability=std::make_shared<Ability>(a,dmg,cost);
    enemy2.SetAbility(ability);
    game.AddEnemy(&enemy2);
    Character enemy3("Saquon the King",1000,50);
    a="Quad Stomp";
    dmg=120;
    cost=3;
    ability=std::make_shared<Ability>(a,dmg,cost);
    enemy3.SetAbility(ability);
    game.AddEnemy(&enemy3);

    //the game, player and enemies have been created so now use play to begin the fights
    game.Play();

    return 0;
}
