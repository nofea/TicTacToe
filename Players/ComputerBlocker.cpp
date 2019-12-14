#include "ComputerBlocker.hpp"

using namespace std;

ComputerBlocker::ComputerBlocker()
{
}

ComputerBlocker::ComputerBlocker(int& iPlayerChoice)
{
    iPlayable = iPlayerChoice;
}

ComputerBlocker::ComputerBlocker(const ComputerBlocker& obj)
{
    iPlayable = obj.iPlayable;
}

ComputerBlocker& ComputerBlocker::operator=(const ComputerBlocker& obj)
{
    iPlayable = obj.iPlayable;
    return *this;
}

ComputerBlocker::~ComputerBlocker()
{
}

void ComputerBlocker::SetPlayable(int iPlayerChoice)
{
    iPlayable = iPlayerChoice;
}

int ComputerBlocker::GetPlayable()
{
    return(iPlayable);
}

pair<int,int> ComputerBlocker::ComputeMove(vector<vector<int>>& vecGameBoard)
{
    pair<int,int> pairCoordinates;
    int iCoordinate = -1;
    
    int iBoardSize = vecGameBoard.size();

    if(vecVictoryConditions.empty())
    {
        MakeVictoryConditionsList(iBoardSize);
    }

    if(!UpdateEnemyPosition(vecGameBoard))
    {
        // The first move
        iCoordinate = rand() % iBoardSize + 1;
        pairCoordinates.first = iCoordinate;
        pairCoordinates.second = iCoordinate;
    }
    else
    {
        
    }
    

    return pairCoordinates;
}

bool ComputerBlocker::MakeVictoryConditionsList(int& iGameBoardSize)
{
    int iNumOfVictoryConditions = (iGameBoardSize * 2) + 2;
    list<pair<int,int>> listTempRow, listTempCol, listTempPDia, listTempSDia;

    for(int j = 0, i = (iGameBoardSize - 1); j < iGameBoardSize, i >= 0; j++, i--)
    {
        for (int k = 0; k < iGameBoardSize; k++)
        {
            listTempRow.push_back(pair<int,int> {j,k});
            listTempCol.push_back(pair<int,int> {k,j});
        }
        vecVictoryConditions.push_back(listTempRow);
        vecVictoryConditions.push_back(listTempCol);
        listTempRow.clear();
        listTempCol.clear();

        listTempPDia.push_back(pair<int,int> {j,j});
        listTempSDia.push_back(pair<int,int> {j,i});
    }
    vecVictoryConditions.push_back(listTempPDia);
    vecVictoryConditions.push_back(listTempSDia);
    
    
    return true;
}

bool ComputerBlocker::UpdateEnemyPosition(vector<vector<int>>& vecGameBoard)
{
    int iBoardSize = vecGameBoard.size();
    bool bRetVal = true;
    list<pair<int,int>>::iterator it;

    for(int i = 0; i < iBoardSize; i++)
    {
        for (int j = 0; j < iBoardSize; j++)
        {
            if (vecGameBoard.at(i).at(j) != iPlayable 
            && vecGameBoard.at(i).at(j) != GAMEBOARDINITVALUE) 
            {
                it = find(listEnemyPositions.begin(), listEnemyPositions.end(), pair<int,int> {i,j});

                if(it == listEnemyPositions.end())
                {
                    listEnemyPositions.push_back(pair<int,int> {i,j});
                }
            } 
        }  
    }

    if(listEnemyPositions.empty())
    {
        bRetVal = false;
    }

    return bRetVal;
}