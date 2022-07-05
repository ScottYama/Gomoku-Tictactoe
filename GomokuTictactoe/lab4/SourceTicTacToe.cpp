/*SourceTicTacToe.cpp: This file contains the constructor and method definitions for the TicTacToeGame class, a derived class of the Gamebase abstract class. 
* Contributors: Adam Schwartz, Jeremy Ouyang, Scott Yamamoto
*/
#include "lab4header.h"
#include "TicTacToeGame.h"
#include "GamePiece.h"
#include "GameBase.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
//Constructor Definition
TicTacToeGame::TicTacToeGame() {
	whoseTurn = true;
	numTurns = 0; 
	longestDisplay = 1;
	width = 5;
	height = 5;
	maxMoves = (width-2) * (height-2);
	
	for (int i = 0; i < width * height;++i) {
		gamePiece piece = gamePiece();
		gamePieces.push_back(piece);
	}
}
//Insertion operator overloading: This prints out the game board.
ostream& operator<<(ostream& o, const TicTacToeGame& t) {
	o << setw(t.longestDisplay);
	for (int row = t.height+1; row > 0; --row) {
		for (int col = 0; col < t.width+1; ++col) {
			//For printing Column numbers
			if (row == 1) {
				if (col == 0) {
					o << " ";
				}
				else {
					o << (col - 1);
				}
			}
			//for printing Row Numbers
			else if (col == 0) {
				if (row != 0) {
					o << (row - 2);
				}
			}
			//For printing Game Piece Display
			else {
				int idx = (row - 2) * t.width + col-1;
				o << t.gamePieces[idx].gamePieceDisplay;
			}
			
		}
		o << endl;
	}
	return o;
}

//Check if someone has won the game
bool TicTacToeGame:: done() {
	//check rows:
	for (int i = 1; i <= 3; ++i) {
		
		if (gamePieces[5*i+1].gamePieceDisplay!=" " &&(gamePieces[5 * i + 1].gamePieceDisplay == gamePieces[5 * i + 2].gamePieceDisplay && gamePieces[5 * i + 2].gamePieceDisplay==gamePieces[5 * i + 3].gamePieceDisplay)) {
			winner = gamePieces[5 * i + 1].gamePieceDisplay;
			return true;
		}
	}
	//check columns:
	for (int i = 1; i <= 3; ++i) {
		if (gamePieces[5 + i].gamePieceDisplay != " " && (gamePieces[10 + i].gamePieceDisplay == gamePieces[15 + i].gamePieceDisplay && gamePieces[15 + i].gamePieceDisplay == gamePieces[5 +i].gamePieceDisplay)) {
			winner = gamePieces[5 + i].gamePieceDisplay;
			return true;
		}
	}
	//check diagonals:
	if (gamePieces[8].gamePieceDisplay != " " && (gamePieces[12].gamePieceDisplay == gamePieces[16].gamePieceDisplay && gamePieces[16].gamePieceDisplay  == gamePieces[8].gamePieceDisplay)) {
		winner = gamePieces[8].gamePieceDisplay;
		return true;
	}
	if (gamePieces[6].gamePieceDisplay != " " && (gamePieces[6].gamePieceDisplay == gamePieces[12].gamePieceDisplay && gamePieces[12].gamePieceDisplay == gamePieces[18].gamePieceDisplay)) {
		winner = gamePieces[6].gamePieceDisplay;
		return true;
	}
	//if there are no three in a rows, return false:
	return false;
}
//Check if the Game ended in a draw
bool TicTacToeGame::draw(){
	if (done() || numTurns != maxMoves) {
		return false;
	}
	return true;
}


//This method codes for one turn of the game
int TicTacToeGame::turn() {
	string player = "";
	//Check whose turn it is with a member boolean variable
	if(whoseTurn){
		player = "X";
	}
	else {
		player = "O";
	}
	cout << "It's Player " << player << "'s turn" << endl;
	unsigned int row;
	unsigned int col;
	bool validMove = false;
	//Continuously prompt the user for input coordinates until a valid move is made.
	while (!validMove) {
		int succFail = prompt(col, row);
		if (succFail == userQuit) {
			return userQuit;
		}
		if (succFail == success) {
			int idx = row * width + col;
			//If the prompt is successful, check if there is a piece at the index. If there isn't add the piece there.
			if (gamePieces[idx].gamePieceName == "") {
				validMove = true;
				++numTurns;
				gamePieces[idx].gamePieceName = player;
				gamePieces[idx].gamePieceDisplay = player;
				//Print out the board
				cout << (*this) << endl;
				cout << endl;
				//Add the move to the correct player's moves vector. Then print the vector out.
				string move = to_string(col) + "," + to_string(row);
				cout << "Player " << player << "'s Moves:";
				if (player == "X") {
					p1Moves.push_back(move);
					for (unsigned int i = 0; i < p1Moves.size(); ++i) {
						cout << p1Moves[i] << "  ";
					}
				}
				else {
					p2Moves.push_back(move);
					for (unsigned int i = 0; i < p2Moves.size(); ++i) {
						cout << p2Moves[i] << "  ";
					}
				}
				
				cout << endl;
			}
		}
	}
	whoseTurn = !whoseTurn;
	return success;

}
void TicTacToeGame::print() {
	cout << *this << endl;
}
