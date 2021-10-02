#ifndef _PLAYERFACTORY_HPP_
#define _PLAYERFACTORY_HPP_

#include <iostream>
#include "Player.hpp"
#include "Human.hpp"
#include "ComputerBlocker.hpp"

/**
 * @brief holds the factory class for generating player objects
 * 
 */
class PlayerFactory
{
private:
    static Commons* objCommons;
    static Player* obj;
    
public:
    PlayerFactory();
    ~PlayerFactory();

    static Player* AssignPlayer(Commons::PlayerType Type);

};

#endif