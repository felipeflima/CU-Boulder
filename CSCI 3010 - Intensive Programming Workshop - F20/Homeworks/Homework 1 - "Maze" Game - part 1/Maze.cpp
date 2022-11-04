/* CSCI 3010 - IPW
* Felipe Lima
* Homework 1 - "Maze" Game - part 2
* 09/18/2020
* Fun-ish maze game. User controls the player and the enemies and tries to reach the exit with the human
* How to run: using Makefile
~make
~./maze
*/ 

// -----_____-__-___-_______----_-_-_____-_--_--_____-_----____---


#include <iostream>
#include <cstdlib>
#include <string>
#include "Player.h"
#include "Maze.h"

/**
 * Compares the SquareType passed into the function and returns the corresponding representation in string or emoji
 * @param a SquareType
 * @return Return a string representation of a given SquareType
 */ 
std::string SquareTypeStringify(SquareType sq){
	std::string genie = "\U0001F9DE"; // all of these set a string to a hex representation of an emoji
    std::string wolf = "\U0001F43A";
    std::string zombie = "\U0001F9DF";
    std::string white_square = "\U00002B1C";
    std::string wall = "\U0000274C"; // or "\xE2\x9D\x8C"
	std::string exit = "\U00002705";
    std::string fire = "\U0001F525";
    std::string moon = "\U0001F315";
    std::string man = "\U0001F468";
	std::string error = "error";

	switch(sq){
		case SquareType::Wall: return wall; break; //if the SquareType passed into the function is x , return string representsation of x
		case SquareType::Exit: return exit; break;
		case SquareType::Empty: return white_square; break;
		case SquareType::Human: return man; break;
		case SquareType::Enemy: return zombie; break;
		case SquareType::Treasure: return genie; break;
        case SquareType::Trap: return fire; break;
        case SquareType::Moon: return moon; break;
        case SquareType::Wolf: return wolf; break;
        //defaut: std::cout << "error";
	}
}

/**
 * Initializes the board by populating the squares with 10% chance of being a treasure, 20% chance of being a wall, 10% chance of being a Trap, 5% chance of being a moon
 * Inserst human and exit on respective locations
 * inserts enemies on desired location
 */ 
Board::Board(){
    srand (time(NULL));
    int random;
    int random2;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            random = (rand() % 20);
            if (random == 0 || random == 1){
                arr_[i][j] = SquareType::Treasure;
            }
            else if (random >= 2 && random <= 5){
                arr_[i][j] = SquareType::Wall;
            }
            else if (random == 6 || random == 7){
                arr_[i][j] = SquareType::Trap;
            }
            else if (random == 8){
                arr_[i][j] = SquareType::Moon;
            }
            else{
                arr_[i][j] = SquareType::Empty;
            }
        }
    }
    int num_enemies = 2;
    int i = 0;
    int enemy_x = -1;
    int enemy_y = -1;
    while (i < num_enemies){
        random = (rand() % 4);
        random2 = (rand() % 4);
        //std::cout << random << std::endl;
        if ((random != 0 || random2 != 0) && (random != 3 || random2 != 3) && (random != enemy_x || random2 != enemy_y))
        {
            enemy_x = random;
            enemy_y = random2;
            arr_[random][random2] = SquareType::Enemy;
            Position enemy_pos = {enemy_x, enemy_y};
            enemies_positions_.push_back(enemy_pos);
            i++;
        }
    }
    // arr_[0][3] = SquareType::Enemy;
    // arr_[2][0] = SquareType::Enemy;
    arr_[0][0] = SquareType::Human;
    arr_[3][3] = SquareType::Exit;
}

/**
 * Returns the type of the square of the position passed into the function
 * @param position
 * @return the SquareType of the position
 */ 
SquareType Board::get_square_value(Position pos) const{
    SquareType type  = arr_[pos.row][pos.col];
    return type;
}

/**
 * Sets the type of the square passed as the position parameter as the squaretype passed to the function
 * @param positoin and squaretype
 */ 
void Board::SetSquareValue(Position pos, SquareType value){
    arr_[pos.row][pos.col] = value;
}

/**
 * Gets the possible moves for the player
 * @param player
 * @return  a vector withb all the possible moves for that player
 */ 
std::vector<Position> Board::GetMoves(Player *p){
    std::vector<Position> moves; //creates a vector to return
    Position pos = p->get_position(); // current position and possible moves
    Position up = {pos.row-1, pos.col};
    Position down = {pos.row+1, pos.col};
    Position left = {pos.row, pos.col-1};
    Position right = {pos.row, pos.col+1};
    if (get_square_value(up) != SquareType::Wall && up.row >= 0){ // if this is a possible move, because it is not a wall and not out od bounds push this move to the vector
        moves.push_back(up);
    }
    if (get_square_value(down) != SquareType::Wall && down.row <= 3 && ((!p->is_human() && get_square_value(down) != SquareType::Exit) || p->is_human())){ //also checks for enemies not being able to move to an exit
        moves.push_back(down);
    }
    if (get_square_value(left) != SquareType::Wall && left.col >= 0){
        moves.push_back(left);
    }
    if (get_square_value(right) != SquareType::Wall && right.col <= 3 && ((!p->is_human() && get_square_value(right) != SquareType::Exit) || p->is_human())){
        moves.push_back(right);
    }
    return moves;
}

/**
 * Checks if a position to move the player is whithin the option sreturned by the array of possible moves
 * Helper function to determine if a move in MovePlayer() is valid
 * @param position and the current player
 * @return true for the position is in the vector, false otherwise
 */
bool Board::IsMove(Position pos, Player *p){
    std::vector<Position> moves = GetMoves(p);
    for (int i = 0; i < moves.size(); i++){
        if (moves.at(i) == pos){
            return true;
        }
    }
    return false;
}

/**
 * Moves the player on the board to the desired position and return true if successful, false otherwise.
 * Check for every possibility of Squaretypes in the future position
 * @param current player and future position
 * @return true if the move was Successful false otherwise
 */ 
bool Board::MovePlayer(Player *p, Position pos){
    if (!IsMove(pos, p)){ //eliminates the move if it wasn't a possiblity acconrding to GetMoves()
        return false;
    }
    std::string player_name = p->get_name();
    if (get_square_value(pos) == SquareType::Enemy){ //moving into an enemy square. 
        if (p->is_human()){
            SetSquareValue(p->get_position(), SquareType::Empty);
            p->SetPosition(pos);
        }
        return 1;
    }
    else if (get_square_value(pos) == SquareType::Exit){ //moving into the exit square
        if (p->is_human()){
            Position exit = {3,3};
            SetSquareValue(exit, SquareType::Human);
            SetSquareValue(p->get_position(), SquareType::Empty);
            p->SetPosition(pos);
            p->ChangePoints(1);
            return 1;
        }
    }
    else if (get_square_value(pos) == SquareType::Trap){ // moving into a trap square
            SetSquareValue(p->get_position(), SquareType::Empty);
            p->SetPosition(pos);
            if (!p->is_human()){
                SetSquareValue(p->get_position(), SquareType::Enemy);
            }
            return 1;
    }
    else if (get_square_value(pos) == SquareType::Human){ // moving into a human square
            SetSquareValue(p->get_position(), SquareType::Empty);
            p->SetPosition(pos);
            SetSquareValue(p->get_position(), SquareType::Enemy);
            return 1;
    }
    else if (get_square_value(pos) == SquareType::Treasure){ // moving into a Treasure square
        SetSquareValue(p->get_position(), SquareType::Empty);
        p->SetPosition(pos);
        if (p->is_human()){
            SetSquareValue(p->get_position(), SquareType::Human);
        }
        else {
            SetSquareValue(p->get_position(), SquareType::Enemy);
        }
        p->ChangePoints(100);
        std::cout << "Congratulations! " << player_name << " just collected a treasure! " << player_name << " now has " << p->get_points() << " points!" << std::endl;
        return 1;
    }
    else if (get_square_value(pos) == SquareType::Empty){ // moving into an empty square
        SetSquareValue(p->get_position(), SquareType::Empty);
        p->SetPosition(pos);
        if (p->is_human()){
            SetSquareValue(p->get_position(), SquareType::Human);
        }
        else {
            SetSquareValue(p->get_position(), SquareType::Enemy);
        }
        return true;
    }
    else if (get_square_value(pos) == SquareType::Moon){ // moving into a moon square
        SetSquareValue(p->get_position(), SquareType::Empty);
        p->SetPosition(pos);
        if (p->is_human()){
            SetSquareValue(p->get_position(), SquareType::Wolf);
        }
        else if (!p->is_human()){
            SetSquareValue(p->get_position(), SquareType::Enemy);
        }
        p->ChangePoints(150);
        return 1;
    }
    return false; // returns false by default because if the moves are executed it will return true within the if statements
}

/**
 * Gets the square type of the exit square
 * @return the sqauretype of the exit square
 */ 
SquareType Board::GetExitOccupant(){
    Position exit = {3,3};
    return get_square_value(exit);
}

/**
 * Gets the user input for the move and translates it into the future position of the player
 * @param direction input of the user and the current player
 * @return the future position of the player or invalid position if the user input is not a direction
 */ 
Position Board::DirectionToPosition(std::string direction, Player *p){
    Position invalid_position = {-1,-1};
    Position player = p->get_position();
    Position future_position = player;
    if (direction == "Up" || direction == "up"){
        future_position.row -= 1;
    }
    else if (direction == "Down" || direction == "down"){
        future_position.row += 1;
    }
    else if (direction == "Left" || direction == "left"){
        future_position.col -= 1;
    }
    else if (direction == "Right" || direction == "right"){
        future_position.col += 1;
    }
    else{
        std::cout << "Invalid direction. Please insert a valid direction" << std::endl;
        return invalid_position;
    }
    return future_position;
}


/**
 * Initializing a maze initializes a new game every time. Creates a board and the human player
 */ 
Maze::Maze(){
    board_ = new Board();
    Position human_pos = {0,0};
    turn_count_ = -1;
    Player *human = new Player("Player", 1, 0, human_pos);
    num_enemies_ = 2;
    NewGame(human, num_enemies_);
    std::cout << std::endl << *board_ << std::endl;
    while (!IsGameOver()){ // while the game is not over make the player take their turn 
        TakeTurn(GetNextPlayer());
        std::cout << std::endl << *board_ << std::endl;
    }
    std::cout << GenerateReport();
}

/**
 * Initializes a new game with the human player and the number of enemies
 * Pushes the player and enemies into the players_ vector
 * @param the human player and the number of enemies in the game
 */ 
void Maze::NewGame(Player *human, const int enemies){
    players_.push_back(human);
    for (int i = 0; i < enemies; i++){
        Player *enemy = new Player("Zombie "+std::to_string(i+1), 0, i+1, board_->GetEnemiesPositions().at(i)); //creates new enemy with name Zombie + number of enemy
        players_.push_back(enemy);
    }
}

/**
 * Have the player passed into the function to take their turn
 * @param current player
 */ 
void Maze::TakeTurn(Player *p){
    std::string player_name = p->get_name();
    std::vector<Position> moves = board_ -> GetMoves(p);
    std::string direction;
    Position future_position = {-1,-1};
    Position invalid_position = {-1,-1};

    std::cout << "It's " << player_name << "'s turn. " << player_name << " can go: " << std::endl;
    for (int i = 0; i < moves.size(); i++){
        std::cout << p->ToRelativePosition(moves.at(i)) << " "; // prints out the possible moves for the current player
    }
    std::cout << std::endl;
    std::cout << "Plase enter your choice: " << std::endl;
    while(future_position == invalid_position){ //while the user hasn't inputed a valid durection
        std::cin >> direction;
        future_position = board_ -> DirectionToPosition(direction, p); // stores in future_position the direction input translated to a position on the board
        if (!board_->MovePlayer(p, future_position)){ //if the move is denied, not valid
            std::cout << p->get_name() << " cannot move in this direction. Enter another direction." << std::endl;
            future_position = invalid_position;
        }
    }
}

/**
 * Get the next player in the right order
 * @return next player 
 */ 
Player * Maze::GetNextPlayer(){
    turn_count_++;
    if(turn_count_ > num_enemies_){turn_count_ = 0;} // if the turn count has passed the number of players reset it to 0
    Player *current = players_.at(turn_count_); //set the player current to the one in the array at position of turn count
    return current;
}

/**
 * Return true if the game is over, that is, if a human reached the exit, the enemies eliminated the humans, or it walked into a trap
 * @return true or false for game is over
 */ 
bool Maze::IsGameOver(){
    if (board_->GetExitOccupant() == SquareType::Human) { //if the human reach the exit
        std::cout << "Congratulations! You have reached the exit of the maze!" << std::endl;
        return true;
    }
    for (int i = 0; i < players_.size(); i++){
        if (players_.at(i)->is_human() && board_->get_square_value(players_.at(i)->get_position()) == SquareType::Enemy) { //if a player in the vecotrs player is human and is occupying a square in which the SqaureType is a zombie
            std::cout << "Game Over. You were eaten by a zombie!" << std::endl;
            return true;
        }
        else if (players_.at(i)->is_human() && board_->get_square_value(players_.at(i)->get_position()) == SquareType::Trap) { ///if a player in the vecotrs player is human and is occupying a square in which the SqaureType is a trap
            std::cout << "Game Over. You were eaten by a zombie!" << std::endl;
            std::cout << "Game Over. You were caught fire!" << std::endl;
            return true;
        }
    }
    return false;
}

/**
 * Reports the points for every player at the end of the game
 * @return string with the points and names of the players
 */ 
std::string Maze::GenerateReport(){
    std::string report = "";
    for (int i = 0; i < players_.size(); i++){
        report += players_.at(i)->Stringify();
    }
    return report;
}