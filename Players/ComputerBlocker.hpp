#ifndef __COMPUTERBLOCKER_HPP__
#define __COMPUTERBLOCKER_HPP__

#include <vector>
#include <list>
#include <stdlib.h>
#include <algorithm>
#include "Player.hpp"
#include "Commons.hpp"

class ComputerBlocker : Player
{
private:
    int iPlayable;
    std::vector<std::list<std::pair<int,int>>> vecVictoryConditions;
    std::list<std::pair<int,int>> listEnemyPositions;
public:
    ComputerBlocker();
    ComputerBlocker(int& iPlayerChoice);
    ComputerBlocker(const ComputerBlocker& obj);
    ComputerBlocker& operator= (const ComputerBlocker& obj);
    ~ComputerBlocker();

private:
    bool MakeVictoryConditionsList(int& iGameBoardSize);
    bool UpdateEnemyPosition(const std::vector<std::vector<int>>& vecGameBoard);

public:
    void SetPlayable(int iPlayerChoice);
    int GetPlayable();
    std::pair<int,int> ComputeMove(const std::vector<std::vector<int>>& vecGameBoard);
};

#endif