#include <iostream>
#include <map>
#include "Commons.hpp"
#include "Logger.hpp"

class Arena
{
private:
    Commons* ObjCommons;
    Logger Log;

public:
    Arena();
    ~Arena();
    Arena(const Arena& obj);
    Arena& operator= (const Arena& obj);

    bool PlayMatch(std::map<Commons::GameSettings, int> mapGameSettings);

private:
    bool MatchSetup();
};
