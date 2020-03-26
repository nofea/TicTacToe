#ifndef __DRAWGRID_HPP__
#define __DRAWGRID_HPP__

#include <vector>
#include <string>

class DrawGrid
{
private:
    /* data */
public:
    DrawGrid(/* args */);
    ~DrawGrid();

public:
    std::string DrawGameBoard(const std::vector<std::vector<int>>& vecGameBoard);
};

#endif