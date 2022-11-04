#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

#include "gameoflife.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void playGame();
    void gamePlaying();
    void stepGame();
    void pauseGame();
    void ChangeColor(Cell * c);
    void CellLeftClickedSlot(Cell * c);
    void CellRightClickedSlot(Cell * c);
    void SliderSlot(int value);
    void LoadGameSlot(QString s);
    void selectMasterColor();

private:
    Ui::MainWindow *ui;
    GameOfLife *game = new GameOfLife();

    QTimer *timer = new QTimer(this);

    QGraphicsScene *scene = new QGraphicsScene;

    bool playing_;

    int speed_;

    int turn_;

    int populationW_;

    QColor liveW_;
    QColor deadW_;

};
#endif // MAINWINDOW_H
