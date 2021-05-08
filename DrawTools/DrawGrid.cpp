#include "DrawGrid.hpp"


using namespace std;

DrawGrid::DrawGrid()
{
    ObjCommons = Commons::GetInstance();
}

DrawGrid::~DrawGrid()
{
}

DrawGrid::DrawGrid(const DrawGrid& obj)
{
    ObjCommons = obj.ObjCommons;
}

DrawGrid& DrawGrid::operator=(const DrawGrid& obj)
{
    this->ObjCommons = obj.ObjCommons;
    return *this;
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