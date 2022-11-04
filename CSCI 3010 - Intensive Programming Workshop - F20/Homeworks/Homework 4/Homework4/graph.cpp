#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>


#include "graph.h"

Graph::Graph(int height, int x, int y)
{
    QColor color(255,0,0);
    height_ = height;
    x_ = x;
    y_ = y;
    bar_color = color;
}

QRectF Graph::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}

QPainterPath Graph::shape() const
{
    QPainterPath path;
    path.addRect(x_, y_, width_, width_);
    return path;
}

void Graph::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);


    QBrush b = painter->brush();
    // update the line for setBrush to be this
    painter->setBrush(QBrush(bar_color));

    painter->drawRect(QRect(this->x_, this->y_, this->width_, this->height_));
    painter->setBrush(b);
}
