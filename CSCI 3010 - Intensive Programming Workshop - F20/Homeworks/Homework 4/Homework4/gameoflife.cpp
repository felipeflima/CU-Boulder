#include <QDebug>
#include <QTime>
#include <vector>
#include "gameoflife.h"
#include "cell.h"
#include "graph.h"

/*
 * Game constructor created the cells and the graph
*/
GameOfLife::GameOfLife()
{
    srand(time(NULL));
    int chance = 0;
    QColor live(255,0,155);
    QColor dead(0,0,0);
    QColor test(0,0,255);
    QColor status;
    live_ = live;
    dead_ = dead;
    test_ = test;
    populationG_ = 0;
    int x_coord = 40;
    int y_coord = 40;
    Position pos = {0,0};
    for(int i = 0; i < 15; i++){ //creates the cell and insert them into the 2d array
        for(int j = 0; j < 35; j++){
            pos = {i,j};
            chance = rand() % 100; // 50% chance to be alive
            if (chance < 50){
                status = live_;
                populationG_++;
            }
            else{
                status = dead_;
            }
            Cell * c = new Cell(status, x_coord, y_coord, pos);
            arr_[i][j] = c;
            x_coord += 20;
        }
        x_coord = 40;
        y_coord += 20;
    }

    // creates blue box and first bar of the graph
    bar_pos_ = 40;
    graph_->setBrush(QBrush(test_));
    Graph * g = new Graph((populationG_/525.0)*100, bar_pos_, 100-((populationG_/525.0)*100)+360);
    bars_.push_back(g);

}

/*
 * handles each turn of the game
*/
void GameOfLife::turn(){
    Position pos = {0,0};
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 35; j++){
            pos = {i,j};
            num_neighbors(get_cell(pos)); // sets the number of neighbors for each cell
            isChange(get_cell(pos)); // sets each cell next turn's status
        }
    }
    populationG_ = 0;
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 35; j++){
            pos = {i,j};
            get_cell(pos)->SetCellStatus(get_cell(pos)->get_next_status()); //update cell acording to next turn's status
            if (get_cell(pos)->get_status() == live_){ //calculates population
                populationG_++;
            }
        }
    }

    if(bars_.size() < 35){ //if the bars still fit in the graph
        bar_pos_ += 20;
        Graph * g = new Graph((populationG_/525.0)*100, bar_pos_, (100-((populationG_/525.0)*100))+360); // creates a new bar
        bars_.push_back(g);
        update();
    }
    else if (bars_.size() >= 35){ // if the bars don't fit anymore
        for (int i = 0; i < bars_.size()-1; i ++){
            bars_[i]->set_height(bars_[i+1]->get_height()); //updates previous bar to be equal to the next one
            bars_[i]->set_y(bars_[i+1]->get_y()); // fixes the height
            update();
        }
        Graph * g = new Graph((populationG_/525.0)*100, bar_pos_, (100-((populationG_/525.0)*100))+360);
        bars_.push_back(g); //add the new bar
        update();
    }


}


/*
 * sets the number of neighbors for a cell
*/
void GameOfLife::num_neighbors(Cell *c){
    int neighbors = 0;
    Position pos = c->get_position();

    // relative positions to the cell
    Position up = {pos.row-1, pos.col};
    Position down = {pos.row+1, pos.col};
    Position left = {pos.row, pos.col-1};
    Position right = {pos.row, pos.col+1};

    Position topl = {pos.row-1, pos.col-1};
    Position topr = {pos.row-1, pos.col+1};
    Position botl = {pos.row+1, pos.col-1};
    Position botr = {pos.row+1, pos.col+1};

    std::vector<Position> moves {up, down, left, right, topl, topr, botl, botr};

    // ajust for edge cases and add neighbors
    for (int i = 0; i < moves.size(); i++){
        if (moves.at(i).row < 0){
            moves.at(i).row = 14;
        }
        else if (moves.at(i).row > 14){
            moves.at(i).row = 0;
        }
        if (moves.at(i).col < 0){
            moves.at(i).col = 34;
        }
        else if (moves.at(i).col > 34){
            moves.at(i).col = 0;
        }
        if (get_cell(moves.at(i))->get_status() == live_){
            neighbors++;
        }
    }
    c->set_neighbors(neighbors);
    update();
}

/*
 * sets cell's next turn's status based on how many neighbors and the rules of the game
*/
void GameOfLife::isChange(Cell * c){
    int neighbors = c->get_neighbors();
    if (c->get_status() == live_){
        if(neighbors < 2){
            c->SetNextStatus(dead_);
        }
        else if (neighbors == 2 || neighbors == 3){
            c->SetNextStatus(live_);
        }
        else if(neighbors > 3){
            c->SetNextStatus(dead_);
        }
    }
    else{
        if(neighbors == 3){
            c->SetNextStatus(live_);
        }
        else{
            c->SetNextStatus(dead_);
        }
    }
}

