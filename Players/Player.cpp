#include "Player.hpp"

/**
 * @brief Construct a new Player:: Player object
 * 
 */
Player::Player()
{
}

/**
 * @brief Construct a new Player:: Player object
 * 
 * @param iPlayerChoice 
 */
Player::Player(int iPlayerChoice)
{
    iPlayable = iPlayerChoice;
}

/**
 * @brief Construct a new Player:: Player object
 * 
 * @param obj [in] object of class Player
 */
Player::Player(const Player& obj)
{
    iPlayable = obj.iPlayable;
}

/**
 * @brief Assignment operator overloading for the class Player
 * 
 * @param obj [in] object of class Player
 * @return Player& 
 */
Player& Player::operator=(const Player& obj)
{
    iPlayable = obj.iPlayable;

    return *this;
}

/**
 * @brief Destroy the Player:: Player object
 * 
 */
Player::~Player()
{
}
