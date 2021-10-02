#include "PlayerFactory.hpp"

using namespace std;

Commons* PlayerFactory::objCommons = 0;
Player* PlayerFactory::obj = 0;

/**
 * @brief Construct a new Player Factory:: Player Factory object
 * 
 */
PlayerFactory::PlayerFactory()
{
    objCommons = Commons::GetInstance();
}

/**
 * @brief Destroy the Player Factory:: Player Factory object
 * 
 */
PlayerFactory::~PlayerFactory()
{
    delete obj;
}

/**
 * @brief function used to create and assign player object
 * 
 * @param Type [in] Player type selected by the game settings
 * @return Player* 
 */
Player* PlayerFactory::AssignPlayer(Commons::PlayerType Type)
{
    switch(Type)
    {
    case objCommons->PlayerType_Human:
        obj = new Human;
        break;

    case objCommons->PlayerType_ComputerBlocker:
        obj = new ComputerBlocker;
        break;
    
    default:
        obj = NULL;
        break;
    }

    return obj;
}
