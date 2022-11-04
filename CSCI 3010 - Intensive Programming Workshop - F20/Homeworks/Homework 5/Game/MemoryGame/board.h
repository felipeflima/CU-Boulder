#ifndef BOARD_H
#define BOARD_H

#include "cards.h"
#include <QColor>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QLabel>
#include <vector>

struct Player{
    int id;
    int points;
    int cards_picked;
    CardType type_card;
    Cards* cardP;
};




class Board: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    static Board& GetInstance(){
                static Board instance;
                return instance;
            }
            Board(Board const&) = delete; // copy constructor
            void operator=(Board const&) = delete; // assignment operator

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

    Cards *get_card(Position pos) {return arr_[pos.row][pos.col];}

    void generateSetOfNumbers();

    bool isGameOver();

    void TakeTurn(Cards* card);

    Player * getCurrPlayer(){return current_player;}
    Cards* getCurrCard(){return currCard;}
    int getCurrPlayerPoints(){return current_player->points;}

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:

    Board();
    const int x_ = 0;
    int y_ = 0;

    int const width_ = 1141;
    int const height_ = 712;

    Cards *arr_[3][6];

    int orderCards[18];

//    std::vector<Player *> players_;
    int turn_count_;
    int num_players_;

    Player * player1  = new Player();
    Player * player2  = new Player();
    Player * current_player;
    Cards* currCard;

signals:
    void reset();
    void updatePoints();
    void updatePlayer();

};


#endif // BOARD_H
