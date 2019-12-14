#ifndef __COMPUTERBLOCKER_HPP__
#define __COMPUTERBLOCKER_HPP__

#include <vector>
#include <list>
#include "Player.hpp"

class ComputerBlocker : Player
{
private:
    int iPlayable;
    std::vector<std::list<std::pair<int,int>>> vecVictoryConditions;
public:
    ComputerBlocker();
    ComputerBlocker(int iPlayerChoice);
    ComputerBlocker(const ComputerBlocker& obj);
    ComputerBlocker& operator= (const ComputerBlocker& obj);
    ~ComputerBlocker();

private:
    bool MakeVictoryConditionsList(int iGameBoardSize);

public:
    void SetPlayable(int iPlayerChoice);
    int GetPlayable();
    std::pair<int,int> ComputeMove(std::vector<std::vector<int>> vecGameBoard);
};

#endif