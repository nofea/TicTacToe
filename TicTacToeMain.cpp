#include <iostream>
#include <string>
#include <map>
#include "Commons.hpp"
#include "GameBoard.hpp"
#include "Logger.hpp"
#include "ComputerBlocker.hpp"
#include "Human.hpp"
#include "DrawGrid.hpp"
#include "Arena.hpp"


using namespace std;

int main(int argc,char* argv[])
{   
    Logger Log;
    Commons* objCommons = Commons::GetInstance();
    Arena A;
    int iGameMode = 0, iGameSpeed = 0;
    bool bGameModeSelected = false;
    map<Commons::GameSettings, int> mapGameSettings;
    bool bAutisticMode = false;

    if(argc > 1)
    {
        bAutisticMode = true;
        iGameMode = stoi(string(argv[1]));

        if(iGameMode == objCommons->GameMode_ComputerVComputer)
        {
            // I going to leave this empty for now as there is no real use for it, yet...
        }
        else if(iGameMode == objCommons->GameMode_HumanVComputer)
        {
            if(argc < 4) // 1 + 3 for game mode, game speed and selection of X or O
            {
                cout << "Error! of arguments" << endl;
                cout << "Exiting Game..." << endl;
                return 0;
            }
            iGameSpeed = stoi(string(argv[2])); // unused
            mapGameSettings.insert(pair<Commons::GameSettings,int>(objCommons->GameSettings_PlayerType, stoi(string(argv[3]))));
        }
        else
        {
            cout << "Error! Invalid Game Mode" << endl;
            cout << "Exiting Game..." << endl;
            return 0;
        }
           
        bGameModeSelected = true;
    }

    try
    {
        if(!Log.OpenLoggerFile(LOGGERPATHNAME))
        {
            cout << "Error! Failed to Initialize Logger!" << endl;
            cout << "Terminating..." << endl;
            return 0;
        }
    }
    catch(const exception& e)
    {
        cerr << e.what() << endl;
    }

    cout << "Welcome to a game of Tic Tac Toe!!!" << endl << endl << endl;

    while(!bGameModeSelected)
    {
        cout << "Choose Game Mode" << endl << endl;

        cout << "(1) Versus Computer" << endl;
        cout << "(2) Computer Versus Computer" << endl;

        cin >> iGameMode;

        if(iGameMode > objCommons->GameMode_ComputerVComputer || 
            iGameMode < objCommons->GameMode_HumanVComputer)
        {
            cout << "Pick (1) or (2) Doofus!!!" << endl;
        }
        else
        {
            bGameModeSelected = true;
        } 
    }
    
    mapGameSettings.insert(pair<Commons::GameSettings,int>(objCommons->GameSettings_GameMode, iGameMode));
    
    // implementation of game speed pending
    mapGameSettings.insert(pair<Commons::GameSettings,int>(objCommons->GameSettings_ComputerMatchSpeed, objCommons->GameSettingsMatchSpeed_NORMAL));

    
    Log.LogMessage("Game Mode: " + to_string(mapGameSettings.at(objCommons->GameSettings_GameMode)));
    Log.LogMessage("Comuter Match Speed: " + to_string(mapGameSettings.at(objCommons->GameSettings_ComputerMatchSpeed)));

    if(!A.PlayMatch(mapGameSettings, bAutisticMode, Log))
    {
        cout << "Error! Something has gone wrong in the Arena" << endl;
    }

    Log.CloseLoggerFile();
    return 0;
}
