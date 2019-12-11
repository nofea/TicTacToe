#include "ComputerBlocker.hpp"

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