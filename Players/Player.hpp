#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

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
};

#endif