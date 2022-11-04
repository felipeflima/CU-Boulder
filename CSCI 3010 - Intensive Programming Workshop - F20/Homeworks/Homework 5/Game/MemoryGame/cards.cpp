#include "cards.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>

/*
 * Converts the enum class into a QPixmap readable by the program to add the image to the view
*/
QPixmap CardTypePixify(CardType cd){
    QPixmap background(":/rsc/Resources/background.png");
    QPixmap card(":/rsc/Resources/card.png");
    QPixmap farm(":/rsc/Resources/farm.jpg");
    QPixmap cow(":/rsc/Resources/cow.png");
    QPixmap dog(":/rsc/Resources/dog.png");
    QPixmap farmer(":/rsc/Resources/farmer.png");
    QPixmap pig(":/rsc/Resources/pig.png");
    QPixmap snake(":/rsc/Resources/snake.png");
    QPixmap chicken(":/rsc/Resources/chicken.png");
    QPixmap duck(":/rsc/Resources/duck.png");
    QPixmap goat(":/rsc/Resources/goat.png");
    QPixmap horse(":/rsc/Resources/horse.png");
    QPixmap sheep(":/rsc/Resources/sheep.png");

    switch(cd){
        case CardType::Background: return background; break;
        case CardType::Card: return card; break;
        case CardType::Farm: return farm; break;
        case CardType::Cow: return cow; break;
        case CardType::Dog: return dog; break;
        case CardType::Farmer: return farmer; break;
        case CardType::Pig: return pig; break;
        case CardType::Snake: return snake; break;
        case CardType::Chicken: return chicken; break;
        case CardType::Duck: return duck; break;
        case CardType::Goat: return goat; break;
        case CardType::Horse: return horse; break;
        case CardType::Sheep: return sheep; break;

        //defaut: std::cout << "error";
    }
}

// Card constructor
Cards::Cards(const int x, const int y, Position pos, CardType type)
{
    QPixmap card(":/rsc/Resources/card.png");

    x_ = x;
    y_ = y;
    pos_ = pos;
    visible_ = false;
    appearence_ = card;
    visible_ = false;
    type_ = type;
    value_ = CardTypePixify(type);
    match_ = false;

}



void Cards::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
//    qDebug() << "Clicked";
    emit CardSelected(this);
    visible_ = true;
    appearence_ = value_;


    update();
}


QRectF Cards::boundingRect() const
{
    return QRectF(x_, y_, width_, height_);
}

QPainterPath Cards::shape() const
{
    QPainterPath path;
    path.addRect(x_, y_, width_, height_);
    return path;
}

void Cards::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);


    QBrush b = painter->brush();
    // update the line for setBrush to be this
//    painter->setBrush(QBrush(color_));

//    painter->drawRect(QRect(this->x_, this->y_, this->width_, this->height_));

    painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->height_), appearence_);

    painter->setBrush(b);

}
