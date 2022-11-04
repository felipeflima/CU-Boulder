#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <QColor>
//#include <QGraphicsItem>
#include <QWidget>
#include <vector>
#include "cell.h"
#include "graph.h"

/*
 * Class handles the process of the game thorugh creating and run
*/
class GameOfLife  : public QWidget
{
    Q_OBJECT
public:
    GameOfLife();

    Cell *get_cell(Position pos) {return arr_[pos.row][pos.col];}
    QColor get_cell_status(Position pos) {return arr_[pos.row][pos.col]->get_status();}

    void turn();

    void isChange(Cell * c);

    void num_neighbors(Cell * c);

    int get_population() {return populationG_;}
    void set_population(int num) {populationG_ = num;}

    QGraphicsRectItem* get_graph(){return graph_;}
    Graph* get_bar(int pos){return bars_[pos];}

    int get_vec_size(){return bars_.size();}

    void setMasterColor(const QColor &color){live_ = color; update();}


private:
        Cell *arr_[15][35];
        QColor live_;
        QColor dead_;
        QColor test_;

        int populationG_;

        QGraphicsRectItem* graph_ = new QGraphicsRectItem(40,360,700,100);
        std::vector <Graph *> bars_;
        int bar_pos_;

signals:
        void ChangeColorTurn(Cell * c);

};

#endif // GAMEOFLIFE_H
