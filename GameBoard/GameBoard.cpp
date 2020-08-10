#include "GameBoard.hpp"

using namespace std;

GameBoard::GameBoard()
{
    iBoardSize = 0;
    iWinningPlayable = -1;
}

GameBoard::~GameBoard()
{
}

GameBoard::GameBoard(int iSize)
{
    iBoardSize = iSize;
    iWinningPlayable = -1;
    InitGameBoard();
}

GameBoard::GameBoard(const GameBoard& obj)
{
    iBoardSize = obj.iBoardSize;
    iWinningPlayable = obj.iWinningPlayable;
    vecGameBoard = obj.vecGameBoard;
    listVictorySet = obj.listVictorySet;
}

GameBoard& GameBoard::operator= (const GameBoard& obj)
{
    iBoardSize = obj.iBoardSize;
    iWinningPlayable = obj.iWinningPlayable;
    vecGameBoard = obj.vecGameBoard;
    listVictorySet = obj.listVictorySet;
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
    bool bFull = true;
    int iTemp = GAMEBOARDINITVALUE;
    list<int> listRowX, listRowO, listColX, listColO, listPDiaX, listPDiaO, listSDiaX, listSDiaO;   
    
    for(int i = 0, k = iBoardSize - 1; i < iBoardSize, k >= 0; i++, k--)
    {
        //check the rows and cols
        for(int j = 0; j < iBoardSize; j++)
        {
            if(vecGameBoard.at(i).at(j) == Playable_X)
            {
                listRowX.push_back(Playable_X);
            }
            else if(vecGameBoard.at(i).at(j) == Playable_O)
            {
                listRowO.push_back(Playable_O);
            }

            if(vecGameBoard.at(j).at(i) == Playable_X)
            {
                listColX.push_back(Playable_X);
            }
            else if(vecGameBoard.at(j).at(i) == Playable_O)
            {
                listColO.push_back(Playable_O);
            }
        }

        if(listRowX.size() == iBoardSize)
        {
            SaveVictorySet(MatrixProperties_Row, i);
            return true;
        }
        else if(listRowO.size() == iBoardSize)
        {
            SaveVictorySet(MatrixProperties_Row, i);
            return true;
        }
        else if(listColX.size() == iBoardSize)
        {
            SaveVictorySet(MatrixProperties_Column, i);
            return true;
        }
        else if(listColO.size() == iBoardSize)
        {
            SaveVictorySet(MatrixProperties_Column, i);
            return true;
        }
        else
        {
            listRowX.clear();
            listRowO.clear();
            listColX.clear();
            listColO.clear();
        }

        if(vecGameBoard.at(i).at(i) == Playable_X)
        {
            listPDiaX.push_back(Playable_X);
        }
        else if(vecGameBoard.at(i).at(i) == Playable_O)
        {
            listPDiaO.push_back(Playable_O);
        }

        if(vecGameBoard.at(i).at(k) == Playable_X)
        {
            listSDiaX.push_back(Playable_X);
        }
        else if(vecGameBoard.at(i).at(k) == Playable_O)
        {
            listSDiaO.push_back(Playable_O);
        }
    }

    if(listPDiaX.size() == iBoardSize)
    {
        SaveVictorySet(MatrixProperties_PrimaryDiagonal, iTemp);
        retVal = true;
    }
    else if(listPDiaO.size() == iBoardSize)
    {
        SaveVictorySet(MatrixProperties_PrimaryDiagonal, iTemp);
        retVal = true;
    }
    else if(listSDiaX.size() == iBoardSize)
    {
        SaveVictorySet(MatrixProperties_SecondaryDiagonal, iTemp);
        retVal = true;
    }
    else if(listSDiaO.size() == iBoardSize)
    {
        SaveVictorySet(MatrixProperties_SecondaryDiagonal, iTemp);
        retVal = true;
    }
    else
    {
        listPDiaX.clear();
        listPDiaO.clear();
        listSDiaX.clear();
        listSDiaO.clear();
    }

    //check if the game board is full
    if(!retVal)
    {
        for(auto it = vecGameBoard.begin(); it != vecGameBoard.end(); ++it)
        {
            for(auto jt = it->begin(); jt != it->end(); ++jt)
            {
                if (*jt == GAMEBOARDINITVALUE)
                {
                    bFull = false;
                    break;
                }
            }
        }
        retVal = bFull;
    }

    return retVal;
}

bool GameBoard::SaveVictorySet(MatrixProperties Property, int& iIndex)
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
        for(int iCount = 0, jCount = (iBoardSize - 1); iCount < iBoardSize, jCount >= 0; iCount++, jCount--)
        {
            listVictorySet.push_back(pair<int,int> {iCount, jCount});    
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

bool GameBoard::MarkBoard(const pair<signed int, signed int>& pairCoordinates, const signed int& iMark)
{ 
    bool bRetVal = true;

    if(pairCoordinates.first < ZERO || pairCoordinates.second > (iBoardSize - 1))
    {
        bRetVal = false;
    }
    else
    {
        if(vecGameBoard.at(pairCoordinates.first).at(pairCoordinates.second) != GAMEBOARDINITVALUE)
        {
            bRetVal = false;
        }
        else
        {
            vecGameBoard.at(pairCoordinates.first).at(pairCoordinates.second) = iMark;
        }
    }
     
    return bRetVal;
}

vector<std::vector<int>> GameBoard::ShowGameBoard()
{
    return vecGameBoard;
}