#include "Commons.hpp"

Commons* Commons::objCommons = 0;

/**
 * @brief Construct a new Commons:: Commons object
 * 
 */
Commons::Commons()
{
}

/**
 * @brief Destroy the Commons:: Commons object
 * 
 */
Commons::~Commons()
{
    delete objCommons;
}

/**
 * @brief Construct a new Commons:: Commons object
 * 
 * @param obj 
 */
Commons::Commons(const Commons& obj)
{
    objCommons = obj.objCommons;
}

/**
 * @brief Assignment operator for the class Commons
 * 
 * @param obj   [in] object reference to Commons
 * @return Commons& 
 */
Commons& Commons::operator=(const Commons& obj)
{
    this->objCommons = obj.objCommons;
    return *this;
}
