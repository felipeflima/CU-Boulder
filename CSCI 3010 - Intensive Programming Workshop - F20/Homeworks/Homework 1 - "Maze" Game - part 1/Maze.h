/* CSCI 3010 - IPW
* Felipe Lima
* Homework 1 - "Maze" Game - part 2
* 09/18/2020
* Fun-ish maze game. User controls the player and the enemies and tries to reach the exit with the human
* How to run: using Makefile
~make
~./maze
*/
#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include "Player.h"

// you may change this enum as you need
enum class SquareType { Wall, Exit, Empty, Human, Enemy, Treasure, Trap, Moon, Wolf };

// TODO: implement
// this function should return a string representation of a given SquareType
// for example an ascii letter or an emoji
std::string SquareTypeStringify(SquareType sq);

class Board {
public:
	// TODO: implement
	Board();
	
	// already implemented in line
	int get_rows() const {return 4; }  // you should be able to change the size of your 
	int get_cols() const {return 4; }  // board by changing these numbers and the numbers in the arr_ field

	// TODO: you MUST implement the following functions
	SquareType get_square_value(Position pos) const; 

	// set the value of a square to the given SquareType
	void SetSquareValue(Position pos, SquareType value);

	// get the possible Positions that a Player could move to
	// (not off the board or into a wall)
	std::vector<Position> GetMoves(Player *p);

	bool IsMove(Position pos, Player *p);

	// Move a player to a new position on the board. Return
	// true if they moved successfully, false otherwise.
	bool MovePlayer(Player *p, Position pos);

	// Get the square type of the exit square
	SquareType GetExitOccupant();

	std::vector <Position> GetEnemiesPositions(){return enemies_positions_;}

	// You probably want to implement this
	friend std::ostream& operator<<(std::ostream& os, const Board &b){
		for (int i = 0; i < 4; i ++){
			for (int j = 0; j < 4; j++){
				os << SquareTypeStringify(b.arr_[i][j]) + " ";
			}
			std::cout << std::endl;
		}
		return os;
	}

	Position DirectionToPosition(std::string direction, Player *p);
	// std::vector<Position> EnemyPosition();

private:
	SquareType arr_[4][4];
	std::vector <Position> enemies_positions_;

	//int rows_; // might be convenient but not necessary
	//int cols_;
	
	// you may add more fields, as needed
};  // class Board

class Maze {
public:
	// TODO: implement these functions
	Maze(); // constructor

	// initialize a new game, given one human player and 
	// a number of enemies to generate
	void NewGame(Player *human, const int enemies);

	// have the given Player take their turn
	void TakeTurn(Player *p);

	// Get the next player in turn order
	Player * GetNextPlayer();

	// return true iff the human made it to the exit 
	// or the enemies ate all the humans
	bool IsGameOver();

	// You probably want to implement these functions as well
	// string info about the game's conditions after it is over
	std::string GenerateReport();
	friend std::ostream& operator<<(std::ostream& os, const Maze &m);

private:
	Board *board_; // HINT: when you instantiate your board_, use the new Board() syntax
	std::vector<Player *> players_;
	int turn_count_;
	int num_enemies_;

	// you may add more fields, as needed

};  // class Maze

#endif  // MAZE_H
