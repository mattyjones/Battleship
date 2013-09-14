/*------------------------------------------------------------------------/
 *																		  /
 *Project: BattleShip											  /
 *File: BattleShip.h													  /
 *																		  /
 *Abstract:																  /
 *	 This is the header file for the program							  /
 *																		  /
 *																		  /
 *																		  /
 *																		  /
 *Author:																  /
 *	Matty Jones															  /
 *																		  /
 *List of Initals														  /
 *	mrj		matty jones													  /
 *																		  /
 *when		who		what												  /
 *03-10-10	mrj		started psuedocode and designed inital game flow	  /
 *03-18-10  mrj		worked on test functions and header file			  /
 *03-20-10	mrj		worked on pseudocode and game flow				      /
 *03-23-10	mrj		coded the grids										  /
 *-----------------------------------------------------------------------*/


#ifndef _BATTLESHIP_H_
#define _BATTLESHIP_H_

#include <iostream>
#include "default.h"


class BattleShip
{
	
public:
	
	//BattleShip();															// default constructor
	//~BattleShip();														// default destructor
	
	void clear_grid();														// this function with initalize the grid to all water '~' spaces
	void print_grid_ship_locations();														// this function will print the grid with ship locations
	void print_grid_hit_miss_locations();														// this function will print the grid hits and misses
	void start_game(int);													// this will let the player input their name
	void player_set_ship_location(int n);												// this will set the inital ship locations for the player
	void comp_set_ship_location();										// this will set the inital ship locations for the computer player
	int num_generator();													// this will generate the number
	void comp_start_game();
	void computer_turn(int);													// this is the cmputers turn
	int end_game(int);
	//int m_iShipCounter;
	//char check_condition_game();											// this will check for a win condition
	
	void player_turn(int);													// this function is player's turn 
	/*
	void end_game(char[9], char);											// this will print the winner's name and ask if they want to play again
	void testing(int);
	//void add_move();
	//void play_game(int);
	//char win_draw();
	//int win_game(char[9], char);
	//int draw_game(char);
	//int play_game2(char);
	*/
private:
	
	char m_cBattleShipGrid_ShipLocations[GRID_SIZE][GRID_SIZE];							// this is the array that will hold the grid for the ship locations
	char m_cBattleShipGrid_HitMissLocations[GRID_SIZE][GRID_SIZE];							// this is the array that will hold the grid for the ship hits and misses
	//char m_cWinNoWin;														// this will hold the value for the win(w), draw(d), or continue(c)
	//char m_cToken;														// this will represent the player on the board
	char m_cPlayer1Name[9];													// this is the player's name
	char m_cPlayerTempName[9];												// this is a temp variable to hold the player's name
	//char m_p2_cName[9];													// this is the player's name
	
	//char * p_test;
	int m_Ship_X_Location;													// this holds the x location
	int m_Ship_Y_Location;													// this holds the y location
	//char horz_vert_location;												// this will say if they want their ship placed vertical or horizontal for multi-character ships
	//int m_iShipCounter;														// this will hold the counter for all ships being found
	//char m_cGameState;													// this will hold the currrent state of the game
																			//char m_cContinueGame;
};

#endif

