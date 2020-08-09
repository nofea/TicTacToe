#ifndef __HUMAN_HPP__
#define __HUMAN_HPP__

#include "Player.hpp"

class Human : Player
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
};

#endif