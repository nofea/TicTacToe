#include <iostream>
#include <map>
#include "Commons.hpp"
#include "Logger.hpp"
#include "PlayerFactory.hpp"
#include "GameBoard.hpp"

class Arena
{
private:
    Commons* objCommons;
    Player* ObjPlayer_1;
    Player* ObjPlayer_2;


public:
    Arena();
    ~Arena();
    Arena(const Arena& obj);
    Arena& operator= (const Arena& obj);

    bool PlayMatch(std::map<Commons::GameSettings, int>& mapGameSettings, Logger& Log);

private:
    bool MatchSetup(std::map<Commons::GameSettings, int>& mapGameSettings, PlayerFactory& PF, Logger& Log);
};
