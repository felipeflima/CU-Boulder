#ifndef GRAPH_H
#define GRAPH_H

#include <QColor>
#include <QGraphicsItem>


/*
 * Graph class handles the bars in the graph
*/
class Graph:public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Graph(int height, int x, int y);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

    int get_x(){return x_;}
    void set_x(int value){x_ = value;}

    int get_y(){return y_;}
    void set_y(int value){y_ = value;}

    int get_height(){return height_;}
    void set_height(int value){height_ = value;}

private:
    int height_;
    int x_;
    int y_;
    QColor bar_color;

    int const width_ = 20;
};

#endif // GRAPH_H
