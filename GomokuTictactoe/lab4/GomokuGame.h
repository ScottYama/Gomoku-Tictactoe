/*GomokuGame.h: This header file contains the class declarations for the Gomoku Game class, which extends GameBase.
* Contributors: Jeremy Ouyang, Adam Schwartz, Scott Yamamoto
*/
#pragma once
#include "GameBase.h"
class Gomoku : public GameBase {
	friend ostream& operator<<(ostream& o, const Gomoku& g);
public:
	Gomoku();
	virtual void print() override;
	virtual bool done();
	virtual bool draw();
	virtual int turn();
};