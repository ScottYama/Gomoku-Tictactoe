/*lab4header.h: This header file contains enumerations for important Array Indicies and Success and Failure, as well as the declaration for the usage function.
Contributors: Jeremy Ouyang, Adam Schwartz, Scott Yamamoto
*/
#pragma once
#include <string>
using namespace std;
enum importantArrayIndicies {
	programName = 0,
	programArg = 1,
	numCommandLineArgs = 2
};

enum successFailure {
	success = 0,
	incorrectCommandLineArgs = 1,
	gameResultDraw = 2,
	invalidCoordinate = 3,
	userQuit = 4,
	failureToExtractValue = 5
};

int usageMessage(const string& a, const string& b);