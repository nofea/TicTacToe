#include <iostream>
#include <string>
#include <algorithm>
#include "Commons.hpp"
#include "GameBoard.hpp"
#include "Logger.hpp"
#include "ComputerBlocker.hpp"
#include "Human.hpp"
#include "DrawGrid.hpp"


using namespace std;

int main()
{   
    string sPlayable(""), sGameBoard("");
    Human H1;
    ComputerBlocker CB;
    Logger Log;
    DrawGrid DG;
    signed int iXCoord = 0, iYCoord = 0, iMoveCounter = 0;
    bool bMarked = false;
    pair<int, int> pairCoords;

    try
    {
        Log.OpenLoggerFile(LOGGERPATHNAME);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    
    cout << "Welcome to a game of Tic Tac Toe" << endl;

    while (1)
    {
        cout << "Do you want to be X's or O's?" << endl;
        cin >> sPlayable;

        transform(sPlayable.begin(), sPlayable.end(), sPlayable.begin(), ::toupper);

        if(sPlayable == "X")
        {
            H1.SetPlayable(Playable_X);
            CB.SetPlayable(Playable_O);
            break;
        }
        else if(sPlayable == "O")
        {
            H1.SetPlayable(Playable_O);
            CB.SetPlayable(Playable_X);
            break;
        }
        else
        {
            cout << "Bruh, pick X or O..." << endl;
            Log.LogError("The Human is being daft!!!", iMoveCounter);
        }
    }
    
    Log.LogMessage("The Human chose: "+ to_string(H1.GetPlayable()), iMoveCounter);
    Log.LogMessage("The Computer was given: "+ to_string(CB.GetPlayable()), iMoveCounter);

    GameBoard GB(DEFAULTGAMEBOARDSIZE);
    Log.LogMessage("Game Board Initialized with size: "+ to_string(DEFAULTGAMEBOARDSIZE), iMoveCounter);
    
    cout << "X goes first" << endl;  

    if(CB.GetPlayable() == Playable_X)
    {
        pairCoords = CB.ComputeMove(GB.ShowGameBoard());
        GB.MarkBoard(pairCoords, CB.GetPlayable());
        Log.LogMessage("The Computer played: "+ to_string(pairCoords.first)+ "," + to_string(pairCoords.second), iMoveCounter);

    }
    

    // and so let the games begin...
    while(!GB.IsEndOfGame())
    {
        bMarked = false;
        iMoveCounter++;
        
        sGameBoard = DG.DrawGameBoard(GB.ShowGameBoard());
        cout << "The Game Board:" << endl;
        cout << sGameBoard << endl;
        Log.LogMessage("\n"+sGameBoard, iMoveCounter);   
        
        cout << "Key in x y Coordinates" << endl;

        while(!bMarked)
        {
            cin >> iXCoord >> iYCoord;

            if(iXCoord < DEFAULTGAMEBOARDSIZE && iYCoord < DEFAULTGAMEBOARDSIZE)
            {
                Log.LogMessage("The Human keyed in: "+ to_string(iXCoord) +" and "+ to_string(iYCoord), iMoveCounter);

                if(!GB.MarkBoard(pair<signed int, signed int>(iXCoord, iYCoord), H1.GetPlayable()))
                {
                    Log.LogError("The Human keyed in: "+ to_string(iXCoord) +" and "+ to_string(iYCoord), iMoveCounter);
                    cout << "This coordinate is already marked, pick a different position..." << endl; 
                }
                else
                {
                    bMarked = true;
                }                   
            }
            else
            {
                Log.LogError("The Human keyed in: "+ to_string(iXCoord) +" and "+ to_string(iYCoord), iMoveCounter);
                cout << "The x and y coordinates have to be between and including 0 and "+ to_string(DEFAULTGAMEBOARDSIZE - 1) << endl;
                cout << "Try again..." << endl; 
            }
        }

        pairCoords = CB.ComputeMove(GB.ShowGameBoard());

        if(pairCoords != pair<int, int>(-1, -1))
        {
             GB.MarkBoard(pairCoords, CB.GetPlayable());
            Log.LogMessage("The Computer played: "+ to_string(pairCoords.first)+ "," + to_string(pairCoords.second), iMoveCounter);
        }
    }
    
    cout << "Game Over!" << endl;
    sGameBoard = DG.DrawGameBoard(GB.ShowGameBoard());
    cout << "The Game Board:" << endl;
    cout << sGameBoard << endl;
    Log.LogMessage("\n"+sGameBoard, iMoveCounter); 
    Log.CloseLoggerFile();
    return 0;
}
