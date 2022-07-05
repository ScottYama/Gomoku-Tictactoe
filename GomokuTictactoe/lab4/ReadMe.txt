Adam Schwartz, Jeremy Ouyang, Scott Yamamoto
Lab 4
We all worked together on the lab by sitting down and thinking about the logic of each method as we coded. Jeremy helped out a lot on the draw() method, Scott helped a lot on part I and Adam helped write the done() method. Overall, we were able to divide the work evenly.

Errors:
	We struggled a bit on how to implement the draw method for this lab. At first, we tried to iterate through the array in a similar fashion as the done method,
	but we realized that there's a much simpler way to approach this method -- we can just fill up the array with each of the different pieces separately and 
	check if there is a win condition for either of the two cases. 

Enumerations: 
Important Array Indicies:
	0 - program name
	1 - program argument
	2 - number of command line arguments


Success/Failure:
	0 - success 
	1 - incorrect command line arguments
	2 - game result draw
	3 - invalid coordinate
	4 - user quit 
	5 - failure to extract value

Test Cases: 

1.	Bad input - when the user enters the wrong input into the terminal, they are greeted with a message letting them know to enter one of the two possible games to play after lab4.exe. The proper value is returned.

	H:\332 repos\lab4\lab4\x64\Debug>lab4.exe
	There was incorrect input for the function into the terminal. Please enter either TicTacToe or Gomoku after the filename to play.
	Usage: lab4.exe [TicTacToe or Gomoku]

	H:\332 repos\lab4\lab4\x64\Debug>echo %errorlevel%
	1


2.	Bad input - when the user enters the wrong input into the terminal, they are greeted with a message letting them know to enter one of the two possible games to play after lab4.exe. The proper value is returned.

	H:\332 repos\lab4\lab4\x64\Debug>lab4.exe CoolMathGames
	There was incorrect input for the function into the terminal. Please enter either TicTacToe or Gomoku after the filename to play.
	Usage: lab4.exe [TicTacToe or Gomoku]

	H:\332 repos\lab4\lab4\x64\Debug>echo %errorlevel%
	1


3.	TicTacToe (X wins diagonally) - when X wins diagonally, the done method recognizes the win condition and the game announces X as the winner.
	
	H:\332 repos\lab4\lab4\x64\Debug>lab4.exe TicTacToe
	4
	3
	2
	1
	0
	 01234

	It's Player X's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	2,2
	4
	3
	2  X
	1
	0
	 01234


	Player X's Moves:2,2
	It's Player O's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	1,3
	4
	3 O
	2  X
	1
	0
	 01234


	Player O's Moves:1,3
	It's Player X's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	1,1
	4
	3 O
	2  X
	1 X
	0
	 01234


	Player X's Moves:2,2  1,1
	It's Player O's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	2,3
	4
	3 OO
	2  X
	1 X
	0
	 01234


	Player O's Moves:1,3  2,3
	It's Player X's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	3,3
	4
	3 OOX
	2  X
	1 X
	0
	 01234


	Player X's Moves:2,2  1,1  3,3
	Player X won the game!

	H:\332 repos\lab4\lab4\x64\Debug>echo %errorlevel%
	0

	
4.	TicTacToe (O wins horizontally) - when O wins horizontally, the done method recognizes the win condition and the game announces O as the winner.

	It's Player X's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	1,2
	4
	3   X
	2 XX
	1 OO
	0
	 01234


	Player X's Moves:2,2  3,3  1,2
	It's Player O's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	3,1
	4
	3   X
	2 XX
	1 OOO
	0
	 01234


	Player O's Moves:1,1  2,1  3,1
	Player O won the game!

	H:\332 repos\lab4\lab4\x64\Debug>echo %errorlevel%
	0


5.	TicTacToe (X wins vertically) -  when X wins vertically, the done method recognizes the win condition and the game announces X as the winner.

	It's Player O's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	3,3
	4
	3   O
	2 XO
	1 X
	0
	 01234


	Player O's Moves:2,2  3,3
	It's Player X's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	1,3
	4
	3 X O
	2 XO
	1 X
	0
	 01234


	Player X's Moves:1,1  1,2  1,3
	Player X won the game!

	H:\332 repos\lab4\lab4\x64\Debug>echo %errorlevel%
	0


6.	TicTacToe (quit) - when the user enters 'quit' in the command line, the game ends with a quit message and the number of turns played is also printed.

	H:\332 repos\lab4\lab4\x64\Debug>lab4.exe TicTacToe
	4
	3
	2
	1
	0
	 01234

	It's Player X's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	1,3
	4
	3 X
	2
	1
	0
	 01234


	Player X's Moves:1,3
	It's Player O's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	2,2
	4
	3 X
	2  O
	1
	0
	 01234


	Player O's Moves:2,2
	It's Player X's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	quit
	2 turns were played. The user quit the game.

	H:\332 repos\lab4\lab4\x64\Debug>echo %errorlevel%
	4


7.	TicTacToe (draw) - when all the spaces on the board are filled, the program ends the game by printing out how many moves were played and that there are no winning moves that remain. 

	It's Player O's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	1,3
	4
	3 O X
	2 XXO
	1 OOX
	0
	 01234


	Player O's Moves:1,1  2,1  3,2  1,3
	It's Player X's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	2,3
	4
	3 OXX
	2 XXO
	1 OOX
	0
	 01234


	Player X's Moves:2,2  3,3  3,1  1,2  2,3
	There were 9 moves played. No winning moves remain.

	H:\332 repos\lab4\lab4\x64\Debug>echo %errorlevel%
	2


8.	TicTacToe (coordinate out of bounds) - when the user enters a coordinate that is out of the bounds of the board, the program will tell them an invalid coordinate was entered and will prompt the user for another coordinate or quit the game. 

	H:\332 repos\lab4\lab4\x64\Debug>lab4.exe TicTacToe
	4
	3
	2
	1
	0
	 01234

	It's Player X's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	4,2
	Invalid Coordinate entered.
	Enter a valid coordinate or 'quit'. (Ex: 2,2).


9.	TicTacToe (poorly formatted coordinate) - if the user enters a coordinate that is not in the specific X,Y format, the program will let them know that it could not extract the value and will prompt again.

	4
	3 X
	2
	1
	0
	 01234


	Player X's Moves:1,3
	It's Player O's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	1 3
	Failed to Extract Value.
	Enter a valid coordinate or 'quit'. (Ex: 2,2).


10.	Gomoku (Black wins horizontally) -  when B wins horizontally, the done method recognizes the win condition and the game announces Black Stone as the winner.

	H:\332 repos\lab4\lab4\x64\Debug>lab4.exe Gomoku
	 19
	 18
	 17
	 16
	 15
	 14
	 13
	 12
	 11
	 10
	  9
	  8
	  7
	  6
	  5
	  4
	  3
	  2
	  1
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

	It's Black Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	5,2
	 19
	 18
	 17
	 16
	 15
	 14
	 13
	 12
	 11
	 10
	  9
	  8
	  7
	  6
	  5
	  4
	  3
	  2              B
	  1
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19


	Player Black Stone's Moves:5,2
	It's White Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	7,12
	 19
	 18
	 17
	 16
	 15
	 14
	 13
	 12                    W
	 11
	 10
	  9
	  8
	  7
	  6
	  5
	  4
	  3
	  2              B
	  1
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19


	Player White Stone's Moves:7,12
	It's Black Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	6,2
	 19
	 18
	 17
	 16
	 15
	 14
	 13
	 12                    W
	 11
	 10
	  9
	  8
	  7
	  6
	  5
	  4
	  3
	  2              B  B
	  1
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19


	Player Black Stone's Moves:5,2  6,2
	It's White Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	18,10
	 19
	 18
	 17
	 16
	 15
	 14
	 13
	 12                    W
	 11
	 10                                                     W
	  9
	  8
	  7
	  6
	  5
	  4
	  3
	  2              B  B
	  1
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19


	Player White Stone's Moves:7,12  18,10
	It's Black Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	4,2
	 19
	 18
	 17
	 16
	 15
	 14
	 13
	 12                    W
	 11
	 10                                                     W
	  9
	  8
	  7
	  6
	  5
	  4
	  3
	  2           B  B  B
	  1
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19


	Player Black Stone's Moves:5,2  6,2  4,2
	It's White Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	12,1
	 19
	 18
	 17
	 16
	 15
	 14
	 13
	 12                    W
	 11
	 10                                                     W
	  9
	  8
	  7
	  6
	  5
	  4
	  3
	  2           B  B  B
	  1                                   W
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19


	Player White Stone's Moves:7,12  18,10  12,1
	It's Black Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	7,2
	 19
	 18
	 17
	 16
	 15
	 14
	 13
	 12                    W
	 11
	 10                                                     W
	  9
	  8
	  7
	  6
	  5
	  4
	  3
	  2           B  B  B  B
	  1                                   W
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19


	Player Black Stone's Moves:5,2  6,2  4,2  7,2
	It's White Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	1,17
	 19
	 18
	 17  W
	 16
	 15
	 14
	 13
	 12                    W
	 11
	 10                                                     W
	  9
	  8
	  7
	  6
	  5
	  4
	  3
	  2           B  B  B  B
	  1                                   W
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19


	Player White Stone's Moves:7,12  18,10  12,1  1,17
	It's Black Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	8,2
	 19
	 18
	 17  W
	 16
	 15
	 14
	 13
	 12                    W
	 11
	 10                                                     W
	  9
	  8
	  7
	  6
	  5
	  4
	  3
	  2           B  B  B  B  B
	  1                                   W
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19


	Player Black Stone's Moves:5,2  6,2  4,2  7,2  8,2
	Player Black Stone won the game!

	H:\332 repos\lab4\lab4\x64\Debug>echo %errorlevel%
	0


11.	Gomoku (White wins vertically) - when W wins vertically, the done method recognizes the win condition and the game announces White Stone as the winner.

	It's Black Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	9,4
	 19                 B
	 18
	 17
	 16
	 15
	 14
	 13
	 12
	 11
	 10
	  9
	  8
	  7                             W
	  6                             W
	  5                          B  W
	  4                          B  W
	  3                             B
	  2                                B
	  1
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19


	Player Black Stone's Moves:6,19  9,5  10,3  11,2  9,4
	It's White Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	10,8
	 19                 B
	 18
	 17
	 16
	 15
	 14
	 13
	 12
	 11
	 10
	  9
	  8                             W
	  7                             W
	  6                             W
	  5                          B  W
	  4                          B  W
	  3                             B
	  2                                B
	  1
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19


	Player White Stone's Moves:10,5  10,4  10,6  10,7  10,8
	Player White Stone won the game!

	H:\332 repos\lab4\lab4\x64\Debug>echo %errorlevel%
	0


12.	Gomoku (Black wins diagonally top right to bottom left) - when B wins diagonally top right to bottom left, the done method recognizes the win condition and the game announces Black Stone as the winner.

	It's White Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	14,14
	 19                                                     W  B
	 18                                                     B  W
	 17                                                  B     W
	 16                                               B
	 15
	 14                                         W
	 13
	 12
	 11
	 10
	  9
	  8
	  7
	  6
	  5
	  4
	  3
	  2
	  1
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19


	Player White Stone's Moves:19,18  19,17  18,19  14,14
	It's Black Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	15,15
	 19                                                     W  B
	 18                                                     B  W
	 17                                                  B     W
	 16                                               B
	 15                                            B
	 14                                         W
	 13
	 12
	 11
	 10
	  9
	  8
	  7
	  6
	  5
	  4
	  3
	  2
	  1
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19


	Player Black Stone's Moves:19,19  18,18  17,17  16,16  15,15
	Player Black Stone won the game!

	H:\332 repos\lab4\lab4\x64\Debug>echo %errorlevel%
	0


13.	Gomoku (Black wins diagonally top left to bottom right) - when Black wins diagonally, the done method recognizes the win condition and the game announces Black as the winner.

	It's White Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	15,12
	 19
	 18
	 17
	 16
	 15
	 14
	 13
	 12                                            W
	 11                                         B
	 10                                            B  W
	  9                                               B
	  8                                                  B
	  7
	  6
	  5
	  4
	  3
	  2                             W
	  1  W
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19


	Player White Stone's Moves:10,2  1,1  16,10  15,12
	It's Black Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	13,12
	 19
	 18
	 17
	 16
	 15
	 14
	 13
	 12                                      B     W
	 11                                         B
	 10                                            B  W
	  9                                               B
	  8                                                  B
	  7
	  6
	  5
	  4
	  3
	  2                             W
	  1  W
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19


	Player Black Stone's Moves:15,10  14,11  16,9  17,8  13,12
	Player Black Stone won the game!

	H:\332 repos\lab4\lab4\x64\Debug>echo %errorlevel%
	0


14.	Gomoku (quit) - when the user enters 'quit' during the game, the number of moves played are printed out and a quit message is printed. 

	It's White Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	10,4
	 19
	 18
	 17
	 16
	 15
	 14
	 13
	 12
	 11
	 10
	  9
	  8
	  7              W
	  6
	  5
	  4           B                 W
	  3                                                        B
	  2
	  1
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19


	Player White Stone's Moves:5,7  10,4
	It's Black Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	18,12
	 19
	 18
	 17
	 16
	 15
	 14
	 13
	 12                                                     B
	 11
	 10
	  9
	  8
	  7              W
	  6
	  5
	  4           B                 W
	  3                                                        B
	  2
	  1
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19


	Player Black Stone's Moves:4,4  19,3  18,12
	It's White Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	quit
	5 turns were played. The user quit the game.

	H:\332 repos\lab4\lab4\x64\Debug>echo %errorlevel%
	4

	The program returns the correctly enumerated value for the user quitting, and it prints out the correct statement, so the program performs correctly.

15.	Gomoku (coordinate out of bounds) - if the user enters a coordinate that is out of the bounds of the game board, the program lets them know that an invalid coordinate was entered and will prompt for a set of coordinates until a valid move is given.

	 19
	 18
	 17
	 16
	 15
	 14
	 13
	 12
	 11
	 10
	  9
	  8
	  7
	  6
	  5
	  4
	  3
	  2
	  1
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

	It's Black Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	20,5
	Invalid Coordinate entered.
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	0,15
	Invalid Coordinate entered.
	Enter a valid coordinate or 'quit'. (Ex: 2,2).

16.	Gomoku (poorly formatted coordinate) - if the user enters a poorly formatted coordinate, the program lets them know that a coordinate could not be extracted will prompt for a set of coordinates until a valid move is given.

	H:\332 repos\lab4\lab4\x64\Debug>lab4.exe Gomoku
	 19
	 18
	 17
	 16
	 15
	 14
	 13
	 12
	 11
	 10
	  9
	  8
	  7
	  6
	  5
	  4
	  3
	  2
	  1
	  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

	It's Black Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	2  6
	Failed to Extract Value.
	Enter a valid coordinate or 'quit'. (Ex: 2,2).


17.	Gomoku (draw) - if there are no more possible paths for B or W to win, prints how many moves were used returns the correctly enumerated value. 

	It's Black Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	19,14
		19  B  B  W  W  W  B  B  W  W  B  W  W  W  B  B  B  W  B
		18  W  W  B  B  B  W  W  B  B  W  B  B  B  W  W  W  B  W
		17  B  B  W  W  W  B  B  W  W  B  W  W  W  B  B  B  W  B
		16  W  W  B  B  B  W  W  B  B  W  B  B  B  W  W     B  W
		15  B  B  W  W  W  B  B  W  W  B  W  W  W  B  B  W  W  B
		14  W  W  B  B  B  W  W  B  B  W  B  B  B  W  W  B  B  W  B
		13  B  B  W  W  W  B  B  W  W  B  W  W  W  B  B  W  W  B  W
		12  W  W  B  B  B  W  W  B  B  W  B  B  B  W  W  B  B  W
		11  B  B  W  W  W  B  B  W  W  B     W  W  B  B  W  W  B
		10  W  W  B  B  B  W  W  B  B  W  W  B  B  W  W  B  B  W  B
		 9  B  B  W  W  W  B  B  W  W  B  B  W  W  B  B  W  W  B  W
		 8  W  W  B  B  B  W  W  B  B  W  W  B  B  W  W  B  B  W
		 7  B  B  W  W  W  B  B  W  W  B  B  W  W  B  B  W  W  B
		 6  W  W  B  B  B  W  W  B  B  W  W  B  B  W  W  B  B  W
		 5  B  B  W  W  W  B  B  W  W  B  B  W  W  B  B  W  W  B  B
		 4  W  W  B  B  B  W  W  B  B  W  W  B  B  W  W  B  B  W  W
		 3  B  B  W  W  W  B  B  W  W  B  B  W  W  B  B  W  W  B
		 2  W  W  B  B  B  W  W  B  B  W  W  B  B  W  W  B  B  W
		 1  B  B  W  W  W  B  B  W  W  B  B     W  B  B  W  W  B
		 X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19


	Player Black Stone's Moves:1,1  1,3  1,5  1,7  1,9  1,11  1,13  1,15  1,17  1,19  2,3  2,5  2,7  2,9  2,11  2,13  2,15  2,17  2,19  3,2  3,4  3,6  3,8  3,10  3,12  3,14  3,16  3,18  2,1  4,2  4,4  4,6  4,8  4,10  4,12  4,14  4,16  4,18  5,2  5,4  5,6  5,8  5,10  6,1  5,12  5,14  5,16  5,18  6,3  6,5  6,7  6,9  6,11  6,13  6,15  6,17  6,19  7,1  7,3  7,5  7,7  7,9  7,11  7,13  7,15  7,17  7,19  8,2  8,4  8,6  8,8  8,10  8,12  8,14  8,16  8,18  9,2  9,4  9,6  9,8  9,10  9,12  9,14  9,16  9,18  10,1  10,3  10,5  10,7  10,9  10,11  10,13  10,15  10,17  10,19  11,1  11,3  11,5  11,7  11,9  11,12  11,14  11,16  11,18  12,2  12,4  12,6  12,8  12,10  12,12  12,14  12,16  12,18  13,2  13,4  13,6  13,8  13,10  13,12  13,14  13,16  13,18  14,1  14,3  14,5  14,7  14,9  14,11  14,13  14,15  14,17  14,19  15,1  15,3  15,5  15,7  15,9  15,11  15,13  15,15  15,17  15,19  16,2  16,4  16,6  16,8  16,10  16,12  16,14  16,17  16,19  17,2  17,4  17,6  17,8  17,10  17,12  17,14  17,16  17,18  18,1  18,3  18,5  18,7  18,9  18,11  18,13  18,15  18,17  18,19  19,5  19,10  19,14
	It's White Stone's turn
	Enter a valid coordinate or 'quit'. (Ex: 2,2).
	19,18
		19  B  B  W  W  W  B  B  W  W  B  W  W  W  B  B  B  W  B
		18  W  W  B  B  B  W  W  B  B  W  B  B  B  W  W  W  B  W  W
		17  B  B  W  W  W  B  B  W  W  B  W  W  W  B  B  B  W  B
		16  W  W  B  B  B  W  W  B  B  W  B  B  B  W  W     B  W
		15  B  B  W  W  W  B  B  W  W  B  W  W  W  B  B  W  W  B
		14  W  W  B  B  B  W  W  B  B  W  B  B  B  W  W  B  B  W  B
		13  B  B  W  W  W  B  B  W  W  B  W  W  W  B  B  W  W  B  W
		12  W  W  B  B  B  W  W  B  B  W  B  B  B  W  W  B  B  W
		11  B  B  W  W  W  B  B  W  W  B     W  W  B  B  W  W  B
		10  W  W  B  B  B  W  W  B  B  W  W  B  B  W  W  B  B  W  B
		 9  B  B  W  W  W  B  B  W  W  B  B  W  W  B  B  W  W  B  W
		 8  W  W  B  B  B  W  W  B  B  W  W  B  B  W  W  B  B  W
		 7  B  B  W  W  W  B  B  W  W  B  B  W  W  B  B  W  W  B
		 6  W  W  B  B  B  W  W  B  B  W  W  B  B  W  W  B  B  W
		 5  B  B  W  W  W  B  B  W  W  B  B  W  W  B  B  W  W  B  B
		 4  W  W  B  B  B  W  W  B  B  W  W  B  B  W  W  B  B  W  W
		 3  B  B  W  W  W  B  B  W  W  B  B  W  W  B  B  W  W  B
		 2  W  W  B  B  B  W  W  B  B  W  W  B  B  W  W  B  B  W
		 1  B  B  W  W  W  B  B  W  W  B  B     W  B  B  W  W  B
		 X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19


	Player White Stone's Moves:1,2  1,4  1,6  1,8  1,10  1,12  1,14  1,16  1,18  2,2  2,4  2,6  2,8  2,10  2,12  2,14  2,16  2,18  3,1  3,3  3,5  3,7  3,9  3,11  3,13  3,15  3,17  3,19  4,1  4,3  4,5  4,7  4,9  4,11  4,13  4,15  4,17  4,19  5,3  5,5  5,7  5,9  5,1  5,11  5,13  5,15  5,17  5,19  6,4  6,6  6,8  6,10  6,12  6,14  6,16  6,18  6,2  7,2  7,4  7,6  7,8  7,10  7,12  7,14  7,16  7,18  8,1  8,3  8,5  8,7  8,9  8,11  8,13  8,15  8,17  8,19  9,3  9,5  9,7  9,9  9,11  9,13  9,15  9,17  9,19  10,2  10,4  10,6  10,8  10,10  10,12  10,14  10,16  10,18  9,1  11,2  11,4  11,6  11,8  11,10  11,13  11,15  11,17  11,19  12,3  12,5  12,7  12,9  12,11  12,13  12,15  12,17  12,19  13,3  13,5  13,7  13,9  13,11  13,13  13,15  13,17  13,19  14,2  14,4  14,6  14,8  14,10  14,12  14,14  14,16  14,18  13,1  15,2  15,4  15,6  15,8  15,10  15,12  15,14  15,16  15,18  16,1  16,3  16,5  16,7  16,9  16,11  16,13  16,15  16,18  17,1  17,3  17,5  17,7  17,9  17,11  17,13  17,15  17,17  17,19  18,2  18,4  18,6  18,8  18,10  18,12  18,14  18,16  18,18  19,4  19,9  19,13  19,18
	There were 346 moves played. No winning moves remain.

	H:\332 repos\lab4\lab4\x64\Debug>echo %errorlevel%
	2

	