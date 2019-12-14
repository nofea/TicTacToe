#include <iostream>
#include "Commons.hpp"
#include "GameBoard.hpp"
#include "Logger.hpp"
#include "ComputerBlocker.hpp"
#include "Human.hpp"
#include "DrawGrid.hpp"


using namespace std;

int main()
{   
    string sPlayable("");
    Human H1;
    ComputerBlocker CB;
    Logger Log;

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

        if(sPlayable == "x" || sPlayable == "X")
        {
            H1.SetPlayable(Playable_X);
            CB.SetPlayable(Playable_O);
            break;
        }
        else if(sPlayable == "o" || sPlayable == "O")
        {
            H1.SetPlayable(Playable_O);
            CB.SetPlayable(Playable_X);
            break;
        }
        else
        {
            cout << "Bruh, pick X or O..." << endl;
            Log.LogError("The Human is being daft!!!");
        }
    }
    
    Log.LogMessage("The Human chose: "+ to_string(H1.GetPlayable()));
    Log.LogMessage("The Computer was given: "+ to_string(CB.GetPlayable()));

    GameBoard GB(DEFAULTGAMEBOARDSIZE);
    Log.LogMessage("Game Board Initialized with size: "+ to_string(DEFAULTGAMEBOARDSIZE));
    
    cout << "X goes first" << endl;

    while (!GB.IsEndOfGame())
    {
        
    }
    
    
    Log.CloseLoggerFile();
    return 0;
}
