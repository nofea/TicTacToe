#ifndef __GAMEBOARD_HPP__
#define __GAMEBOARD_HPP__

#include <iostream>
#include <vector>
#include <list>
#include "Commons.hpp"


class GameBoard
{
private:
    int iBoardSize;
    std::vector<std::vector<int>> vecGameBoard;
    std::list<std::pair<int,int>> listVictorySet;

private:
    GameBoard();
    bool SaveVictorySet(MatrixProperties Property, int iIndex);

public:   
    GameBoard(int iSize);
    GameBoard(const GameBoard& obj);
    GameBoard& operator= (const GameBoard& obj);
    ~GameBoard();

public:
    bool InitGameBoard();
    bool IsEndOfGame();
    std::list<std::pair<int,int>> GetVictorySet();
    bool MarkBoard(std::pair<int,int> pairCoordinates, int iMark);
    std::vector<std::vector<int>> ShowGameBoard();
};

#endif