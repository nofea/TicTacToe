#ifndef __COMMONS_HPP__
#define __COMMONS_HPP__


#define DEFAULTGAMEBOARDSIZE 3
#define LOGGERPATHNAME "log.txt"
#define GAMEBOARDINITVALUE -1

enum Playable
{
    Playable_X,
    Playable_O
};

enum MatrixProperties
{
    MatrixProperties_Row,
    MatrixProperties_Column,
    MatrixProperties_PrimaryDiagonal,
    MatrixProperties_SecondaryDiagonal
};

#endif