/*------------------------------------------------------------------------/
 *																		  
 *Project: BattleShip											  
 *File: BattleShip.cpp													  
 *																		  
 *Abstract:																  
 *	 This file will hold all of the function definations for the program  
 *																		  
 *																		  
 *																		  
 *																		  
 *Author:																  
 *	Matty Jones															  
 *																		  
 *List of Initals														  
 *	mrj		matty jones													  
 *																		  
 *when		who		what												  
 *03-10-10	mrj		started psuedocode and designed inital game flow	  
 *03-18-10  mrj		worked on test functions and header file			  
 *03-20-10	mrj		worked on pseudocode and game flow				      
 *03-23-10	mrj		coded the grids										  
 *-----------------------------------------------------------------------*/

#include "battleship.h"
#include <cstring>	
#include <cstdlib>

using namespace std;


/*-------------------------------------/
/ this functions clear the playing grid/
/ to all empty water                   /
/-------------------------------------*/

void BattleShip::clear_grid()
{
	for (int i = 0; i < GRID_SIZE; i++)
	    for(int j = 0; j < GRID_SIZE; j++)
			m_cBattleShipGrid_ShipLocations [i][j] = '~';
	
	for (int i = 0; i < GRID_SIZE; i++)
	    for(int j = 0; j < GRID_SIZE; j++)
			m_cBattleShipGrid_HitMissLocations [i][j] = '~';
}


/*-------------------------------------/
/ this functions prints the playing    /
/ grid                                 /
/-------------------------------------*/

void BattleShip::print_grid_ship_locations()
{
	cout << " 01234567" << endl;
	
	for (int i = 0; i < GRID_SIZE; i++)
		{
			cout << i;
		
			for(int j = 0; j < GRID_SIZE; j++)
			
				cout << m_cBattleShipGrid_ShipLocations[i][j];
				cout << endl;
	}
	
}


/*-------------------------------------/
/ this functions prints the playing    /
/ grid                                 /
/-------------------------------------*/

void BattleShip::print_grid_hit_miss_locations()
{
	cout << " 01234567" << endl;
	
	for (int i = 0; i < GRID_SIZE; i++)
	{
		cout << i;
		
		for(int j = 0; j < GRID_SIZE; j++)
			
			cout << m_cBattleShipGrid_HitMissLocations[i][j];
		cout << endl;
	}
	
}

/*-------------------------------------/
/ this function takes the player's     /
/ name and sets it to a variable if    /
/ it is the right size                 /
/-------------------------------------*/

void BattleShip::start_game(int n)
{
	
	cout << "Player " << n << " please enter your name" << endl;
	
	if (n == 1)		// this is for player 1, if needed add another number for more players
	{
		cin >> m_cPlayerTempName;	// the variable to hold player 1's name
	}
	
	int a = strlen (m_cPlayerTempName);	// this gets the length of the name entered
	
	if ( a < 9)		// this will check to make sure that name fits within the array
	{
		strcpy (m_cPlayer1Name, m_cPlayerTempName);		// this sets the name entered to PLayer 1
	}
	else 
		{
			cout << "Please enter a name between 1 and 8 letters" << endl;
			start_game( n);		// this calls the function again to get them to enter a name of the right size
		}
	
	cout << m_cPlayer1Name << " please enter the location for your 5 ships using the row and column indicators" << endl;
	
	player_set_ship_location(1);
	player_set_ship_location(2);
	player_set_ship_location(3);
	player_set_ship_location(4);
	player_set_ship_location(5);

	}


/*-------------------------------------/
/ this function will set the intial    /
/ ships location on the playing grid   /
/ and perform error checking           /
/-------------------------------------*/

void BattleShip::player_set_ship_location(int n)
{
	print_grid_ship_locations();
	
	cout << "Enter the row for ship #" << n << endl;
	cin >> m_Ship_X_Location;
	
	//------------------this blocks checks for errors with input of the x value---------//
	
	while ((m_Ship_X_Location != 0) && (m_Ship_X_Location != 1) && (m_Ship_X_Location != 2) 
		&& (m_Ship_X_Location != 3) && (m_Ship_X_Location != 4) && (m_Ship_X_Location != 5) 
		&& (m_Ship_X_Location != 6) && (m_Ship_X_Location != 7))							// it will loop until the input is valid
	{
		cout << "Please enter a valid location between 0 and 7" << endl;
		cin >> m_Ship_X_Location;
		
	}
	
	//----------------------------------END BLOCK---------------------------------------//

	
	
		
	cout << "Enter the column for ship #" << n << endl;
	cin >> m_Ship_Y_Location;
	
	//------------------this blocks checks for errors with input of the y value---------//
	
		while ((m_Ship_Y_Location != 0) && (m_Ship_Y_Location != 1) && (m_Ship_Y_Location != 2) 
			&& (m_Ship_Y_Location != 3) && (m_Ship_Y_Location != 4) && (m_Ship_X_Location != 5) 
			&& (m_Ship_Y_Location != 6) && (m_Ship_Y_Location != 7))						// it will loop until the input is valid
	{
		cout << "Please enter a valid location between 0 and 7" << endl;
		cin >> m_Ship_Y_Location;
		
	}
	//----------------------------------END BLOCK---------------------------------------//


	
	
	//------------------this blocks checks to see if the spot is already taken----------//
	
		if (m_cBattleShipGrid_ShipLocations[m_Ship_X_Location] [m_Ship_Y_Location] == '~')
		{
			m_cBattleShipGrid_ShipLocations[m_Ship_X_Location] [m_Ship_Y_Location] = 's';
		}
		
		else 
		{
			cout << "That location is already taken, please enter a new location" << endl;
			player_set_ship_location(n);
		}
	//----------------------------------END BLOCK---------------------------------------//

	
	}


/*-------------------------------------/
/ this function will start the game    /
/ for the computer                     /
/-------------------------------------*/

void BattleShip::comp_start_game()
{
	comp_set_ship_location();	// fist ship
	comp_set_ship_location();	// second ship
	comp_set_ship_location();	// third ship
	comp_set_ship_location();	// fourth ship
	comp_set_ship_location();	// fifth ship
}


/*-------------------------------------/
/ this function will generate the      /
/ number used by the computer          /
/-------------------------------------*/


int BattleShip::num_generator()
{
	srand(time (NULL) );	// this is the seed number
	
	int num = rand() % 8;	// this generates the random number
	
	//int jeff = 1; jeff = 6;
	cout << num << endl;	// checking the printout of the number

	return (num);
	
	}	

/*-------------------------------------/
/ this function will set the intial    /
/ ships location on the playing grid   /
/ and perform error checking           /
/-------------------------------------*/

void BattleShip::comp_set_ship_location()
{	
	
	m_Ship_X_Location = num_generator();	// generate the x location for the ship
	
	//------------------this blocks checks for errors with input of the x value---------//
	
	while ((m_Ship_X_Location != 0) && (m_Ship_X_Location != 1) && (m_Ship_X_Location != 2) 
		&& (m_Ship_X_Location != 3) && (m_Ship_X_Location != 4) && (m_Ship_X_Location != 5) 
		&& (m_Ship_X_Location != 6) && (m_Ship_X_Location != 7))							// it will loop until the input is valid
	{
		m_Ship_X_Location = num_generator();
	}
	//----------------------------------END BLOCK---------------------------------------//
	
	
	
	m_Ship_Y_Location = num_generator();	// generate the y location for the ship
	
	//------------------this blocks checks for errors with input of the y value---------//
	
	while ((m_Ship_Y_Location != 0) && (m_Ship_Y_Location != 1) && (m_Ship_Y_Location != 2) 
		&& (m_Ship_Y_Location != 3) && (m_Ship_Y_Location != 4) && (m_Ship_X_Location != 5) 
		&& (m_Ship_Y_Location != 6) && (m_Ship_Y_Location != 7))							// it will loop until the input is valid
	{
		m_Ship_Y_Location = num_generator();
		
	}
	//----------------------------------END BLOCK---------------------------------------//
	
	
	
	//------------------this blocks checks to see if the spot is already taken----------//
	
	if (m_cBattleShipGrid_ShipLocations[m_Ship_X_Location] [m_Ship_Y_Location] == '~') // check to make sure the space is unused
	{
		m_cBattleShipGrid_ShipLocations[m_Ship_X_Location] [m_Ship_Y_Location] = 's';	 // a computer ship
	}
	
	else 
	{
		comp_set_ship_location();	// recall the function if the space was already taken
	}
	//----------------------------------END BLOCK---------------------------------------//

	
	
	
}
	

/*-------------------------------------/
/ this function will be the players    /
/ turn as they attack the computers    /
/ ships                                /
/-------------------------------------*/	

void BattleShip::player_turn(int m_iShipCounter)
{	

	print_grid_hit_miss_locations();	//this will print the grid to hold hit or misses
	
	cout << "Please select the row you want to attack" << endl;
	cin >> m_Ship_X_Location;
	
	cout << "Please select the column you want to attack" << endl;
	cin >> m_Ship_Y_Location;
	
	if (m_cBattleShipGrid_ShipLocations[m_Ship_X_Location] [m_Ship_Y_Location] == 's')	// this checks to see if the location is a ship
		{
			
			cout << "good job you hit a ship" << endl;
			m_cBattleShipGrid_HitMissLocations[m_Ship_X_Location] [m_Ship_Y_Location] = 'h';	// this means you hit something
			m_iShipCounter = m_iShipCounter --;
		}
		
	else if (m_cBattleShipGrid_ShipLocations[m_Ship_X_Location] [m_Ship_Y_Location] == '~')	// this checks to see if the location is empty water
		{
			cout << "you missed" << endl;
			m_cBattleShipGrid_HitMissLocations[m_Ship_X_Location] [m_Ship_Y_Location] = 'm';	// this means you missed
		}
	
	else if(m_cBattleShipGrid_HitMissLocations[m_Ship_X_Location] [m_Ship_Y_Location] == 'h' || m_cBattleShipGrid_HitMissLocations[m_Ship_X_Location] [m_Ship_Y_Location] == 'm')
	{
		cout << "you already picked that space" << endl;
	}
	
	
	
}


/*-------------------------------------/
/ this function will be the computers  /
/ turn as they attack the players      /
/ ships                                /
/-------------------------------------*/

void BattleShip::computer_turn(int m_iShipCounter)
{

		m_Ship_X_Location = num_generator();
	m_Ship_Y_Location = num_generator();
	
	if (m_cBattleShipGrid_ShipLocations[m_Ship_X_Location] [m_Ship_Y_Location] == 's')	// this checks to see if the location is a ship
	{
		
		
		m_cBattleShipGrid_ShipLocations[m_Ship_X_Location] [m_Ship_Y_Location] = 'h';	// this means you hit something
		m_iShipCounter = m_iShipCounter --;
	}
	
	else if (m_cBattleShipGrid_ShipLocations[m_Ship_X_Location] [m_Ship_Y_Location] == '~')	// this checks to see if the location is empty water
	{
	
		m_cBattleShipGrid_ShipLocations[m_Ship_X_Location] [m_Ship_Y_Location] = 'm';	// this means you missed
	}
	
		


}

int BattleShip::end_game(int m_iShipCounter)
{
	if (m_iShipCounter == 0)
	{
		cout << "game over" << endl;
		return 0;
	}
}
/*
void BattleShip::play_game()
{




}
*/
