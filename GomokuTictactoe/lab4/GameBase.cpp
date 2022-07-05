/* GameBase.cpp:  This file contains the constructor and method definitions for the GameBase class. 
* Contributors: Scott Yamamoto, Jeremy Ouyang, Adam Schwartz
*/

#include "GameBase.h"
#include "lab4header.h"
#include "TicTacToeGame.h"
#include "GomokuGame.h"
#include <iostream>
#include <sstream>
//This method helps take in user input from the command line
int GameBase::prompt(unsigned int& a, unsigned int& b) {
	bool valid = false;
	while (!valid) {
		cout << "Enter a valid coordinate or 'quit'. (Ex: 2,2)." << endl;
		string input = "";
		if (cin >> input) {
			if (input == "quit") {
				return userQuit;
			}
			//Replace the comma to make it easier to parse the input
			for (unsigned int i = 0; i < input.length(); ++i) {
				if (input[i] == ',') {
					input[i] = ' ';
				}
			}
			istringstream iss(input);
			int first;
			int second;
			//Parse the integers and check if they are valid coordinates
			if (iss >> first) {
				if (first >= validMin && first <= validMax) {
					a = first;
					if (iss >> second) {
						if (second >= validMin && second <= validMax) {
							b = second;
							valid = true;
						}
						else {
							cout << "Invalid Coordinate entered." << endl;
							return invalidCoordinate;
						}
					}
					else {
						cout << "Failed to Extract Value." << endl;
						return failureToExtractValue;
					}

				}
				else {
					cout << "Invalid Coordinate entered." << endl;
					return invalidCoordinate;
				}
			}
			else {
				cout << "Failed to Extract Value." << endl;
				return failureToExtractValue;
			}
		}
	}
	return success;
}

//This method uses the other methods written to play the game.
int GameBase::play() {
	print();
	//While the game hasn't finished, call turn() to play a turn
	while (!done()) {
		int turns = turn();
		//Check if the game is Done
		if (done()) {
			cout << "Player " << winner << " won the game!" << endl;
			return success;
		}
		//Check if the game is a Draw
		if (draw()) {
			cout << "There were " << numTurns << " moves played. No winning moves remain." << endl;
			return gameResultDraw;
		}
		//Check if the user quit
		if (turns == userQuit) {
			cout << numTurns << " turns were played. The user quit the game." << endl;
			return userQuit;
		}
	}
	return success;
}
// This construct method helps construct a new object of a GameBase derived class. 
GameBase* GameBase::construct(int argc, char* argv[]) {
	if (argc == numCommandLineArgs ) {
		string program = argv[programArg];
		if (program == "TicTacToe") {
			GameBase *game = new TicTacToeGame();
			(*game).validMin = 1; 
			(*game).validMax = 3;
			return game;
		}
		if (program == "Gomoku") {
			GameBase* game = new Gomoku();
			(*game).validMin = 1;
			(*game).validMax = 19;
			return game;

		}
	}
	return nullptr;
}
