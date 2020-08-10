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
    pair<int, int> pairCoords = pair<int,int>(-1,-1);
    signed int iRetry = 0;

    try
    {
        Log.OpenLoggerFile(LOGGERPATHNAME);
    }
    catch(const exception& e)
    {
        cerr << e.what() << endl;
    }
    
    cout << "Welcome to a game of Tic Tac Toe" << endl;

    while (1) //change this!!!
    {
        cout << "Do you want to be X's or O's?" << endl;
        cin >> sPlayable;

        try
        {
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
        catch(const std::exception& e)
        {
            cerr << e.what() << endl;
            Log.LogError(e.what(), iMoveCounter);
        }
    }
    
    Log.LogMessage("The Human chose: "+ to_string(H1.GetPlayable()), iMoveCounter);
    Log.LogMessage("The Computer was given: "+ to_string(CB.GetPlayable()), iMoveCounter);

    GameBoard GB(DEFAULTGAMEBOARDSIZE);
    Log.LogMessage("Game Board Initialized with size: "+ to_string(DEFAULTGAMEBOARDSIZE), iMoveCounter);

    sGameBoard = DG.DrawGameBoard(GB.ShowGameBoard());
    cout << "The Game Board:" << endl;
    cout << sGameBoard << endl;
    Log.LogMessage("\n"+sGameBoard, iMoveCounter);
    
    cout << "X goes first" << endl;
    iMoveCounter++;  

    if(CB.GetPlayable() == Playable_X)
    {
        try
        {
            while(!GB.MarkBoard(pairCoords, CB.GetPlayable()) && (++iRetry < 3))
            {
                pairCoords = CB.ComputeMove(GB.ShowGameBoard());
            }
            iRetry = 0;
            Log.LogMessage("The Computer played: "+ to_string(pairCoords.first)+ ", " + to_string(pairCoords.second), iMoveCounter);
              
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
        
        cout << "Key in x y Coordinates" << endl;

        while(!bMarked)
        {
            cin >> iXCoord >> iYCoord;

            if(iXCoord < DEFAULTGAMEBOARDSIZE && iYCoord < DEFAULTGAMEBOARDSIZE)
            {
                Log.LogMessage("The Human keyed in: "+ to_string(iXCoord) +", "+ to_string(iYCoord), iMoveCounter);

                try
                {
                    if(!GB.MarkBoard(pair<signed int, signed int>(iXCoord, iYCoord), H1.GetPlayable()))
                    {
                        Log.LogError("The Human keyed in: "+ to_string(iXCoord) +", "+ to_string(iYCoord), iMoveCounter);
                        cout << "This coordinate is already marked, pick a different position..." << endl; 
                    }
                    else
                    {
                        bMarked = true;
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
                Log.LogError("The Human keyed in: "+ to_string(iXCoord) +", "+ to_string(iYCoord), iMoveCounter);
                cout << "The x and y coordinates have to be between and including 0 and "+ to_string(DEFAULTGAMEBOARDSIZE - 1) << endl;
                cout << "Try again..." << endl; 
            }
        }

        try
        {
            while(!GB.MarkBoard(pairCoords, CB.GetPlayable()) && (++iRetry < 3))
            {
                pairCoords = CB.ComputeMove(GB.ShowGameBoard());
            }
            iRetry = 0;
            
            Log.LogMessage("The Computer played: "+ to_string(pairCoords.first)+ ", " + to_string(pairCoords.second), iMoveCounter);    
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
    cout << "Game Over!" << endl;
    Log.LogMessage("Game Over!");
    sGameBoard = DG.DrawGameBoard(GB.ShowGameBoard());
    cout << "The Game Board:" << endl;
    cout << sGameBoard << endl;
    Log.LogMessage("\n"+sGameBoard, iMoveCounter); 

    // wait for user input
    cin.get(); // safety workaround
    cin.get(); 

    Log.CloseLoggerFile();
    return 0;
}
