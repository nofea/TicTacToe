#ifndef __HUMAN_HPP__
#define __HUMAN_HPP__

#include <map>
#include <vector>
#include "Player.hpp"

class Human : public Player
{
private:
    int iPlayable;
public:
    Human();
    Human(int iPlayerChoice);
    Human(const Human& obj); // copy constructor
    Human& operator= (const Human& obj); //assingment operator
    ~Human();

public:
    void SetPlayable(int iPlayerChoice);
    int GetPlayable();
    std::pair<int,int> ComputeMove(const std::vector<std::vector<int>>& vecGameBoard);
    bool RememberMyPosition(const std::pair<int,int>& pairCoords);
};

#endif