#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QTime>
#include <QColorDialog>


#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsView * view = ui->graphicsView;
    view->setScene(scene);

    view->setSceneRect(0,0,view->size().width()-2,view->size().height()-2);

    scene->addItem(&board);

    connect(timer, SIGNAL(timeout()), this, SLOT(resetC()));
    connect(&board, &Board::reset, this, &MainWindow::timerStart);
    connect(&board, &Board::updatePoints, this, &MainWindow::updatePoints);
    connect(&board, &Board::updatePlayer, this, &MainWindow::updatePlayer);


    // adds the cards to the scene
    Position pos = {0,0};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 6; j++){
            pos = {i,j};
            scene->addItem(board.get_card(pos));
            connect(board.get_card(pos), &Cards::CardSelected, this, &MainWindow::CardClicked);
        }
    }

    resetCheck = false;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CardClicked(Cards * card){

    if (!board.isGameOver()){
        board.TakeTurn(card);
//        board->addCardPlayer(card);
    }

}

/*
 * used to time the cards that don't match so they face down after 2 seconds
*/
void MainWindow::timerStart(){
     timer->start(2000);
     resetCheck = true;

}

/*
 * reset the cards after two seconds so they are facing down
*/
void MainWindow::resetC(){
    Position pos = {0,0};
    if(resetCheck == true){
//        for(int i = 0; i < 3; i++){
//            for(int j = 0; j < 6; j++){
//                pos = {i,j};
//                if(board.get_card(pos)->isVisible() == true && board.get_card(pos)->getMatch() == false){
//                    board.get_card(pos)->resetCard();
//                }
//            }
//        }
        board.getCurrPlayer()->cardP->resetCard(); // both cards selected by the player
        board.getCurrCard()->resetCard();
    }
    resetCheck = false;
}

/*
 * update the points display in the view
*/
void MainWindow::updatePoints(){
    Player * temp = board.getCurrPlayer();
    if (temp->id == 1){
        std::string t = "Player1: " + std::to_string(temp->points);
        QString qt(t.c_str());
        ui->p1Score->setText(qt);
    }
    else{
        std::string t = "Player2: " + std::to_string(temp->points);
        QString qt(t.c_str());
        ui->p2Score->setText(qt);
    }
}


/*
 * updates the current player display
*/
void MainWindow::updatePlayer(){
    std::string t = "Current Player: " + std::to_string(board.getCurrPlayer()->id);
    QString qt(t.c_str());
    ui->curPlayer->setText(qt);
}

