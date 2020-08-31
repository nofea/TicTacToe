#include "PlayerFactory.hpp"

using namespace std;

Commons* PlayerFactory::objCommons = 0;
Player* PlayerFactory::obj = 0;
PlayerFactory::PlayerFactory()
{
    objCommons = Commons::GetInstance();
}

PlayerFactory::~PlayerFactory()
{
    delete obj;
}

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