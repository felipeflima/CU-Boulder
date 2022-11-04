#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>

#include "cell.h"


Cell::Cell(QColor status, const int x, const int y, Position pos)
{
    QColor live(255,0,155);
    QColor dead(0,0,0);
    QColor next(0,255,0);
    live_cell_ = live;
    dead_cell_ = dead;
    this->status_ = status;
    x_ = x;
    y_ = y;
    next_status_ = next;
    change_ = 0;
    pos_ = pos;
    neighbors_ = -1;
}

/*
 * If a cell is clicked function handles responde
*/
void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){ //left click
           emit CellSelected(this);
    }
    else if(event->button() == Qt::RightButton){ // right click
         emit CellRightClicked(this);
    }
    update();
}


QRectF Cell::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}

QPainterPath Cell::shape() const
{
    QPainterPath path;
    path.addRect(x_, y_, width_, width_);
    return path;
}

void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);


    QBrush b = painter->brush();
    // update the line for setBrush to be this
    painter->setBrush(QBrush(status_));

    painter->drawRect(QRect(this->x_, this->y_, this->width_, this->width_));
    painter->setBrush(b);
}

void Cell::ChangeCellStatus(){
    if (status_ == live_cell_){
        status_= dead_cell_;
    }
    else{
        status_ = live_cell_;
    }
    update();
}
