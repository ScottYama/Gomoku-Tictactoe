/*TicTacToeGame.h: This header file is for the TicTacToeGame class. It's constructor, methods, and member variables
* are declared here. 
* Contributors: Jeremy Ouyang, Adam Schwartz, Scott Yamamoto
*/
#pragma once

#include <iostream>
#include <vector>
#include "GamePiece.h"
#include <string>
#include "GameBase.h"
using namespace std;

class TicTacToeGame: public GameBase{
	//Friend Declaration
	friend ostream& operator<<(ostream& o, const TicTacToeGame& t);
public:
	//Constructor
	TicTacToeGame();
	//Methods
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	virtual void print() override;
};
//Operator Overloading
ostream& operator<<(ostream& o, const TicTacToeGame& t);

