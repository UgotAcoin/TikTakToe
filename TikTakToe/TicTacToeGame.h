#pragma once
class TicTacToeGame
{


public:
	
	
	TicTacToeGame();

	void playGame();


private:

	int getXCoord();
	int getYCoord();

	bool playMarker(int x, int y, char currentPlayer);

	bool checkForVictory(char currentPlayer);

	//empties the board
	void clearBoard();

	//prints the board
	void printBoard();

	char board[3][3];

};