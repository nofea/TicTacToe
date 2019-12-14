#include "ComputerBlocker.hpp"

using namespace std;

ComputerBlocker::ComputerBlocker()
{
}

ComputerBlocker::ComputerBlocker(int iPlayerChoice)
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

pair<int,int> ComputerBlocker::ComputeMove(vector<vector<int>> vecGameBoard)
{
    pair<int,int> pairCoordinates;

    if(vecVictoryConditions.empty())
    {
        MakeVictoryConditionsList(vecGameBoard.size());
    }

    return pairCoordinates;
}

bool ComputerBlocker::MakeVictoryConditionsList(int iGameBoardSize)
{
    int iNumOfVictoryConditions = (iGameBoardSize * 2) + 2;

    for (int i = 0; i < iNumOfVictoryConditions; i++)
    {
        /* code */
    }
    
    return true;
}