/**
 * @file Player.h
 * @author Bryce Cooperkawa
 *
 *
 */

#ifndef BRYCEGAME_CHARACTER_H
#define BRYCEGAME_CHARACTER_H

#include "string"
#include "vector"

#include "Ability.h"

/*
 * Characters that are in the game
 */
class Character {
private:
    /// the characters name
    std::string mName = "";

    /// the characters health
    int mHealth;

    /// characters energy
    int mEnergy = 3;

    /// characters attack cost
    int mAttackCost = 1;

    /// the characters attack damage
    int mAD;

    /// the characters ability
    std::shared_ptr<Ability> mAbility;

    /// says if the characters next ability will poison
    bool mPoisonActive = false;

    /// says if the characters next ability will paralyze
    bool mParalyzeActive = false;

    /// says if the character is poisoned
    int mPoisoned = 0;

    /// says if the character is paralyzed
    int mParalyzed = 0;

public:
    /// Default constructor (disabled)
    Character() = delete;

    /// Copy constructor (disabled)
    Character(const Character &) = delete;

    /// Assignment operator
    void operator=(const Character &) = delete;

    /// constructor
    Character(std::string name, int health, int ad);

    /**
     * Get the characters name
     * @return The characters name
     */
    std::string GetName() { return mName; }

    /**
     * Set the characters health
     * @param i the new health
     */
    void SetHealth(int i) { mHealth = i; }
    /**
     * Get the characters health
     * @return The characters current health
     */
    int GetHealth() const { return mHealth; }

    /**
     * Set the characters health
     * @param i the new health
     */
    void SetEnergy(int i) { mEnergy = i; }
    /**
     * Get the characters health
     * @return The characters current health
     */
    int GetEnergy() const { return mEnergy; }

    /**
     * Set the characters attack cost
     * @param i the new attack cost
     */
    void SetAttackCost(int i) { mAttackCost = i; }
    /**
     * Get the characters attack cost
     * @return The characters attack cost
     */
    int GetAttackCost() const { return mAttackCost; }

    /**
     * Set the characters health
     * @param i the new health
     */
    void SetAD(int i) { mAD = i; }
    /**
     * Get the characters health
     * @return The characters current health
     */
    int GetAD() const { return mAD; }

    /**
     * Set the characters ability to poison
     * @param i says if can poison or not
     */
    void SetPoison(bool i) { mPoisonActive = i; }
    /**
     * Get if the character can poison
     * @return The characters ability to poison
     */
    int GetPoison() const { return mPoisonActive; }

    /**
     * Set the characters ability to paralyze
     * @param i says if can paralyze or not
     */
    void SetParalyze(bool i) { mParalyzeActive = i; }
    /**
     * Get if the character can paralyze
     * @return The characters ability to paralyze
     */
    int GetParalyze() const { return mParalyzeActive; }

    /**
     * Set the characters poison status
     * @param i the poison status
     */
    void SetPoisoned(int i) { mPoisoned = i; }
    /**
     * Get the characters poison status
     * @return The characters current poison status
     */
    int GetPoisoned() const { return mPoisoned; }

    /**
     * Set the characters paralyzed status
     * @param i the paralyzed status
     */
    void SetParalyzed(int i) { mParalyzed = i; }
    /**
     * Get the characters paralyzed status
     * @return The characters current paralyzed status
     */
    int GetParalyzed() const { return mParalyzed; }

    /**
     * Sets the characters ability
     * @param ability the ability being set
     */
    void SetAbility(std::shared_ptr<Ability> ability) { mAbility = static_cast<const std::shared_ptr<Ability>>(ability); }
    /**
     * Get the characters ability
     * @return The characters ability
     */
    std::shared_ptr<Ability> GetAbility() const { return mAbility; }

    /// select the move(attack/ability/rest) that the enemy will do
    char EnemyMove();

    /// resets the players stats
    void Reset(int health, int energy);
};

#endif //BRYCEGAME_CHARACTER_H
