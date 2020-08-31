#include "Human.hpp"

using namespace std;

Human::Human()
{
}

Human::Human(int iPlayerChoice)
{
    iPlayable = iPlayerChoice;
}

Human::Human(const Human& obj)
{
    iPlayable = obj.iPlayable;
}

Human& Human::operator=(const Human& obj)
{
    iPlayable = obj.iPlayable;

    return *this;
}

Human::~Human()
{
}

void Human::SetPlayable(int iPlayerChoice)
{
    iPlayable = iPlayerChoice;
}

int Human::GetPlayable()
{
    return(iPlayable);
}

pair<int,int> Human::ComputeMove(const vector<vector<int>>& vecGameBoard)
{
    return pair<int,int>(-1,-1);
}

bool Human::RememberMyPosition(const std::pair<int,int>& pairCoords)
{
    return false;
}