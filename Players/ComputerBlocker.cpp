#include "ComputerBlocker.hpp"
#include <algorithm>

using namespace std;

ComputerBlocker::ComputerBlocker()
{
}

ComputerBlocker::ComputerBlocker(int& iPlayerChoice)
: Player()
{
    iPlayable = iPlayerChoice;
    objCommons = Commons::GetInstance();
}

ComputerBlocker::ComputerBlocker(const ComputerBlocker& obj)
: Player()
{
    iPlayable = obj.iPlayable;
    vecVictoryConditions = obj.vecVictoryConditions;
    listEnemyPositions = obj.listEnemyPositions;
    listMyPositions = obj.listMyPositions;
}

ComputerBlocker& ComputerBlocker::operator=(const ComputerBlocker& obj)
{
    iPlayable = obj.iPlayable;
    vecVictoryConditions = obj.vecVictoryConditions;
    listEnemyPositions = obj.listEnemyPositions;
    listMyPositions = obj.listMyPositions;
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

pair<int,int> ComputerBlocker::ComputeMove(const vector<vector<int>>& vecGameBoard)
{
    pair<int,int> pairCoordinates(-1,-1);
    int iCoordinate = -1, iVictoryCondition = -1;
    list<pair<int,int>>::iterator ft;
    vector<int>::iterator itMax;
    int iBoardSize = vecGameBoard.size();
    bool bFound = false;
    vector<pair<int,int>> vecEmptySpaces;

    if(vecVictoryConditions.empty())
    {
        MakeVictoryConditionsList(iBoardSize);
    }
    vector<int> vecPredictionCounter(vecVictoryConditions.size(), 0);

    if(!UpdateEnemyPosition(vecGameBoard))
    {
        // The first move
        iCoordinate = rand() % iBoardSize;
        pairCoordinates.first = iCoordinate;
        pairCoordinates.second = iCoordinate;
    }
    else
    {
        for(auto it = listEnemyPositions.begin(); it != listEnemyPositions.end(); ++it)
        {
            for(auto ivec = vecVictoryConditions.begin(); ivec != vecVictoryConditions.end(); ++ivec)
            {
                
                ft = find(ivec->begin(), ivec->end(), *it);

                if(ft != ivec->end())
                {
                    vecPredictionCounter.at(ivec - vecVictoryConditions.begin())++;
                }      
            }
        }

        while(!bFound)
        {
            if(iVictoryCondition != -1)
            {
                vecPredictionCounter.erase(itMax);
            }
            
            if(vecPredictionCounter.size() == 0)
            {
                //concede
                break;
            }

            itMax = max_element(vecPredictionCounter.begin(), vecPredictionCounter.end());  
            iVictoryCondition = itMax - vecPredictionCounter.begin();

            if(vecPredictionCounter.at(iVictoryCondition) == iBoardSize) // this line is causing problems!!!
            {
                // concede
                break;
            }

            for(auto itList = vecVictoryConditions.at(iVictoryCondition).begin(); itList != vecVictoryConditions.at(iVictoryCondition).end(); ++itList)
            {
                ft = find(listEnemyPositions.begin(), listEnemyPositions.end(), *itList);

                if(ft == listEnemyPositions.end())
                {
                    if(!AlreadyMadeThisMove(*itList))
                    {
                        pairCoordinates = *itList;
                        bFound = true;
                        break;
                    }
                }
            }
        }
        
        if(!bFound)
        {
            vecEmptySpaces = GetEmptySpaces(vecGameBoard);

            if(!vecEmptySpaces.empty())
            {
                iCoordinate = rand() % vecEmptySpaces.size();
                pairCoordinates = vecEmptySpaces.at(iCoordinate);
            }
        }     
    }
    return pairCoordinates;
}

bool ComputerBlocker::MakeVictoryConditionsList(int& iGameBoardSize)
{
    list<pair<int,int>> listTempRow, listTempCol, listTempPDia, listTempSDia;

    for(int j = 0, i = (iGameBoardSize - 1); (j < iGameBoardSize), (i >= 0); j++, i--)
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

bool ComputerBlocker::UpdateEnemyPosition(const vector<vector<int>>& vecGameBoard)
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

bool ComputerBlocker::RememberMyPosition(const pair<int,int>& pairCoords)
{
    bool retValue = true;

    if(!AlreadyMadeThisMove(pairCoords))
    {
        listMyPositions.push_back(pairCoords);
    }

    return retValue;
}

bool ComputerBlocker::AlreadyMadeThisMove(const pair<int,int>& pairCoords)
{
    bool retValue = true;

    auto it = find(listMyPositions.begin(), listMyPositions.end(), pairCoords);

    if(it == listMyPositions.end())
    {
        retValue = false;
    }

    return retValue;
}

//optimize this
vector<pair<int,int>> ComputerBlocker::GetEmptySpaces(const vector<vector<int>>& vecGameBoard)
{
    vector<pair<int,int>> vecEmptySpaces;

    int iGameBoardSize = vecGameBoard.size();

    for(int i = 0; i < iGameBoardSize; i++)
    {
        for (int j = 0; j < iGameBoardSize; j++)
        {
            if(vecGameBoard.at(i).at(j) == -1)
            {
                vecEmptySpaces.push_back(pair<int,int>(i, j));
            } 
        }
    }

    return vecEmptySpaces;
}