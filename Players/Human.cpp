#include "Human.hpp"

using namespace std;

Human::Human()
: Player()
{
}

Human::Human(int iPlayerChoice)
: Player()
{
    iPlayable = iPlayerChoice;
}

Human::Human(const Human& obj)
: Player()
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
    static_cast<void>(vecGameBoard); // to avoid compiler error
    return pair<int,int>(-1,-1);
}

bool Human::RememberMyPosition(const std::pair<int,int>& pairCoords)
{
    static_cast<void>(pairCoords); // to avoid compiler error
    return false;
}