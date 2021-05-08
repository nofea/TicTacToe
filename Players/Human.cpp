#include "Human.hpp"

using namespace std;

/**
 * @brief Construct a new Human:: Human object
 * 
 */
Human::Human()
: Player()
{
}

/**
 * @brief Construct a new Human:: Human object
 * 
 * @param iPlayerChoice 
 */
Human::Human(int iPlayerChoice)
: Player()
{
    iPlayable = iPlayerChoice;
}

/**
 * @brief Construct a new Human:: Human object
 * 
 * @param obj [in] object of class Human
 */
Human::Human(const Human& obj)
: Player()
{
    iPlayable = obj.iPlayable;
}

/**
 * @brief Assignment operator overload for class Human
 * 
 * @param obj 
 * @return Human& 
 */
Human& Human::operator=(const Human& obj)
{
    iPlayable = obj.iPlayable;

    return *this;
}

/**
 * @brief Destroy the Human:: Human object
 * 
 */
Human::~Human()
{
}

/**
 * @brief setter function to set playable as X or O
 * 
 * @param iPlayerChoice [in] choice of X or O made by the player
 */
void Human::SetPlayable(int iPlayerChoice)
{
    iPlayable = iPlayerChoice;
}

/**
 * @brief getter function to retrieve player select X or O
 * 
 * @return int 
 */
int Human::GetPlayable()
{
    return(iPlayable);
}

/**
 * @brief The human computes it's own move
 * 
 * @param vecGameBoard [in] game board matrix (not in use)
 * @return pair<int,int> 
 */
pair<int,int> Human::ComputeMove(const vector<vector<int>>& vecGameBoard)
{
    static_cast<void>(vecGameBoard); // to avoid compiler error
    return pair<int,int>(-1,-1);
}

/**
 * @brief The Human can remember his own mark locations
 * 
 * @param pairCoords [in] game board matrix (not in use)
 * @return true 
 * @return false 
 */
bool Human::RememberMyPosition(const std::pair<int,int>& pairCoords)
{
    static_cast<void>(pairCoords); // to avoid compiler error
    return false;
}
