#include "Computer.hpp" 

using namespace std;

Computer::Computer()
{
}

Computer::Computer(int& iPlayerChoice)
{
    iPlayable = iPlayerChoice;
}

Computer::Computer(const Computer& obj)
{
    iPlayable = obj.iPlayable;
}

Computer& Computer::operator=(const Computer& obj)
{
    iPlayable = obj.iPlayable;
    return *this;
}

Computer::~Computer()
{
}


void Computer::SetPlayable(int iPlayerChoice)
{
    iPlayable = iPlayerChoice;
}

int Computer::GetPlayable()
{
    return(iPlayable);
}

pair<int,int> Computer::ComputeMove(const vector<vector<int>>& vecGameBoard)
{
    pair<int,int> pairCoordinates(-1,-1);
    return pairCoordinates;
}