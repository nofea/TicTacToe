#ifndef __COMPUTERBLOCKER_HPP__
#define __COMPUTERBLOCKER_HPP__

#include "Player.hpp"

class ComputerBlocker : Player
{
private:
    int iPlayable;
public:
    ComputerBlocker();
    ComputerBlocker(int iPlayerChoice);
    ComputerBlocker(const ComputerBlocker& obj);
    ComputerBlocker& operator= (const ComputerBlocker& obj);
    ~ComputerBlocker();

public:
    void SetPlayable(int iPlayerChoice);
    int GetPlayable();
};

#endif