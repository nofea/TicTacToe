#include "Player.hpp"


Player::Player()
{
}

Player::Player(int iPlayerChoice)
{
    iPlayable = iPlayerChoice;
}

Player::Player(const Player& obj)
{
    iPlayable = obj.iPlayable;
}

Player& Player::operator=(const Player& obj)
{
    iPlayable = obj.iPlayable;

    return *this;
}

Player::~Player()
{
}
