#pragma once

enum status { WINNER_X, WINNER_O, DRAW, KEEP_PLAYING };

class ticTacToe
{
public:
	void play();
	//Function to start the game.
	//Precondition:	initialize() must be ran first.
	//Postcondition: Function will start the game.
	//				 Running displayBoard() and looping 
	//				 getOXMove() until no more moves are
	//				 left. Once the loop ends, the program will
	//				 check if there is a winner.

	ticTacToe();
	//Default constructor.
	//The game is initialized.
	//Precondition: No preconditions.
	//Postcondition: initialize() is ran and the game is initialized.

private:
	char boardPos[3][3];	//Variable array to store the play positions on the board
	bool npcOn;				//Boolean to store if the computer or human is playing
	char nextMove;			//Variable to store whos turn is next (X or O)
	int lastORow;			//Variable to store the last row used by player O
	int lastOCol;			//Variable to store the last column used by player O

	void initialize();
	//Function to initialize the game.
	//Precondition:	No preconditions, function is ran
	//				by default as the class is defined
	//				to intitialize the game.
	//Postcondition: The function starts the game. Prompting
	//				 the user to pick if they want to play
	//				 against the computer or another user.
	//				 Then prompts the user to pick who goes
	//				 first. Initializes the palceholders to blank.

	void displayBoard() const;
	//Function to display the board
	//Precondition:	initialize() and play() must be ran before
	//				using.
	//Postcondition: Fucntion will update and print the board 
	//				 with any new moves made.

	bool isValidMove(int x, int y) const;
	//Function to check if the move made is valid.
	//Precondition: Function paremeters must be received by
	//				user input to check if the move is valid.
	//				initialize() and play() must be ran before
	//				using.
	//Postcondition: Function will return a boolean value dependent
	//				 on if the move made by the user is valid.

	bool getXOMove(char moveSymbol);
	//Function will prompt the user to make a play.
	//Precondition:	initialize() and play() must be ran before using.
	//Postcondition: Function will prompt the user to make a play.
	//				 If the computer is activated for the second player,
	//				 the program will run npcLogic() to make a move.
	//				 Returns a boolean value of true of false.
	//				 Value returned is dependent if any more move are
	//				 available to make.

	status gameStatus();
	//Function will check the board and determine if there is a winner.
	//Precondition: initialize() and play() must be ran before using.
	//Postcondition: Function will check the current moves made on
	//				 the board and return a value of the enum status.

	void npcLogic();
	//Function to have the computer make a play.
	//Precondition: Function must be ran inside of getXOMove().
	//				initialize() and play() must be ran before
	//				using.
	//Postcondition: Function will determine the best play to make
	//				 for the program.

	void swapTurn(char moveSymbol);
	//Function to swap turns.
	//Precondition:	Function must be ran inside of GetXOMove().
	//				Function must recieve current player. (X or O)
	//Postcondition: Function will swap the next turn to be made.
};

//ticTacToe.cpp, the implementation file.
