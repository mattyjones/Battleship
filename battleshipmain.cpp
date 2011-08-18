/*------------------------------------------------------------------------/
 *																		  /
 *Project: Project 2 BattleShip											  /
 *File: BattleShipMain.cpp												  /
 *																		  /
 *Abstract:																  /
 *	 This file is the main for the program								  /
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


#include "battleship.h"

using namespace std;

int main()

{

	//BattleShip game;
	BattleShip player;
	BattleShip computer;
	
	int m_iShipCounter = 5;			// the number of ships each player has
	
	player.clear_grid();			// this clears the grid at the beginning of a game
	computer.clear_grid();			// this will clear the grid for the computer
	
	
	player.start_game(1);			// this takes the players name and sets it to a variable, for more players just add another instance
								//game.comp_set_ship_location(5);
	
	computer.comp_start_game();		// this places the computer ships on the grid
	
	
	
	do	{
	computer.player_turn(m_iShipCounter);
	player.computer_turn(m_iShipCounter);
	player.print_grid_ship_locations();
	}while (m_iShipCounter != 0);
	
	
	/*
	computer.player_turn();
	player.computer_turn();
	player.print_grid_ship_locations();
	
	computer.player_turn();
	player.computer_turn();
	player.print_grid_ship_locations();
	*/
	
	return (0);
}
