#ifndef CELL_H
#define CELL_H

#include <QColor>
#include <QGraphicsItem>
#include <QGraphicsScene>


/*
 * Position struct hols the info to locate a cell in the 2d array
*/
struct Position {
    int row;
    int col;

    // already implemented for you!
    bool operator==(const Position &other) {
        return row == other.row && col == other.col;
    }
};

/*
 * Handles the creating and status of the cells that make up the grid in the UI
*/
class Cell: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Cell(QColor status, const int x, const int y, Position pos);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

    QColor get_status() { return status_;}
    void ChangeCellStatus();
    void SetCellStatus(QColor s) {status_ = s; update();}

    void SetNextStatus(QColor s) {next_status_ = s; update();}
    QColor get_next_status(){return next_status_;}

    int get_neighbors(){return neighbors_;}
    void set_neighbors(int n){neighbors_ = n; update();}

    Position get_position(){return pos_;}


private:
    int x_;
    int y_;

    int const width_ = 20;

    bool change_;

    QColor status_;
    QColor next_status_;
    QColor live_cell_;
    QColor dead_cell_;

    int neighbors_;

    Position pos_;


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void CellSelected(Cell *c);
    void CellRightClicked(Cell * c);

};

#endif // CELL_H
