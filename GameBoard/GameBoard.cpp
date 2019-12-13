#include "GameBoard.hpp"

using namespace std;

GameBoard::GameBoard()
{
    iBoardSize = 0;
}

GameBoard::~GameBoard()
{
}

GameBoard::GameBoard(int iSize)
{
    iBoardSize = iSize;
    InitGameBoard();
}

GameBoard::GameBoard(const GameBoard& obj)
{
    iBoardSize = obj.iBoardSize;
}

GameBoard& GameBoard::operator= (const GameBoard& obj)
{
    iBoardSize = obj.iBoardSize;
    return *this;
}

bool GameBoard::InitGameBoard()
{
    vector<int> vecTemp(iBoardSize, GAMEBOARDINITVALUE);

    for(int iCount = 0; iCount < iBoardSize; iCount++)
    {
        vecGameBoard.push_back(vecTemp);
    }

    return true;
}

bool GameBoard::IsEndOfGame()
{
    bool retVal = false;
    list<int> listX, listO;
    
    //check the rows
    for(auto it = vecGameBoard.begin(); it != vecGameBoard.end(); ++it)
    {
        for(auto jt = it->begin(); jt != it->end(); ++jt)
        {
            if(*jt == Playable_X)
            {
                listX.push_back(Playable_X);
            }
            else if(*jt == Playable_O)
            {
                listO.push_back(Playable_O);
            }
        }

        if(listX.size() == iBoardSize)
        {
            retVal = true;
            break;
        }
        else if(listO.size() == iBoardSize)
        {
            retVal = true;
            break;
        }
        else
        {
            listX.clear();
            listO.clear();
        }
        
    }

    return retVal;
}

bool GameBoard::SaveVictorySet(MatrixDimensions Dimension, int iIndex)
{
    return true;
}

list<pair<int,int>> GameBoard::GetVictorySet()
{
    return listVictorySet;
}