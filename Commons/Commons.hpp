#ifndef __COMMONS_HPP__
#define __COMMONS_HPP__

#include <iostream>


#define DEFAULTGAMEBOARDSIZE 3
#define LOGGERPATHNAME "log"
#define GAMEBOARDINITVALUE -1
#define ZERO 0
#define NUMBEROFRETRIES 3

/**
 * @brief holds elements common to all classes in TicTacToe.
 * It is a singleton class
 * 
 */
class Commons
{
private:
    static Commons* objCommons;

public:

    /**
     * @brief holds types of players available in the game
     * 
     */
    enum PlayerType
    {
        PlayerType_None,
        PlayerType_Human,
        PlayerType_ComputerBlocker,
        PlayerType_Max
    };

    /**
     * @brief Player selection for TicTacToe
     * 
     */
    enum Playable
    {
        Playable_None,
        Playable_X,
        Playable_O
    };

    /**
     * @brief holds properties of a mathematical matrix
     * 
     */
    enum MatrixProperties
    {
        MatrixProperties_None,
        MatrixProperties_Row,
        MatrixProperties_Column,
        MatrixProperties_PrimaryDiagonal,
        MatrixProperties_SecondaryDiagonal
    };

    /**
     * @brief holds game options
     * 
     */
    enum GameSettings
    {
        GameSettings_None,
        GameSettings_GameMode,
        GameSettings_ComputerMatchSpeed,
        GameSettings_PlayerType,
        GameSettings_Max       
    };

    /**
     * @brief holds one of the game options --> Game Mode
     * 
     */
    enum GameMode
    {
        GameMode_None,
        GameMode_HumanVComputer,
        GameMode_ComputerVComputer,
        GameMode_HumanVHuman,
        GameMode_Max
        
    };

    /**
     * @brief holds one of the game option --> Computer Match Speed 
     * 
     */
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