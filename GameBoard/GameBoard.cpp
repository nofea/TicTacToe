#include "GameBoard.hpp"

using namespace std;

GameBoard::GameBoard()
{
    iBoardSize = 0;
    iWinningPlayable = -1;
    objCommons = Commons::GetInstance();
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
    this->iBoardSize = obj.iBoardSize;
    this->iWinningPlayable = obj.iWinningPlayable;
    this->vecGameBoard = obj.vecGameBoard;
    this->listVictorySet = obj.listVictorySet;
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
    
    for(int i = 0, k = iBoardSize - 1; (i < iBoardSize), (k >= 0); i++, k--)
    {
        //check the rows and cols
        for(int j = 0; j < iBoardSize; j++)
        {
            if(vecGameBoard.at(i).at(j) == objCommons->Playable_X)
            {
                listRowX.push_back(objCommons->Playable_X);
            }
            else if(vecGameBoard.at(i).at(j) == objCommons->Playable_O)
            {
                listRowO.push_back(objCommons->Playable_O);
            }

            if(vecGameBoard.at(j).at(i) == objCommons->Playable_X)
            {
                listColX.push_back(objCommons->Playable_X);
            }
            else if(vecGameBoard.at(j).at(i) == objCommons->Playable_O)
            {
                listColO.push_back(objCommons->Playable_O);
            }
        }

        if(listRowX.size() == static_cast<size_t>(iBoardSize))
        {
            SaveVictorySet(objCommons->MatrixProperties_Row, i);
            iWinningPlayable = objCommons->Playable_X;
            return true;
        }
        else if(listRowO.size() == static_cast<size_t>(iBoardSize))
        {
            SaveVictorySet(objCommons->MatrixProperties_Row, i);
            iWinningPlayable = objCommons->Playable_O;
            return true;
        }
        else if(listColX.size() == static_cast<size_t>(iBoardSize))
        {
            SaveVictorySet(objCommons->MatrixProperties_Column, i);
            iWinningPlayable = objCommons->Playable_X;
            return true;
        }
        else if(listColO.size() == static_cast<size_t>(iBoardSize))
        {
            SaveVictorySet(objCommons->MatrixProperties_Column, i);
            iWinningPlayable = objCommons->Playable_O;
            return true;
        }
        else
        {
            listRowX.clear();
            listRowO.clear();
            listColX.clear();
            listColO.clear();
        }

        if(vecGameBoard.at(i).at(i) == objCommons->Playable_X)
        {
            listPDiaX.push_back(objCommons->Playable_X);
        }
        else if(vecGameBoard.at(i).at(i) == objCommons->Playable_O)
        {
            listPDiaO.push_back(objCommons->Playable_O);
        }

        if(vecGameBoard.at(i).at(k) == objCommons->Playable_X)
        {
            listSDiaX.push_back(objCommons->Playable_X);
        }
        else if(vecGameBoard.at(i).at(k) == objCommons->Playable_O)
        {
            listSDiaO.push_back(objCommons->Playable_O);
        }
    }

    if(listPDiaX.size() == static_cast<size_t>(iBoardSize))
    {
        SaveVictorySet(objCommons->MatrixProperties_PrimaryDiagonal, iTemp);
        iWinningPlayable = objCommons->Playable_X;
        retVal = true;
    }
    else if(listPDiaO.size() == static_cast<size_t>(iBoardSize))
    {
        SaveVictorySet(objCommons->MatrixProperties_PrimaryDiagonal, iTemp);
        iWinningPlayable = objCommons->Playable_O;
        retVal = true;
    }
    else if(listSDiaX.size() == static_cast<size_t>(iBoardSize))
    {
        SaveVictorySet(objCommons->MatrixProperties_SecondaryDiagonal, iTemp);
        iWinningPlayable = objCommons->Playable_X;
        retVal = true;
    }
    else if(listSDiaO.size() == static_cast<size_t>(iBoardSize))
    {
        SaveVictorySet(objCommons->MatrixProperties_SecondaryDiagonal, iTemp);
        iWinningPlayable = objCommons->Playable_O;
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

bool GameBoard::SaveVictorySet(Commons::MatrixProperties Property, int& iIndex)
{
    switch(Property)
    {
        case objCommons->MatrixProperties_Row:
        for(int iCount = 0; iCount < iBoardSize; iCount++)
        {
            listVictorySet.push_back(pair<int,int> {iIndex, iCount});
        }
        break;

        case objCommons->MatrixProperties_Column:
        for(int iCount = 0; iCount < iBoardSize; iCount++)
        {
            listVictorySet.push_back(pair<int,int> {iCount, iIndex});
        }
        break;

        case objCommons->MatrixProperties_PrimaryDiagonal:
        for(int iCount = 0; iCount < iBoardSize; iCount++)
        {
            listVictorySet.push_back(pair<int,int> {iCount, iCount});
        }
        break;

        case objCommons->MatrixProperties_SecondaryDiagonal:
        for(int iCount = 0, jCount = (iBoardSize - 1); (iCount < iBoardSize), (jCount >= 0); iCount++, jCount--)
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

int GameBoard::GetWinningPlayable()
{
    return iWinningPlayable;
}