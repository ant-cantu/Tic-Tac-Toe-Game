//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    : L4-2 (Tic Tac Toe Game)	                        * 
//*                                                                     * 
//* Written by      : Anthony Cantu                                     * 
//*                                                                     * 
//* Purpose         : To play a game of tic tac toe	                    * 
//*                                                                     * 
//* Inputs          : User selects if they want to play against the		*
//*					  computer or another user.							*
//*					  User selects if X or O goes first.				*
//*					  User/s must input a move by selecting a position	*
//*					  on the board.										* 
//*                                                                     * 
//* Outputs         : Prompts the user with menu selection.				*
//*					  Prompts the user to make a move on the board.		*
//*					  Display the board to the user.					*
//*					  Checks and outputs if a winner is found.			* 
//*                                                                     * 
//* Calls           : Functions within ticTacToe.h header file.         *         							 	
//*                                                                     * 
//* Structure       : BEGIN                                             * 
//*                        Straight line code no sub-processes          * 
//*                   STOP                                              * 
//*                        End of Program                               * 
//*                                                                     * 
//*---------------------------------------------------------------------* 
//* Collaboration   : The Goonies										*
//*                                                                     * 
//*---------------------------------------------------------------------* 
//* Change Log:                                                         * 
//*                         Revision                                    * 
//*       Date    Changed  Rel Ver Mod Purpose                          * 
//* 11/29/23      acantu 000.000.000 Initial release of program       	* 
//*                                                                     * 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
#include <iostream>
#include "ticTacToe.h"

using namespace std;

int main()
{
	cout << "Anthony Cantu\t" << "L4-2\t" << "L4-2.exe" << endl;

	ticTacToe game;	//Initialize ticTacToe object.

	game.play();	//Start the game

	cout << "Press any key to Exit.";
	char q;
	cin.ignore(2, '\n');
	cin.get(q);
	return 0;
}