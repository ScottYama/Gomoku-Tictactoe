/* GameBase.h: This header file contains the class declarations for GameBase. 
* Contributors: Adam Schwartz, Jeremy Ouyang, Scott Yamamoto
*/
#pragma once
#include <vector>
#include <string>
using namespace std;
#include "GamePiece.h"

class GameBase {
public:
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool draw() = 0;
	virtual int turn() = 0;
	int play();
	virtual int prompt(unsigned int& a, unsigned int& b);
	static GameBase* construct(int argc, char* argv[]);
protected:
	vector<gamePiece> gamePieces;
	vector<string> p1Moves;
	vector<string> p2Moves;
	int numTurns;
	int width;
	int height;
	int longestDisplay;
	int validMin;
	int validMax;
	bool whoseTurn;
	int maxMoves;
	string winner;
};