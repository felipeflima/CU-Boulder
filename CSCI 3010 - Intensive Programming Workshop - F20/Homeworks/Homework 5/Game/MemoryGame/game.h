#ifndef GAME_H
#define GAME_H

#include <QColor>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QLabel>


struct Player{
    int id;
    int points;
};

class Game: QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Game();
};

#endif // GAME_H
