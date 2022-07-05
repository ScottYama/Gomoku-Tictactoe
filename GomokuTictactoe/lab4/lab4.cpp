// lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Contributors: Jeremy Ouyang, Adam Schwartz, Scott Yamomoto
// This program makes a shared pointer to the GameBase class, which points to an object (either TicTacToe or Gomoku), and uses it to play that game. 
// Errors are thrown if incorrect arguments are used in the command line.
//

#include <iostream>
#include "lab4header.h"
#include "GameBase.h"
#include "TicTacToeGame.h"

int usageMessage(const string& a, const string& b) {
    cout << "There was incorrect input for the function into the terminal. Please enter either TicTacToe or Gomoku after the filename to play." << endl;
    cout << "Usage: " << a << " " << b << endl;
    return incorrectCommandLineArgs;
}

int main(int argc, char*argv[])
{
    GameBase* shared_ptr = GameBase::construct(argc, argv);
    if (shared_ptr == nullptr) {
        return usageMessage(argv[programName], "[TicTacToe or Gomoku]");
    }
    else {
        return shared_ptr->play();
    }

}
