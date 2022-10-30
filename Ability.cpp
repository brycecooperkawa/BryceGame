/**
 * @file Ability.cpp
 * @author Bryce Cooperkawa
 */

#include "Ability.h"

/**
 * constructor
 * @param name ability name
 * @param damage ability damage
 * @param energyCost ability energy cost
 */
Ability::Ability(std::string name, int damage, int energyCost)
{
    mName=name;
    mDamage=damage;
    mEnergyCost=energyCost;
}