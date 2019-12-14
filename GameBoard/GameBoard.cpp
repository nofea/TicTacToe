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

bool GameBoard::SaveVictorySet(MatrixProperties Property, int iIndex)
{
    switch(Property)
    {
        case MatrixProperties_Row:
        for(int iCount = 0; iCount < iBoardSize; iCount++)
        {
            listVictorySet.push_back(pair<int,int> {iIndex, iCount});
        }
        break;

        case MatrixProperties_Column:
        for(int iCount = 0; iCount < iBoardSize; iCount++)
        {
            listVictorySet.push_back(pair<int,int> {iCount, iIndex});
        }
        break;

        case MatrixProperties_PrimaryDiagonal:
        for(int iCount = 0; iCount < iBoardSize; iCount++)
        {
            listVictorySet.push_back(pair<int,int> {iCount, iCount});
        }
        break;

        case MatrixProperties_SecondaryDiagonal:
        for(int iCount = 0; iCount < iBoardSize; iCount++)
        {
            for(int jCount = (iBoardSize - 1); jCount >= 0; jCount--)
            {
                listVictorySet.push_back(pair<int,int> {iCount, jCount});
            }
        }
        break;

        default:
        return false;
        break;
    }
    return true;
}

list<pair<int,int>> GameBoard::GetVictorySet()
{
    return listVictorySet;
}

bool GameBoard::MarkBoard(pair<int,int> pairCoordinates, int iMark)
{ 
    bool bRetVal = true;

    if(vecGameBoard.at(pairCoordinates.first).at(pairCoordinates.second) == Playable_X
     || vecGameBoard.at(pairCoordinates.first).at(pairCoordinates.second) == Playable_O)
     {
         bRetVal = false;
     }
     else
     {
         vecGameBoard.at(pairCoordinates.first).at(pairCoordinates.second) = iMark;
     }
     
    return bRetVal;
}

vector<std::vector<int>> GameBoard::ShowGameBoard()
{
    return vecGameBoard;
}