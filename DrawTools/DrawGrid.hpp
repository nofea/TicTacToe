#ifndef __DRAWGRID_HPP__
#define __DRAWGRID_HPP__

#include <vector>
#include <string>

class DrawGrid
{
private:
    /* data */
public:
    DrawGrid();
    ~DrawGrid();
    DrawGrid(const DrawGrid& obj);
    DrawGrid& operator=(const DrawGrid& obj);

public:
    std::string DrawGameBoard(const std::vector<std::vector<int>>& vecGameBoard);
};

#endif