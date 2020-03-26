#include "DrawGrid.hpp"
#include "Commons.hpp"

using namespace std;

DrawGrid::DrawGrid(/* args */)
{
}

DrawGrid::~DrawGrid()
{
}

string DrawGrid::DrawGameBoard(const vector<vector<int>>& vecGameBoard)
{
    string sGB(""); 

    for (auto it = vecGameBoard.begin(); it != vecGameBoard.end(); ++it)
    {
        for (auto jt = it->begin(); jt != it->end(); ++jt)
        {
            switch (*jt)
            {
                case Playable_X:
                    sGB += "X";
                    break;
                
                case Playable_O:
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