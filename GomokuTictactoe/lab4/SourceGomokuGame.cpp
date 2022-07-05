/*SourceGomokuGame.cpp: This source file contains the definitions for the Gomoku class methods. 
* Contributors: Adam Schwartz, Jeremy Ouyang, Scott Yamamoto
*/
#include "GomokuGame.h"
#include "lab4header.h"
#include <iostream>
#include <iomanip>

// Gomoku Constructor
Gomoku::Gomoku() {
	width = 19;
	height = 19;
	numTurns = 0;
	longestDisplay = 3;
	whoseTurn = true;
	maxMoves = width * height;
	for (int i = 0; i < width * height; ++i) {
		gamePiece piece = gamePiece();
		gamePieces.push_back(piece);
		
	}
}
// Insertion Operator Overloading
ostream& operator<< (ostream& o, const Gomoku& g) {
	for (int row = g.height + 1; row > 0; --row) { 
		for (int col = 0; col < g.width + 1; ++col) {
			//set width
			o << setw(g.longestDisplay);
			//For printing Column numbers
			if (row == 1) {
				if (col == 0) {
					o << "X";
				}
				else {
					o << col;
				}
			}
			//for printing Row Numbers
			else if (col == 0) {
				if (row != 0) {
					o << (row - 1);
				}
			}
			//For printing Game Piece Display
			else {
				int idx = (row - 2) * g.width + col - 1;
				o << g.gamePieces[idx].gamePieceDisplay;
			}

		}
		o << endl;
	}
	return o;
}
//Print Board Status
void Gomoku::print() {
	cout << *this << endl;
}

//This method checks if a player has won the game
bool Gomoku::done() {
	//check column
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height - 4; ++j) {
			if (gamePieces[j * width + i].gamePieceDisplay != " " && gamePieces[j * width + i].gamePieceDisplay == gamePieces[(j + 1) * width + i].gamePieceDisplay && gamePieces[j * width + i].gamePieceDisplay == gamePieces[(j + 2) * width + i].gamePieceDisplay && gamePieces[j * width + i].gamePieceDisplay == gamePieces[(j + 3) * width + i].gamePieceDisplay && gamePieces[j * width + i].gamePieceDisplay == gamePieces[(j + 4) * width + i].gamePieceDisplay) {
				winner = gamePieces[j * width + i].gamePieceName;
				return true;
			}
		}
	}

	//check rows:
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width - 4; ++j) {
			if (gamePieces[i * width + j].gamePieceDisplay != " " && gamePieces[i * width + j].gamePieceDisplay == gamePieces[i * width + j + 1].gamePieceDisplay && gamePieces[i * width + j].gamePieceDisplay == gamePieces[i * width + j + 2].gamePieceDisplay && gamePieces[i * width + j].gamePieceDisplay == gamePieces[i * width + j + 3].gamePieceDisplay && gamePieces[i * width + j].gamePieceDisplay == gamePieces[i * width + j + 4].gamePieceDisplay) {
				winner = gamePieces[i * width + j].gamePieceName;
				return true;
			}
		}
	}


	//Top left to bottom right diagonals. For the diagonals, we chose to iterate down the diagonals in two ways. We start in the top left corner,
	//and iterate down the row first (the first block of code), and then iterating down the column (the second block of code) to exhaust all the possible
	//diagonal win conditions. 
	int col = 0;
	while (col < width - 4) {
		int row = height - 1;
		int tempCol = col;
		while (row > 3 && tempCol < width - 4) {
			if (gamePieces[row * width + tempCol].gamePieceDisplay != " " && gamePieces[row * width + tempCol].gamePieceDisplay == gamePieces[(row - 1) * width + tempCol + 1].gamePieceDisplay && gamePieces[row * width + tempCol].gamePieceDisplay == gamePieces[(row - 2) * width + tempCol + 2].gamePieceDisplay && gamePieces[row * width + tempCol].gamePieceDisplay == gamePieces[(row - 3) * width + tempCol + 3].gamePieceDisplay && gamePieces[row * width + tempCol].gamePieceDisplay == gamePieces[(row - 4) * width + tempCol + 4].gamePieceDisplay) {
				winner = gamePieces[row * width + tempCol].gamePieceName;
				return true;
			}
			--row;
			++tempCol;
		}
		++col;
	}

	int row = height - 1;
	while (row > 3) {
		col = 0;
		int tempRow = row;
		while (col < width - 4 && tempRow > 3) {
			if (gamePieces[tempRow * width + col].gamePieceDisplay != " " && gamePieces[tempRow * width + col].gamePieceDisplay == gamePieces[(tempRow - 1) * width + col + 1].gamePieceDisplay && gamePieces[tempRow * width + col].gamePieceDisplay == gamePieces[(tempRow - 2) * width + col + 2].gamePieceDisplay && gamePieces[tempRow * width + col].gamePieceDisplay == gamePieces[(tempRow - 3) * width + col + 3].gamePieceDisplay && gamePieces[tempRow * width + col].gamePieceDisplay == gamePieces[(tempRow - 4) * width + col + 4].gamePieceDisplay) {
				winner = gamePieces[tempRow * width + col].gamePieceName;
				return true;
			}
			++col;
			--tempRow;
		}
		--row;
	}

	//top right to bottom left. Similar to the top left to bottom right, we split the array into two sections to iterate through all of the possible win conditions.
	col = width - 1; 
	while (col > 3) {
		row = height - 1;
		int tempCol = col;
		while (row > 3 && tempCol > 3) {
			if (gamePieces[row * width + tempCol].gamePieceDisplay != " " && gamePieces[row * width + tempCol].gamePieceDisplay == gamePieces[(row - 1) * width + tempCol - 1].gamePieceDisplay && gamePieces[row * width + tempCol].gamePieceDisplay == gamePieces[(row - 2) * width + tempCol - 2].gamePieceDisplay && gamePieces[row * width + tempCol].gamePieceDisplay == gamePieces[(row - 3) * width + tempCol - 3].gamePieceDisplay && gamePieces[row * width + tempCol].gamePieceDisplay == gamePieces[(row - 4) * width + tempCol - 4].gamePieceDisplay) {
				winner = gamePieces[row * width + tempCol].gamePieceName;
				return true;
			}
			--row;
			--tempCol;
		}
		--col;
	}

	row = height - 1;
	while (row > 3) {
		col = width - 1;
		int tempRow = row; 
		while (tempRow > 3) {
			if (gamePieces[tempRow * width + col].gamePieceDisplay != " " && gamePieces[tempRow * width + col].gamePieceDisplay == gamePieces[(tempRow - 1) * width + col - 1].gamePieceDisplay && gamePieces[tempRow * width + col].gamePieceDisplay == gamePieces[(tempRow - 2) * width + col - 2].gamePieceDisplay && gamePieces[tempRow * width + col].gamePieceDisplay == gamePieces[(tempRow - 3) * width + col - 3].gamePieceDisplay && gamePieces[tempRow * width + col].gamePieceDisplay == gamePieces[(tempRow - 4) * width + col - 4].gamePieceDisplay) {
				winner = gamePieces[tempRow * width + col].gamePieceName;
				return true;
			}
			--tempRow;
			--col;
		}
		--row;
	}
	return false;
}
//This method checks to see if there are any paths to victory left for either player. We do this by storing our current gamePiece array in a temporary array,
//filling out the rest of the array with the piece we are checking, and then checking if it can win. 
bool Gomoku::draw() {
	if (done()){
		return false;
	}

	//fill all blank spaces with "B" to see if any paths remain for Black
	vector<gamePiece> temp;
	for (unsigned int i = 0; i < gamePieces.size(); ++i) {
		temp.push_back(gamePieces[i]);
		if (gamePieces[i].gamePieceDisplay == " ") {
			gamePieces[i].gamePieceDisplay = "B";
		}
	}
	if (done()) {
		for (unsigned int i = 0; i < gamePieces.size(); ++i) {
			gamePieces[i] = temp[i];
		}
		return false;
	}

	//fill all blank spaces with "W" to see if any paths remain for White
	vector<gamePiece> temp2;
	for (unsigned int i = 0; i < gamePieces.size(); ++i) {
		temp2.push_back(gamePieces[i]);
		if (gamePieces[i].gamePieceDisplay == " ") {
			gamePieces[i].gamePieceDisplay = "W";
		}
	}
	if (done()) {
		for (unsigned int i = 0; i < gamePieces.size(); ++i) {
			gamePieces[i] = temp2[i];
		}
		return false;
	}

	return true;
}

//This method codes for one turn of the game
int Gomoku::turn() {
	string player = "";
	//Check whose turn it is with a member boolean variable
	if (whoseTurn) {
		player = "Black Stone";
	}
	else {
		player = "White Stone";
	}
	cout << "It's " << player << "'s turn" << endl;
	unsigned int row;
	unsigned int col;
	bool validMove = false;
	//Continuously prompt the user for input coordinates until a valid move is made.
	while (!validMove) {
		int succFail = prompt(col, row);
		--col;
		--row;
		if (succFail == userQuit) {
			return userQuit;
		}
		if (succFail == success) {
			int idx = row * width + col;
			//If the prompt is successful, check if there is a piece at the index. If there isn't add the piece there.
			if (gamePieces[idx].gamePieceName == "") {
				validMove = true;
				++numTurns;

				if (player == "Black Stone") {
					gamePieces[idx].gamePieceDisplay = "B";
				}
				else {
					gamePieces[idx].gamePieceDisplay = "W";
				}
				gamePieces[idx].gamePieceName = player;

				//Print out the board
				cout << (*this) << endl;
				cout << endl;
				//Add the move to the correct player's moves vector. Then print the vector out.
				string move = to_string(++col)  + "," + to_string(++row);
				cout << "Player " << player << "'s Moves:";
				if (player == "Black Stone") {
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