#ifndef __COMMONS_HPP__
#define __COMMONS_HPP__

#include <iostream>


#define DEFAULTGAMEBOARDSIZE 3
#define LOGGERPATHNAME "log"
#define GAMEBOARDINITVALUE -1
#define ZERO 0
#define NUMBEROFRETRIES 3

class Commons
{
private:
    static Commons* objCommons;

public:

    enum Playable
    {
        Playable_None,
        Playable_X,
        Playable_O
    };

    enum MatrixProperties
    {
        MatrixProperties_None,
        MatrixProperties_Row,
        MatrixProperties_Column,
        MatrixProperties_PrimaryDiagonal,
        MatrixProperties_SecondaryDiagonal
    };

    enum GameMode
    {
        GameMode_None,
        GameMode_HumanVComputer,
        GameMode_HumanVHuman,
        GameMode_ComputerVComputer
    };

    enum GameSettingsComputerMatchSpeed
    {
        GameSettingsMatchSpeed_NONE,
        GameSettingsMatchSpeed_NORMAL,
        GameSettingsMatchSpeed_FAST
    };

private:
    Commons();
    ~Commons();
    Commons(const Commons& obj);
    Commons& operator=(const Commons& obj);


public:
    static Commons* GetInstance()
    {
        if(!objCommons)
        {
            objCommons = new Commons;
        }

        return objCommons;
    }
};

#endif