#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <map>
#include <vector>
#include "Commons.hpp"

class Player
{
private:
    int iPlayable;

public:
    Player();
    Player(int iPlayerChoice); //constructor
    Player(const Player &obj); // copy constructor
    Player& operator= (const Player &obj); //assingment operator
    ~Player(); //destructor

public:
    virtual void SetPlayable(int iPlayerChoice) = 0;
    virtual int GetPlayable() = 0;
    virtual std::pair<int,int> ComputeMove(const std::vector<std::vector<int>>& vecGameBoard) = 0;
    virtual bool RememberMyPosition(const std::pair<int,int>& pairCoords) = 0;
};

#endif