#include <iostream>
#include <iomanip>
#include "ticTacToe.h"

using namespace std;

void ticTacToe::initialize()
{
	char selection;
	bool validSelection;

	cout << "Welcome to Tic-Tac-Toe a game of Logic" << endl;
	do //Prompt the user and check for valid input
	{
		cout << "Player X is (H)uman or (C)omputer: ";
		cin >> selection;
		switch (selection)
		{
		case 'H':
		case 'h':
			npcOn = false;
			validSelection = true;
			break;
		case 'C':
		case 'c':
			npcOn = true;
			validSelection = true;
			break;
		default:
			cout << "ERROR: Invalid Selection!" << endl;
			validSelection = false;
		}
	} while (!validSelection);

	do //Prompt the user and check for valid input
	{
		cout << "Who plays first X or O?: ";
		cin >> selection;
		switch (selection)
		{
		case 'X':
		case 'x':
			nextMove = toupper(selection);
			validSelection = true;
			break;
		case 'O':
		case 'o':
			nextMove = toupper(selection);
			validSelection = true;
			break;
		default:
			cout << "ERROR: Invalid Selection!" << endl;
			validSelection = false;
		}
	} while (!validSelection);

	//Initialize the board placemarkers to a blank space
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			boardPos[i][j] = ' ';
}

void ticTacToe::play()
{
	displayBoard();
	cout << endl; //Line Break

	while (!getXOMove(nextMove));

	cout << endl; //Line Break

	switch (gameStatus())
	{
	case WINNER_X:
		cout << "Player X wins!" << endl;
		break;
	case WINNER_O:
		cout << "Player O wins!" << endl;
		break;
	case DRAW:
		cout << "Cat's game!" << endl;
	}
}

void ticTacToe::displayBoard() const
{
	int counter = 0;

	cout << setfill(' ');
	cout << right << setw(4) << "1"
		<< right << setw(5) << "2"
		<< right << setw(5) << "3" << endl;

	cout << endl; //Line Break

	//Draw the board
	for (int i = 0; i < 5; i++)
	{
		if (i == 0 || i == 2 || i == 4)
		{
			cout << (i == 0 ? i + 1 : i == 2 ? i : i - 1)
				<< right << setw(3) << boardPos[counter][0]
				<< right << setw(2) << "|"
				<< right << setw(3) << boardPos[counter][1]
				<< right << setw(2) << "|"
				<< right << setw(3) << boardPos[counter][2]
				<< endl;

			counter++;
		}
		else
		{
			cout << right << setw(1) << "" << "____|____|____" << endl;
			cout << right << setw(6) << "|"
				<< right << setw(5) << "|" << endl;
		}
	}
}

bool ticTacToe::isValidMove(int x, int y) const
{
	x--; y--;

	if (cin)
	{
		if ((x >= 0 && x <= 2) && (y >= 0 && y <= 2))
		{
			if (boardPos[x][y] == ' ')
				return true;
			else
				return false;
		}
	}
	else
	{
		cin.clear();
		cin.ignore(100, '\n');
	}
	return false;
}

bool ticTacToe::getXOMove(char moveSymbol)
{
	int row, col;

	cout << "Player " << moveSymbol << " enter move (row col): ";
	if (moveSymbol == 'X' && npcOn)
	{
		npcLogic();	//Non-player character play
	}
	else
	{
		do
		{
			cin >> row >> col;
			if (isValidMove(row, col))
			{
				boardPos[row - 1][col - 1] = (moveSymbol == 'X') ? 'X' : 'O';
				break;
			}
			else
			{
				cout << "Invalid move, please try again." << endl
					<< "Plater " << moveSymbol << " enter move (row col): ";
			}
		} while (!isValidMove(row, col));
	}
	swapTurn(moveSymbol);	//Change who goes next
	displayBoard();			//Display refreshed board

	//Save the last move to a variable
	if (moveSymbol == 'O')
	{
		lastORow = row - 1;
		lastOCol = col - 1;
	}

	if (gameStatus() == KEEP_PLAYING)
		return false;
	else
		return true;
}

status ticTacToe::gameStatus()
{
	for (int i = 0; i < 3; i++)
	{
		//Check for row win
		if (boardPos[i][0] == 'X' && boardPos[i][1] == 'X'
			&& boardPos[i][2] == 'X')
			return WINNER_X;
		else if (boardPos[i][0] == 'O' && boardPos[i][1] == 'O'
			&& boardPos[i][2] == 'O')
			return WINNER_O;
		//Check for column win
		else if (boardPos[0][i] == 'X' && boardPos[1][i] == 'X'
			&& boardPos[2][i] == 'X')
			return WINNER_X;
		else if (boardPos[0][i] == 'O' && boardPos[1][i] == 'O'
			&& boardPos[2][i] == 'O')
			return WINNER_O;
	}

	//Check for diagonal win
	if (boardPos[0][0] == 'X' && boardPos[1][1] == 'X'
		&& boardPos[2][2] == 'X')
		return WINNER_X;
	else if (boardPos[0][0] == 'O' && boardPos[1][1] == 'O'
		&& boardPos[2][2] == 'O')
		return WINNER_O;
	else if (boardPos[0][2] == 'X' && boardPos[1][1] == 'X'
		&& boardPos[2][0] == 'X')
		return WINNER_X;
	else if (boardPos[0][2] == 'O' && boardPos[1][1] == 'O'
		&& boardPos[2][0] == 'O')
		return WINNER_O;

	//Check to see if the board is full (draw)
	int markersPlaced = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (boardPos[i][j] != ' ')
				markersPlaced++;
		}
	}
	if (markersPlaced == 9)
		return DRAW;

	return KEEP_PLAYING;
}

void ticTacToe::npcLogic()
{
	if (!npcOn)
		return;
	
	//First and second NPC move
	if (boardPos[1][1] == ' ')
	{
		boardPos[1][1] = 'X';
		cout << "2 2" << endl;
		return;
	}
	else if (boardPos[0][0] == ' ')
	{
		boardPos[0][0] = 'X';
		cout << "1 1" << endl;
		return;
	}
	else if (boardPos[0][2] == ' ')
	{
		boardPos[0][2] = 'X';
		cout << "1 3" << endl;
		return;
	}

	//Check before and after the last row used by O
	for (int i = lastORow - 1; i <= lastORow + 1; i++)
	{
		//Check before and after the last column used by O
		for (int j = lastOCol - 1; j <= lastOCol + 1; j++)
		{
			//Make sure we stay inbounds of the array
			if ((i >= 0 && i < 3) && (j >= 0 && j < 3))
			{
				if (boardPos[i][j] == ' ')
				{
					boardPos[i][j] = 'X';
					cout << i + 1 << " " << j + 1 << endl;
					return;
				}
				else
				{
					//If a move near the last O position is not open
					//Move to the next open position
					for (int x = 0; x < 3; x++)
					{
						for (int z = 0; z < 3; z++)
						{
							if (boardPos[x][z] == ' ')
							{
								boardPos[x][z] = 'X';
								cout << x + 1 << " " << z + 1 << endl;
								return;
							}
						}
					}
				}
			}
		}
	}
}

void ticTacToe::swapTurn(char moveSymbol)
{
	if (moveSymbol == 'X')
		nextMove = 'O';
	else
		nextMove = 'X';
}

ticTacToe::ticTacToe()
{
	cout << "Anthony Cantu, ticTacToe.h - L4-2" << endl;
	initialize();
}