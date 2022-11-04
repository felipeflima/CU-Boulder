#ifndef CARDS_H
#define CARDS_H

#include <QColor>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QLabel>



enum class CardType{Background, Card, Farm, Cow, Dog, Farmer, Pig, Snake, Chicken, Duck, Horse, Goat, Sheep};


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

class Cards: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Cards(const int x, const int y, Position pos, CardType type);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

    bool isVisible(){return visible_;}
    void setVisibility(bool v){visible_ = v;}
    CardType getType(){return type_;}

    void resetCard(){QPixmap card(":/rsc/Resources/card.png"); visible_ = false; appearence_ = card;update();}

    void setAppearence(){appearence_ = value_;update();}


    bool getMatch(){return match_;}
    void setMatch(bool s){match_ = s;}



protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    int x_;
    int y_;

    int const width_ = 120;
    int const height_ = 160;

    Position pos_;

    bool visible_;

    QPixmap appearence_;

    QPixmap value_;

    CardType type_;

    bool match_;


signals:
    void CardSelected(Cards *c);

};


//class SpecialCards: public Cards{
//public:
//    SpecialCards():
//        Cards(){}
//};

#endif // CARDS_H
