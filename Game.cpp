/**
 * @file Game.cpp
 * @author Bryce Cooperkawa
 */

#include <iostream>
#include "string"

#include "Ability.h"
#include "Game.h"
#include "Character.h"

/**
 * Constructor for the game
 * @param name the players name
 */
Game::Game(std::string name) : mPlayer(name,500,50)
{
}

/**
 * Creates the player character based on the chosen class
 * @param select the selected class
 * @return true if successful in creation
 */
bool Game::CreatePlayer(char select)
{
    //assassin
    if (select=='1')
    {
        std::cout<<"Assassin selected! Assassins have lower health but their basic attacks cost no energy."<<std::endl;
        std::cout<<"Ability: 'Backstab' costs 3 energy and poisons the enemy!" <<std::endl;
        std::cout<<std::endl;
        //sets the correct health, ad
        mPlayer.SetHealth(450);
        mPlayer.SetAD(40);
        //creates the ability and adds it to the player
        std::string name="Backstab";
        int dmg=200;
        int cost=3;
        auto ability=std::make_shared<Ability>(name,dmg,cost);
        mPlayer.SetAbility(ability);
        mPlayer.SetAttackCost(0);
        mPlayer.SetPoison(true);
        return true;
    }
    //warrior
    else if (select=='2')
    {
        std::cout<<"Warrior selected! Warriors are the most well rounded class with good health and good attack damage."<<std::endl;
        std::cout<<"Ability: 'Slash' costs 2 energy and damages enemy!" <<std::endl;
        std::cout<<std::endl;
        //sets the correct health, ad
        mPlayer.SetHealth(550);
        mPlayer.SetAD(70);
        //creates the ability and adds it to the player
        std::string name="Slash";
        int dmg=75;
        int cost=2;
        auto ability=std::make_shared<Ability>(name,dmg,cost);
        mPlayer.SetAbility(ability);
        return true;
    }
    //tank
    else if (select=='3')
    {
        std::cout<<"Tank selected! Tanks have high health but don't do as much damage."<<std::endl;
        std::cout<<"Ability: 'Body Slam' costs 3 energy and paralyzes the enemy!" <<std::endl;
        std::cout<<std::endl;
        //sets the correct health, ad
        mPlayer.SetHealth(800);
        mPlayer.SetAD(50);
        //creates the ability and adds it to the player
        std::string name="Body Slam";
        int dmg=35;
        int cost=3;
        auto ability=std::make_shared<Ability>(name,dmg,cost);
        mPlayer.SetAbility(ability);
        mPlayer.SetParalyze(true);
        return true;
    }
    //marksman
    else if (select=='4')
    {
        std::cout<<"Marksman selected! Marksman are glass cannons with low health but high damage."<<std::endl;
        std::cout<<"Ability: 'Headshot' costs 3 energy and does huge damage!" <<std::endl;
        std::cout<<std::endl;
        //sets the correct health, ad
        mPlayer.SetHealth(300);
        mPlayer.SetAD(80);
        //creates the ability and adds it to the player
        std::string name="Headshot";
        int dmg=300;
        int cost=3;
        auto ability=std::make_shared<Ability>(name,dmg,cost);
        mPlayer.SetAbility(ability);
        return true;
    }
    //invalid input handler
    else
    {
        return false;
    }
}

/**
 * Allows the characters to fight
 * @param player the player character
 * @param enemy the enemy character
 * @return true if the player wins false if they lose
 */
bool Game::Fight(Character* player, Character* enemy)
{
    std::cout<<player->GetName() + " vs. " + enemy->GetName()<<std::endl;
    std::cout<<std::endl;
    std::cout<<"BEGIN"<<std::endl;
    std::cout<<std::endl;

    //get both characters max health/energy to help with displaying it later
    int maxHealthPlayer=player->GetHealth();
    int maxHealthEnemy=enemy->GetHealth();
    int maxEnergyPlayer=player->GetEnergy();
    int maxEnergyEnemy=enemy->GetEnergy();

    //this loop is the actual fight
    //loops until one player is "dead"
    while(player->GetHealth()>0 && enemy->GetHealth()>0)
    {
        //display the current status of the player and the enemy
        //enemy
        std::cout<<enemy->GetName()<<":"<<std::endl;
        std::cout<<enemy->GetHealth()<<"/"<<maxHealthEnemy<<"   Energy: "<<
        enemy->GetEnergy()<<"/"<<maxEnergyEnemy<<std::endl;

        //player
        std::cout<<player->GetName()<<":"<<std::endl;
        std::cout<<player->GetHealth()<<"/"<<maxHealthPlayer<<"   Energy: "<<
                 player->GetEnergy()<<"/"<<maxEnergyPlayer<<std::endl;

        //allows the player to play, choose between attack, ability, or rest
        std::cout<<"Your move:"<<std::endl;
        std::cout<<"Attack: 'a'    Ability: 'q'    Rest: 'r'"<<std::endl;
        char move=' ';
        std::cin >> move;

        int j=1;
        //checks that user input was valid and if so runs that move
        while(j==1)
        {
            //handles attack
            if(move=='a')
            {
                //handles the player not having enough energy
                if ((player->GetEnergy())-(player->GetAttackCost())<0)
                {
                    std::cout<<"Error! Not enough energy to attack!"<<std::endl;
                    std::cin >> move;
                    continue;
                }
                //does dmg to the enemy
                enemy->SetHealth((enemy->GetHealth())-player->GetAD());
                //checks for kill if killed then end fight
                if(enemy->GetHealth()<=0)
                {
                    player->Reset(maxHealthPlayer,maxEnergyPlayer);
                    enemy->Reset(maxHealthEnemy,maxEnergyEnemy);
                    return true;
                }
                //costs one energy
                player->SetEnergy((player->GetEnergy())-player->GetAttackCost());
                std::cout<<player->GetName()<<" attacks! Dealing "<<player->GetAD()<<" damage to "<<enemy->GetName()<<'!'<<std::endl;
                j=0;
            }
            //handles ability
            else if (move=='q')
            {
                //handles the player not having enough energy
                if ((player->GetEnergy())-(player->GetAbility()->GetEnergyCost())<0)
                {
                    std::cout<<"Error! Not enough energy to attack!"<<std::endl;
                    std::cin >> move;
                    continue;
                }
                //does dmg to the enemy
                enemy->SetHealth((enemy->GetHealth())-player->GetAbility()->GetDamage());
                //checks for kill if killed then end fight
                if(enemy->GetHealth()<=0)
                {
                    player->Reset(maxHealthPlayer,maxEnergyPlayer);
                    enemy->Reset(maxHealthEnemy,maxEnergyEnemy);
                    return true;
                }
                //costs energy
                player->SetEnergy((player->GetEnergy())-player->GetAbility()->GetEnergyCost());

                //displays
                std::cout<<player->GetName()<<" uses "<<player->GetAbility()->GetName()
                <<"! Dealing "<<player->GetAbility()->GetDamage()<<" damage to "<<enemy->GetName()<<'!'<<std::endl;

                //handles paralysis and poison abilities
                //poison
                if (player->GetPoison())
                {
                    //cant stack poison
                    if (enemy->GetPoisoned()>=0)
                    {
                        std::cout<<"Here"<<std::endl;
                        enemy->SetPoisoned(3);
                    }
                }
                //paralysis
                if (player->GetParalyze())
                {
                    enemy->SetParalyzed(1);
                }

                j=0;
            }
            //handles rest
            else if (move=='r')
            {
                //handles the player having full energy already
                if (player->GetEnergy()==maxEnergyPlayer)
                {
                    std::cout<<"Error! Energy is already full! Select a new move: ";
                    std::cin >> move;
                    continue;
                }
                //makes sure energy cannot increase past max energy
                if(player->GetEnergy()<maxEnergyPlayer)
                {
                    player->SetEnergy((player->GetEnergy())+1);
                }
                std::cout<<player->GetName()<<" is resting. Restored 1 energy!"<<std::endl;
                j=0;
            }
            //handles invalid input
            else
            {
                std::cout<<"Error! Invalid input, please enter a valid move!"<<std::endl;
                std::cin >> move;
            }
        }
        std::cout<<std::endl;

        //if the enemy is paralyzed unparalyze them and then skip their turn
        if (enemy->GetParalyzed()==1)
        {
            enemy->SetParalyzed(0);
            std::cout<<enemy->GetName()<<" is paralyzed! They are unable to move!"<<std::endl;
            continue;
        }

        std::cout<<std::endl;
        //allows the enemy to preform their move
        char enemyMove=enemy->EnemyMove();
        //makes sure the enemy didn't die to the players attack
        //if the enemy is dead end the fight and return true
        if (enemy->GetHealth()<=0)
        {
            player->Reset(maxHealthPlayer,maxEnergyPlayer);
            enemy->Reset(maxHealthEnemy,maxEnergyEnemy);
            return true;
        }
        //handles enemy attack
        if (enemyMove=='a')
        {
            //does dmg to the player
            player->SetHealth((player->GetHealth())-enemy->GetAD());
            if(player->GetHealth()<=0)
            {
                player->Reset(maxHealthPlayer,maxEnergyPlayer);
                enemy->Reset(maxHealthEnemy,maxEnergyEnemy);
                return false;
            }
            //costs one energy
            enemy->SetEnergy((enemy->GetEnergy())-1);
            std::cout<<enemy->GetName()<<" attacks! Dealing "<<enemy->GetAD()<<" damage to "<<player->GetName()<<'!'<<std::endl;
        }
        else if (enemyMove=='r')
        {
            //makes sure energy cannot increase past max energy
            if(enemy->GetEnergy()<maxEnergyEnemy)
            {
                enemy->SetEnergy((enemy->GetEnergy())+1);
            }
            std::cout<<enemy->GetName()<<" is resting. Restored 1 energy!"<<std::endl;
        }
        else if (enemyMove=='q')
        {
            //does dmg to the enemy
            player->SetHealth((player->GetHealth())-enemy->GetAbility()->GetDamage());
            //checks for kill if killed then end fight
            if(player->GetHealth()<=0)
            {
                player->Reset(maxHealthPlayer,maxEnergyPlayer);
                enemy->Reset(maxHealthEnemy,maxEnergyEnemy);
                return false;
            }
            //costs energy
            enemy->SetEnergy((enemy->GetEnergy())-enemy->GetAbility()->GetEnergyCost());

            //displays
            std::cout<<enemy->GetName()<<" uses "<<enemy->GetAbility()->GetName()
            <<"! Dealing "<<enemy->GetAbility()->GetDamage()<<" damage to "<<enemy->GetName()<<'!'<<std::endl;
        }
        std::cout<<std::endl;

        //if the enemy is poisoned do the damage and reduce the counter
        if (enemy->GetPoisoned()>0)
        {
            enemy->SetPoisoned(enemy->GetPoisoned()-1);
            enemy->SetHealth(enemy->GetHealth()-20);
            std::cout<<enemy->GetName()<<" is poisoned! They take 20 damage!"<<std::endl;
            //check for kill
            if(enemy->GetHealth()<=0)
            {
                player->Reset(maxHealthPlayer,maxEnergyPlayer);
                enemy->Reset(maxHealthEnemy,maxEnergyEnemy);
                return true;
            }
        }

        std::cout<<std::endl;
    }

    player->Reset(maxHealthPlayer,maxEnergyPlayer);
    enemy->Reset(maxHealthEnemy,maxEnergyEnemy);
    return true;
}

/**
 * Allows the game to be played by looping through the fight
 */
void Game::Play()
{
    int i=0;
    while(i<int(mEnemies.size()))
    {
        bool check=Fight(&mPlayer,mEnemies[i]);

        //if check is true then the fight was won, move onto the next
        if (check && (i+1)!=int(mEnemies.size()))
        {
            std::cout<<"Congrats "<<mPlayer.GetName()<<"! You defeated "<<
            mEnemies[i]->GetName()<<'.'<<std::endl;

            //allows the player to upgrade one of their stats for winning
            std::cout<<"As a reward please select a stat you would like to upgrade for your next fight:"<<std::endl;
            std::cout<<"+15 Attack Damage: 'a'    +1 Max Energy: 'e'    +100 Max Health: 'h'"<<std::endl;
            char c;
            std::cin>>c;

            //upgrades the players selected stat
            int j=1;
            while (j==1)
            {
                if(c=='a')
                {
                    mPlayer.SetAD(mPlayer.GetAD()+15);
                    j=0;
                }
                else if (c=='e')
                {
                    mPlayer.SetEnergy(mPlayer.GetEnergy()+1);
                    j=0;
                }
                else if (c=='h')
                {
                    mPlayer.SetHealth(mPlayer.GetHealth()+100);
                    j=0;
                }
                else
                {
                    std::cout<<"Error! Invalid input, please enter a valid upgrade!"<<std::endl;
                    std::cin >> c;
                }
            }

            i=i+1;
        }
        //lost retry the fight
        else
        {
            std::cout<<"You lost! Try again!"<<std::endl;
        }

    }
    //completed the game!
    std::cout<<"You have completed Bryce's Game! Thanks for playing"<<std::endl;

}

/**
 * Adds the enemy to the game
 * @param enemy pointer to enemy character to be added
 */
void Game::AddEnemy(Character* enemy)
{
    mEnemies.push_back(enemy);
}