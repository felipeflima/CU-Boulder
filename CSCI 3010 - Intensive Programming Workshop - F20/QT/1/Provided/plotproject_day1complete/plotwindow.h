#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "point.h"
namespace Ui {
class PlotWindow;
}

class PlotWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlotWindow(QWidget *parent = 0);
    ~PlotWindow();


private slots:
    void on_randomButton_clicked();

    // Day 1, Task 5
    void SlotTest();

    void on_addButton_clicked();

    void PointSelectedSlot(int x, int y);

private:
    Ui::PlotWindow *ui;

    QGraphicsScene *scene;
};

#endif // PLOTWINDOW_H
