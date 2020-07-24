#ifndef __COMPUTER_HPP__
#define __COMPUTER_HPP__

// this class is suppose to be an expert system to select the right strategy to be used during the game.

#include <vector>
#include <map>
#include "Player.hpp"
#include "Commons.hpp"

class Computer : Player
{
private:
    int iPlayable;

public:
    Computer();
    Computer(int& iPlayerChoice);
    Computer(const Computer& obj);
    Computer& operator= (const Computer& obj);
    ~Computer();

public:
    void SetPlayable(int iPlayerChoice);
    int GetPlayable();
    std::pair<int,int> ComputeMove(const std::vector<std::vector<int>>& vecGameBoard);

};


#endif