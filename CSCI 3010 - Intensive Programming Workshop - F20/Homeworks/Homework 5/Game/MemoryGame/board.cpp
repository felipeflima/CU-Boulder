#include "board.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>
#include <QTimer>
#include <QMessageBox>

/*
 * Board constructor
*/
Board::Board()
{
    CardType type;
    int x_coord = 40;
    int y_coord = 40;
    Position pos = {0,0};
    turn_count_ = -1;
    generateSetOfNumbers(); //randomize order of the cards
    int counter = 0;
    for(int i = 0; i < 3; i++){ //put the cards into a 2d array
        for(int j = 0; j < 6; j++){
            pos = {i,j};

            switch(orderCards[counter]){// array with numbers from 0 to 17 is randomized and used to say what cards goes where
                case 0 ... 1: type = CardType::Chicken; break;
                case 2 ... 3: type = CardType::Cow; break;
                case 4 ... 5: type = CardType::Dog; break;
                case 6 ... 7: type = CardType::Sheep; break;
                case 8 ... 9: type = CardType::Pig; break;
                case 10 ... 11: type = CardType::Duck; break;
                case 12 ... 13: type = CardType::Horse; break;
                case 14 ... 15: type = CardType::Goat; break;
                case 16: type = CardType::Snake; break;
                case 17: type = CardType::Farmer; break;
            }
            counter++;
            Cards * c = new Cards(x_coord, y_coord, pos, type); // creates the new card
            arr_[i][j] = c; // inserts into cards array
            x_coord += 180;
        }
        x_coord = 40;
        y_coord += 180;
    }

    num_players_ = 1;
    player1->id = 1;
    player1->points = 0;
    player1->cards_picked = 0;
    player2->id = 2;
    player2->points = 0;
    player2->cards_picked = 0;

    current_player = player1;

}

/*
 * randomize a sequence of numbers and insert into an array
 * used to define the position of the cards
*/
void Board::generateSetOfNumbers()
{
    srand (time(NULL));
    int p[18] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};

    //shuffle p
    for (int i=17; i>0; --i)
    {
    //get swap index
    int j = rand()%i;
    //swap p[i] with p[j]
    int temp = p[i];
    p[i] = p[j];
    p[j] = temp;
    }

    //copy first n elements from p to arr
    for (int i=0; i<18; ++i)
    orderCards[i] = p[i];
    for(int i = 0; i < 18; i++){
        qDebug() << orderCards[i];
    }
}

void Board::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
//    qDebug() << "Clicked";
}


QRectF Board::boundingRect() const
{
    return QRectF(x_, y_, width_, height_);
}

QPainterPath Board::shape() const
{
    QPainterPath path;
    path.addRect(x_, y_, width_, height_);
    return path;
}

void Board::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);


    QBrush b = painter->brush();

    QPixmap bkgd(":/rsc/Resources/background.png");
    painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->height_), bkgd);

    painter->setBrush(b);

}

/*
 * checks if the game is over and shows a text box meessage when the game is over
*/
bool Board::isGameOver(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 6; j++){
            if (arr_[i][j]->isVisible() == false && arr_[i][j]->getType() != CardType::Farmer && arr_[i][j]->getType() != CardType::Snake)
                return false;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 6; j++){
            arr_[i][j]->setAppearence();
        }
    }
    qDebug() << "END";
    std::string winner;
    if (player1->points > player2->points){
        winner = "Winner: Player 1";
    }
    else if (player1->points < player2->points){
        winner = "Winner: Player 2";
    }
    else{
        winner = "It's a tie!";
    }
    QMessageBox msg;
    std::string t = "Game ended! " + winner;
    QString qt(t.c_str());
        msg.setText(qt);
        msg.exec();
    return true;
}

/*
 * Administers each turn of the game
*/
void Board::TakeTurn(Cards* card){

    if(current_player->cards_picked >= 2){ // if the current player has flipped 2 or more cards, move on to the next player
        current_player->cards_picked = 0;
        if(current_player->id == player1->id){
            current_player = player2;
        }
        else{
            current_player = player1;
        }
        emit updatePlayer();

    }
    if(card->getType() == CardType::Snake){ //if the card is a trap skip this player
        current_player->cards_picked = 2;
        card->resetCard();
    }
//    else if(card->getType() == CardType::Farmer){
//        current_player->cards_picked = -1;
//    }
    if (current_player->cards_picked == 0){ //if the first card the user is picking
        current_player->cardP = card;

    }
    else if(current_player->cards_picked == 1){ //if it is the second card the user is picking
        currCard = card;
        if (current_player->cardP->getType() != card->getType()) //if they don't match
        {
            emit reset(); //reset the cards so they are facing down
        }
        else{ //if they match
            current_player->points++; //add points to player
            card->setMatch(true);
            emit updatePoints();
        }

    }


    current_player->cards_picked++;
    isGameOver();


}

