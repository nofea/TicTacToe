#include <iostream>
#include <list>
#include "Commons.hpp"

class Arena
{
private:
    Commons* ObjCommons;
public:
    Arena();
    ~Arena();
    Arena(const Arena& obj);
    Arena& operator= (const Arena& obj);

    bool PlayMatch();
};
