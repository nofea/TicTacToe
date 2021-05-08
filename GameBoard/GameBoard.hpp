#ifndef __GAMEBOARD_HPP__
#define __GAMEBOARD_HPP__

#include <iostream>
#include <vector>
#include <list>
#include "Commons.hpp"

/**
 * @brief hold properties of the TicTacToe game board
 * 
 */
class GameBoard
{
private:
    int iBoardSize;
    std::vector<std::vector<int>> vecGameBoard;
    std::list<std::pair<int,int>> listVictorySet;
    int iWinningPlayable;
    Commons* objCommons;

private:
    GameBoard();
    bool SaveVictorySet(const Commons::MatrixProperties& Property, const int& iIndex);

public:   
    GameBoard(int iSize);
    GameBoard(const GameBoard& obj);
    GameBoard& operator= (const GameBoard& obj);
    ~GameBoard();

public:
    bool InitGameBoard();
    bool IsEndOfGame();
    std::list<std::pair<int,int>> GetVictorySet();
    int GetWinningPlayable();
    bool MarkBoard(const std::pair<signed int, signed int>& pairCoordinates, const signed int& iMark);
    std::vector<std::vector<int>> ShowGameBoard();
};

#endif