#include "DrawGrid.hpp"

using namespace std;

/**
 * @brief Construct a new Draw Grid:: Draw Grid object
 * 
 */
DrawGrid::DrawGrid()
{
    ObjCommons = Commons::GetInstance();
}

/**
 * @brief Destroy the Draw Grid:: Draw Grid object
 * 
 */
DrawGrid::~DrawGrid()
{
}

/**
 * @brief Construct a new Draw Grid:: Draw Grid object
 * 
 * @param obj 
 */
DrawGrid::DrawGrid(const DrawGrid& obj)
{
    ObjCommons = obj.ObjCommons;
}

/**
 * @brief 
 * 
 * @param obj 
 * @return DrawGrid& 
 */
DrawGrid& DrawGrid::operator=(const DrawGrid& obj)
{
    this->ObjCommons = obj.ObjCommons;
    return *this;
}

/**
 * @brief This function is used to draw the TicTacToe board
 * 
 * @param vecGameBoard [in] game board in vector format
 * @return string      game board in printable format
 */
string DrawGrid::DrawGameBoard(const vector<vector<int>>& vecGameBoard)
{
    string sGB(""); 

    for (auto it = vecGameBoard.begin(); it != vecGameBoard.end(); ++it)
    {
        for (auto jt = it->begin(); jt != it->end(); ++jt)
        {
            switch (*jt)
            {
                case ObjCommons->Playable_X:
                    sGB += "X";
                    break;
                
                case ObjCommons->Playable_O:
                    sGB += "O";
                    break;
                
                default:
                    sGB += "--";
                    break;
            }
            
            sGB += " ";
        }
        sGB += "\n"; 
    }
    
    return(sGB);
}
