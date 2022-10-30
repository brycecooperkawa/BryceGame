/**
 * @file Player.cpp
 * @author Bryce Cooperkawa
 */

#include <stdlib.h>

#include "Ability.h"
#include "Character.h"

/**
 * Creates the player character
 * @param name the name of the character
 */
Character::Character(std::string name, int health, int ad)
{
    mName=name;
    mHealth=health;
    mAD=ad;
}

/**
 * Chooses the move that the enemy preforms and return the character that makes that move happen
 * @return the char that represents the chosen move
 */
char Character::EnemyMove()
{
    //will be fairly basic for now because I don't know how to build a real AI yet
    //basic guide to enemy moves
    //rest if energy is 0
    //50/50 ability or attack if energy permitting
    if(GetEnergy()==0)
    {
        return 'r';
    }
    else
    {
        //generates random number between 1-10 to use as 50/50
        int num=rand() % 10 + 1;

        //if num<5 select attack otherwise use ability
        if (num<=4)
        {
            return 'a';
        }
        //rests
        else if (num>4 && num<6)
        {
            return 'r';
        }
        else
        {
            //can only use ability energy permitting
            if (GetEnergy()>GetAbility()->GetEnergyCost())
            {
                return 'q';
            }
            //not enough energy then either rest or attack
            else
            {
                int num2=rand() % 10 + 1;
                if (num2<=5)
                {
                    return 'a';
                }
                else
                {
                    return 'r';
                }
            }

        }
    }

}

/**
 * Resets the characters health and energy
 * @param health the characters max health
 * @param energy the characters max energy
 */
void Character::Reset(int health, int energy)
{
    mHealth=health;
    mEnergy=energy;
}