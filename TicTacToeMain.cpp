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

int main()
{   
    Logger Log;
    Commons* objCommons = Commons::GetInstance();
    Arena A;
    int iGameMode = 0;
    bool bGameModeSelected = false;
    map<Commons::GameSettings, int> mapGameSettings;

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
    if(!A.PlayMatch(mapGameSettings, Log))
    {
        cout << "Error! Something has gone wrong in the Arena" << endl;
    }

    Log.CloseLoggerFile();
    return 0;
}
