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

}

Commons& Commons::operator=(const Commons& obj)
{
    return *this;
}