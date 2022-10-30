/**
 * @file Ability.h
 * @author Bryce Cooperkawa
 *
 *
 */

#ifndef BRYCEGAME_ABILITY_H
#define BRYCEGAME_ABILITY_H

#include "string"

/**
 * Abilities that can be used by characters
 */
class Ability {
private:
    /// the abilities name
    std::string mName;

    /// the amount of damage the ability does
    int mDamage;

    /// energy cost of the ability
    int mEnergyCost;

public:
    /// Default constructor (disabled)
    Ability() = delete;

    /// Copy constructor (disabled)
    Ability(const Ability &) = delete;

    /// Assignment operator
    void operator=(const Ability &) = delete;

    ///constructor
    Ability(std::string name, int damage, int energyCost);

    /**
     * Get the ability name
     * @return The ability's name
     */
    std::string GetName() { return mName; }

    /**
     * Get the energy cost
     * @return The energy cost
     */
    int GetEnergyCost() const { return mEnergyCost; }

    /**
     * Get the damage done
     * @return The damage done
     */
    int GetDamage() const { return mDamage; }

};

#endif //BRYCEGAME_ABILITY_H
