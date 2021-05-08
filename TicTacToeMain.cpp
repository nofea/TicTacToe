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
    int iGameMode = 0;
    bool bGameModeSelected = false;
    map<Commons::GameSettings, int> mapGameSettings;
    bool bAutisticMode = false;
    bool bPlayableSelected = false;
    string sPlayable("");

    if(argc > 1)
    {
        bAutisticMode = true;
        iGameMode = stoi(string(argv[1]));

        if(argc < 4) // 1 + 3 for game mode, game speed and selection of X or O
        {
            cout << "Error! of arguments" << endl;
            Log.LogError("Error! of arguments");
            cout << "Exiting Game..." << endl;
            return 0;
        }

        mapGameSettings.insert(pair<Commons::GameSettings,int>(objCommons->GameSettings_PlayerType, stoi(string(argv[3]))));
           
        bGameModeSelected = true;
        bPlayableSelected = true;
    }

    try
    {
        if(!Log.OpenLoggerFile(LOGGERPATHNAME))
        {
            cout << "Error! Failed to Initialize Logger!" << endl;
            Log.LogError("Error! Failed to Initialize Logger!");
            cout << "Exiting Game..." << endl;
            return 0;
        }
    }
    catch(const exception& e)
    {
        cerr << e.what() << endl;
        Log.LogError(e.what());
        cout << "Exiting Game..." << endl;
        return 0;
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

    while(!bPlayableSelected)
    {
        cout << "Do you want to be X's or O's?" << endl;
        cin >> sPlayable;

        try
        {
            transform(sPlayable.begin(), sPlayable.end(), sPlayable.begin(), ::toupper);
            if(sPlayable == "X")
            {
                mapGameSettings.insert(pair<Commons::GameSettings,Commons::Playable>(objCommons->GameSettings_PlayerType, objCommons->Playable_X));
                bPlayableSelected = true;
            }
            else if(sPlayable == "O")
            {
                mapGameSettings.insert(pair<Commons::GameSettings,Commons::Playable>(objCommons->GameSettings_PlayerType, objCommons->Playable_O));
                bPlayableSelected = true;
            }
            else
            {
                cout << "Bruh, pick X or O..." << endl;
            }
        }
        catch(const std::exception& e)
        {
            cerr << e.what() << endl;
            Log.LogError(e.what());
            cout << "Exiting Game..." << endl;
            return 0;
        }
    }

    if(!A.PlayMatch(mapGameSettings, bAutisticMode, Log))
    {
        cout << "Error! Something has gone wrong in the Arena" << endl;
    }

    Log.CloseLoggerFile();
    return 0;
}
