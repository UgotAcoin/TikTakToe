#include "TicTacToeGame.h"
#include <iostream>

using namespace std;

void TicTacToeGame::playGame()
{
	clearBoard();

	char player1 = 'X';
	char player2 = 'O';

	char currentPlayer = player1;
	bool isDone = false;

	int x, y;

	int turn = 0;

	while (isDone == false) {

		printBoard();

		x = getXCoord();
		y = getYCoord();

		if (playMarker(x, y, currentPlayer) == false) {
			cout << "That spot has been taken!\n";
		} else {
			turn++;
			if (checkForVictory(currentPlayer) == true) {
				cout << "THE GAME IS OVER! Player " << currentPlayer << " HAS WON!\n";
				isDone = true;
			} else if (turn == 9) {
				cout << "ITS A TIE GAME!\n";
				isDone = true;
			}

			//switch players
			if (currentPlayer == player1) {
				currentPlayer = player2;
			} else {
				currentPlayer = player1;
			}
		}


	}
	
	
	printBoard();


}




int TicTacToeGame::getXCoord()
{
	bool isInputBad = true;
	int x;
	
	while (isInputBad == true) {
		cout << "Enter the X coordinate: ";
		cin >> x;
		
		if (x < 1 || x > 3) {
			cout << "Invalid Coordinate!\n";
		}
		else {
			isInputBad = false;
		}
	}
	return x - 1;
}

int TicTacToeGame::getYCoord()
{
	bool isInputBad = true;

	int y;
	while (isInputBad == true) {
		cout << "Enter the Y coordinate: ";
		cin >> y;

		if (y < 1 || y > 3) {
			cout << "Invalid Coordinate!\n";
		}
		else {
			isInputBad = false;
		}
	}
	return y - 1;
}

bool TicTacToeGame::playMarker(int x, int y, char currentPlayer)
{
	if (board[y][x] != ' ') {
		return false;
	}

	board[y][x] = currentPlayer;
	return true;
}

bool TicTacToeGame::checkForVictory(char currentPlayer)
{
	//check the rows
	for (int i = 0; i < 3; i++) {
		if ((board[i][0] == currentPlayer) && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
			return true; //won
		}

	}
	for (int i = 0; i < 3; i++) {
		if ((board[0][i] == currentPlayer) && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
			return true; //won
		}

	}


	//check top left daiganal 
	if ((board[0][0] == currentPlayer) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
		return true; //won
	}

	//check top left daiganal 
	if ((board[2][0] == currentPlayer) && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2])) {
		return true; //won
	}

	return false;
}

void TicTacToeGame::clearBoard()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}




TicTacToeGame::TicTacToeGame()
{
	
}


void TicTacToeGame::printBoard()
{
	cout << endl;
	cout << "  | 1   2   3 |\n";
	for (int i = 0; i < 3; i++) {
		cout << "  ------------- \n";
		cout << i+1 << " | " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " | \n";

	}
	cout << "  ------------- \n";
}