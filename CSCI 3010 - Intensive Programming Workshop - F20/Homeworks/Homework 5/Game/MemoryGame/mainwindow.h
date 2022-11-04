#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include "cards.h"
#include "board.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene = new QGraphicsScene;

//    Board *board = new Board();

    QTimer *timer = new QTimer(this);

    bool resetCheck;

    Board& board = Board::GetInstance();



private slots:
    void CardClicked(Cards * card);
    void resetC();
    void timerStart();
    void updatePoints();
    void updatePlayer();


};
#endif // MAINWINDOW_H
