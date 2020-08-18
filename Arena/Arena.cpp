#include "Arena.hpp"

using namespace std;

Arena::Arena()
{
    ObjCommons = Commons::GetInstance();
}

Arena::~Arena()
{
}

Arena::Arena(const Arena& obj)
{
}

Arena& Arena::operator=(const Arena& obj)
{
    return *this;
}

bool Arena::PlayMatch()
{
    bool bRetVal = false;
    return bRetVal;
}