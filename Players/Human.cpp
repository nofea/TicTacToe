#include "Human.hpp"

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
    return(iPlayable)
}