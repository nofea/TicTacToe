#include <algorithm>
#include "Arena.hpp"
#include "DrawGrid.hpp"

using namespace std;

/**
 * @brief Construct a new Arena:: Arena object
 * 
 */
Arena::Arena()
{
    objCommons = Commons::GetInstance();
}

/**
 * @brief Destroy the Arena:: Arena object
 * 
 */
Arena::~Arena()
{
}

/**
 * @brief Construct a new Arena:: Arena object
 * 
 * @param obj   [in] object reference of class Arena
 */
Arena::Arena(const Arena& obj)
{
    objCommons = obj.objCommons;
    ObjPlayer_1 = obj.ObjPlayer_1;
    ObjPlayer_2 = obj.ObjPlayer_2;
}

/**
 * @brief Assignment operator
 * 
 * @param obj [in] object reference of class Arena
 * @return Arena& 
 */
Arena& Arena::operator=(const Arena& obj)
{
    this->objCommons = obj.objCommons;
    this->ObjPlayer_1 = obj.ObjPlayer_1;
    this->ObjPlayer_2 = obj.ObjPlayer_2;
    return *this;
}

/**
 * @brief This function contains the main game logic loop
 * 
 * @param mapGameSettings [in] values used to set up the game 
 * @param bAutisticMode   [in] set true to suppress all user facing echos/couts, logging still works 
 * @param Log             [in] logger object used to log events in the game
 * @return true           if all goes well in the game loop
 * @return false          if all is not well in the game loop
 */
bool Arena::PlayMatch(map<Commons::GameSettings, int>& mapGameSettings, bool& bAutisticMode, Logger& Log)
{
    bool bRetVal = false;
    string sPlayable(""), sGameBoard("");
    DrawGrid DG;
    PlayerFactory PF;
    signed int iXCoord = 0, iYCoord = 0, iMoveCounter = 0;
    bool bMarked = false;
    pair<int, int> pairCoords = pair<int,int>(-1,-1);
    signed int iRetry = 0;
    int iWinningPlayable = -1;

    Log.LogMessage("Setting up Match...");
    if(!MatchSetup(mapGameSettings, PF))
    {
        return false;
    }
    Log.LogMessage("Match Set!");
    
    if (mapGameSettings.at(objCommons->GameSettings_GameMode) == objCommons->GameMode_HumanVComputer)
    {
        if(mapGameSettings.at(objCommons->GameSettings_PlayerType) == objCommons->Playable_O)
        {
            ObjPlayer_1->SetPlayable(objCommons->Playable_O);
            ObjPlayer_2->SetPlayable(objCommons->Playable_X);
        }
        else if(mapGameSettings.at(objCommons->GameSettings_PlayerType) == objCommons->Playable_X)
        {
            ObjPlayer_1->SetPlayable(objCommons->Playable_X);
            ObjPlayer_2->SetPlayable(objCommons->Playable_O);
        }
        else
        {
            cout << "Invalid Player Type" << endl;
            cout << "Exiting Game..." << endl;
            return bRetVal;
        }
        
        Log.LogMessage("The Human chose: "+ to_string(ObjPlayer_1->GetPlayable()), iMoveCounter);
        Log.LogMessage("The Computer was given: "+ to_string(ObjPlayer_2->GetPlayable()), iMoveCounter);
    }
    else if(mapGameSettings.at(objCommons->GameSettings_GameMode) == objCommons->GameMode_ComputerVComputer)
    {
        ObjPlayer_1->SetPlayable(objCommons->Playable_X);
        ObjPlayer_2->SetPlayable(objCommons->Playable_O);

        Log.LogMessage("Player 1 is "+ to_string(ObjPlayer_1->GetPlayable()), iMoveCounter);
        Log.LogMessage("Player 2 is "+ to_string(ObjPlayer_2->GetPlayable()), iMoveCounter);
    }

    GameBoard GB(DEFAULTGAMEBOARDSIZE);
    Log.LogMessage("Game Board Initialized with size: "+ to_string(DEFAULTGAMEBOARDSIZE), iMoveCounter);

    sGameBoard = DG.DrawGameBoard(GB.ShowGameBoard());
    cout << "The Game Board:" << endl;
    cout << sGameBoard << endl;
    Log.LogMessage("\n"+sGameBoard, iMoveCounter);
    
    cout << "X goes first" << endl;
    iMoveCounter++;  

    if(ObjPlayer_2->GetPlayable() == objCommons->Playable_X)
    {
        try
        {
            while(++iRetry < NUMBEROFRETRIES)
            {
                pairCoords = ObjPlayer_2->ComputeMove(GB.ShowGameBoard());
                if(GB.MarkBoard(pairCoords, ObjPlayer_2->GetPlayable()))
                {
                    ObjPlayer_2->RememberMyPosition(pairCoords);
                    break;
                }
            }
            iRetry = 0;
            if(mapGameSettings.at(objCommons->GameSettings_GameMode) == objCommons->GameMode_HumanVComputer)
            {
                Log.LogMessage("The Computer played: "+ to_string(pairCoords.first)+ ", " + to_string(pairCoords.second), iMoveCounter);
            }
            else if(mapGameSettings.at(objCommons->GameSettings_GameMode) == objCommons->GameMode_ComputerVComputer)
            {
                Log.LogMessage("Player 2 played: "+ to_string(pairCoords.first)+ ", " + to_string(pairCoords.second), iMoveCounter);
            }
            
            sGameBoard = DG.DrawGameBoard(GB.ShowGameBoard());
            cout << "The Game Board:" << endl;
            cout << sGameBoard << endl;
            Log.LogMessage("\n"+sGameBoard, iMoveCounter);
        }
        catch(const std::exception& e)
        {
            cerr << e.what() << endl;
            Log.LogError(e.what(), iMoveCounter);
        }
    }

    // and so let the games begin...
    while(!GB.IsEndOfGame())
    {
        bMarked = false;
        pairCoords = pair<int,int>(-1,-1);   

        if(mapGameSettings.at(objCommons->GameSettings_GameMode) == objCommons->GameMode_HumanVComputer)
        {
            cout << "Key in x y Coordinates" << endl;
        }

    
        while(!bMarked)
        {
            if(mapGameSettings.at(objCommons->GameSettings_GameMode) == objCommons->GameMode_HumanVComputer)
            {
                cin >> iXCoord >> iYCoord;
            }
            else if(mapGameSettings.at(objCommons->GameSettings_GameMode) == objCommons->GameMode_ComputerVComputer)
            {
                pairCoords = ObjPlayer_1->ComputeMove(GB.ShowGameBoard());
                iXCoord = pairCoords.first;
                iYCoord = pairCoords.second;
            }
            

            if(iXCoord < DEFAULTGAMEBOARDSIZE && iYCoord < DEFAULTGAMEBOARDSIZE)
            {
                if(mapGameSettings.at(objCommons->GameSettings_GameMode) == objCommons->GameMode_HumanVComputer)
                {
                    Log.LogMessage("The Human keyed in: "+ to_string(iXCoord) +", "+ to_string(iYCoord), iMoveCounter);
                }
                else if(mapGameSettings.at(objCommons->GameSettings_GameMode) == objCommons->GameMode_ComputerVComputer)
                {
                    Log.LogMessage("Player 1 keyed in: "+ to_string(iXCoord) +", "+ to_string(iYCoord), iMoveCounter);
                }
                
                try
                {
                    if(!GB.MarkBoard(pair<signed int, signed int>(iXCoord, iYCoord), ObjPlayer_1->GetPlayable()))
                    {
                        if(mapGameSettings.at(objCommons->GameSettings_GameMode) == objCommons->GameMode_HumanVComputer)
                        {
                            Log.LogError("The Human keyed in: "+ to_string(iXCoord) +", "+ to_string(iYCoord), iMoveCounter);
                            cout << "This coordinate is already marked, pick a different position..." << endl; 
                        }
                        else if(mapGameSettings.at(objCommons->GameSettings_GameMode) == objCommons->GameMode_ComputerVComputer)
                        {
                            Log.LogError("Player 1 keyed in: "+ to_string(iXCoord) +", "+ to_string(iYCoord), iMoveCounter);
                        }
                
                    }
                    else
                    {
                        bMarked = true;
                        ObjPlayer_1->RememberMyPosition(pairCoords);
                    }  
                }
                catch(const std::exception& e)
                {
                    cerr << e.what() << endl;
                    Log.LogError(e.what(), iMoveCounter);
                }
                                 
            }
            else
            {
                if(mapGameSettings.at(objCommons->GameSettings_GameMode) == objCommons->GameMode_HumanVComputer)
                {
                    Log.LogError("The Human keyed in: "+ to_string(iXCoord) +", "+ to_string(iYCoord), iMoveCounter);
                    cout << "The x and y coordinates have to be between and including 0 and "+ to_string(DEFAULTGAMEBOARDSIZE - 1) << endl;
                    cout << "Try again..." << endl;
                }
                else if(mapGameSettings.at(objCommons->GameSettings_GameMode) == objCommons->GameMode_ComputerVComputer)
                {
                    Log.LogError("Player 1 keyed in "+ to_string(iXCoord) +", "+ to_string(iYCoord), iMoveCounter);
                }
            }
        }

        try
        {
            while(++iRetry < NUMBEROFRETRIES)
            {
                pairCoords = ObjPlayer_2->ComputeMove(GB.ShowGameBoard());
                if(GB.MarkBoard(pairCoords, ObjPlayer_2->GetPlayable()))
                {
                    ObjPlayer_2->RememberMyPosition(pairCoords);
                    break;
                }
            }
            iRetry = 0;
            
            if(mapGameSettings.at(objCommons->GameSettings_GameMode) == objCommons->GameMode_HumanVComputer)
            {
                Log.LogMessage("The Computer played: "+ to_string(pairCoords.first)+ ", " + to_string(pairCoords.second), iMoveCounter);    
            }
            else if(mapGameSettings.at(objCommons->GameSettings_GameMode) == objCommons->GameMode_ComputerVComputer)
            {
                Log.LogMessage("Player 2 played: "+ to_string(pairCoords.first)+ ", " + to_string(pairCoords.second), iMoveCounter);    
            }        
            
        }
        catch(const std::exception& e)
        {
            cerr << e.what() << endl;
            Log.LogError(e.what(), iMoveCounter);
        }

        sGameBoard = DG.DrawGameBoard(GB.ShowGameBoard());
        cout << "The Game Board:" << endl;
        cout << sGameBoard << endl;
        Log.LogMessage("\n"+sGameBoard, iMoveCounter);

        iMoveCounter++;
    }
    
    cout << endl;
    cout << endl;
    cout << "Game Over!!!" << endl;
    Log.LogMessage("Game Over!!!");
    bRetVal = true;

    iWinningPlayable = GB.GetWinningPlayable();

    if(iWinningPlayable == ObjPlayer_1->GetPlayable())
    {
        if(mapGameSettings.at(objCommons->GameSettings_GameMode) == objCommons->GameMode_HumanVComputer)
        {
            cout << "You Won!!!" << endl;
            Log.LogMessage("You Won!!!");
        }
        else if(mapGameSettings.at(objCommons->GameSettings_GameMode) == objCommons->GameMode_ComputerVComputer)
        {
            cout << "Player 1 Wins!!!" << endl;
            Log.LogMessage("Player 1 Wins!!!");
        }
    }
    else if(iWinningPlayable == ObjPlayer_2->GetPlayable())
    {
        if(mapGameSettings.at(objCommons->GameSettings_GameMode) == objCommons->GameMode_HumanVComputer)
        {
            cout << "The Computer Won!!!" << endl;
            Log.LogMessage("The Computer Won!!!");
        }
        else if(mapGameSettings.at(objCommons->GameSettings_GameMode) == objCommons->GameMode_ComputerVComputer)
        {
            cout << "Player 2 Wins!!!" << endl;
            Log.LogMessage("Player 2 Wins!!!");
        }
    }
    else
    {
        cout << "It is a Stalemate!!!" << endl;
        Log.LogMessage("It is a Stalemate!!!");
    }
    

    sGameBoard = DG.DrawGameBoard(GB.ShowGameBoard());
    cout << "The Game Board:" << endl;
    cout << sGameBoard << endl;
    Log.LogMessage("\n"+sGameBoard, iMoveCounter); 

    if(!bAutisticMode)
    {
        // wait for user input
        cin.get(); // safety workaround
        cin.get(); 
    }

    return bRetVal;
}

/**
 * @brief Used mapGameSettings to set up the game, accordingly
 * 
 * @param mapGameSettings [in] values used to set up the game
 * @param PF              [in] object reference to the class PlayerFactory, used to instantiate players for the game 
 * @return true           if all is ok
 * @return false          if all is not ok
 */
bool Arena::MatchSetup(map<Commons::GameSettings, int>& mapGameSettings, PlayerFactory& PF)
{
    bool bRetVal = false;

    // determine game mode
    switch (mapGameSettings.at(objCommons->GameSettings_GameMode))
    {
    case objCommons->GameMode_HumanVComputer:
        ObjPlayer_1 = PF.AssignPlayer(objCommons->PlayerType_Human);
        ObjPlayer_2 = PF.AssignPlayer(objCommons->PlayerType_ComputerBlocker);
        break;

    case objCommons->GameMode_ComputerVComputer:   
        ObjPlayer_1 = PF.AssignPlayer(objCommons->PlayerType_ComputerBlocker);
        ObjPlayer_2 = PF.AssignPlayer(objCommons->PlayerType_ComputerBlocker);
        break;

    case objCommons->GameMode_HumanVHuman:
    default:
        return bRetVal;
    }

    // this setting is mostly for showing player turns
    switch (mapGameSettings.at(objCommons->GameSettings_ComputerMatchSpeed))
    {
    case objCommons->GameSettingsMatchSpeed_NORMAL:
        break;

    case objCommons->GameSettingsMatchSpeed_FAST:
        break;
    
    default:
        return bRetVal;
    }

    bRetVal = true;
    return bRetVal;
}
