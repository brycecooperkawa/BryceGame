/**
 * @file Game.h
 * @author Bryce Cooperkawa
 *
 *
 */

#ifndef BRYCEGAME_GAME_H
#define BRYCEGAME_GAME_H

#include "string"
#include "vector"

#include "Character.h"

/**
 * The game allows the player to play
 */
class Game {
private:
    /// the player character
    Character mPlayer;

    /// collection of the enemies
    std::vector<Character *> mEnemies;

public:
    /// Default constructor (disabled)
    Game() = delete;

    /// Copy constructor (disabled)
    Game(const Game &) = delete;

    /// Assignment operator
    void operator=(const Game &) = delete;

    /// constructor
    Game(std::string name);

    /// allows the game to be played by looping through the fights
    void Play();

    /// creates the fight between the character and the enemy
    bool Fight(Character* player,Character* enemy);

    /// adds an enemy to the game
    void AddEnemy(Character* enemy);

    /// allows the player to be created
    bool CreatePlayer(char select);
};

#endif //BRYCEGAME_GAME_H
