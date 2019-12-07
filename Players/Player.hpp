#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

class Player
{
private:
    int iPlayable;

public:
    Player(int iPlayerChoice); //constructor
    Player(const Player &obj); // copy constructor
    Player& operator= (const Player &obj); //assingment operator
    ~Player(); //destructor
};

#endif