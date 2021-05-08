#include "Commons.hpp"

Commons* Commons::objCommons = 0;

Commons::Commons()
{
}

Commons::~Commons()
{
    delete objCommons;
}

Commons::Commons(const Commons& obj)
{
    objCommons = obj.objCommons;
}

Commons& Commons::operator=(const Commons& obj)
{
    this->objCommons = obj.objCommons;
    return *this;
}