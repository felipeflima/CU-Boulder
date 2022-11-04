#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QTime>

#include "plotwindow.h"
#include "ui_plotwindow.h"
#include "point.h"

// Name:
//
//

PlotWindow::PlotWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlotWindow)
{
    // we need to set up the ui before we draw on our scene
    ui->setupUi(this);

    // the QGraphicsView is the UI element that contains the
    // scene that we will actually get to draw on.
    QGraphicsView * view = ui->plotGraphicsView;

    // scene is a QGraphicsScene pointer field of the PlotWindow class
    // this makes our lives easier by letting us easily access it
    // from other functions in this class.
    scene = new QGraphicsScene;
    view->setScene(scene);
    // make the scene the same size as the view containing it
    view->setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());

    // we'll want to generate random numbers later so we're
    // going to seed our random number generator once
    qsrand(static_cast<unsigned>(QTime::currentTime().msec()));


    qDebug() << "Here's an example debugging statement";


    // Complete Day 1, Task 2, number 1 here.
    // Calculate the mid points
    int x_mid = view->frameSize().height() / 2;
    int y_mid = view->frameSize().width() / 2;
    // draw the axes
    scene->addLine(0, x_mid, view->frameSize().width(), x_mid);
    scene->addLine(y_mid, 0, y_mid, view->frameSize().height());

    // Day 1, Task 5, number 2 here.
    connect(ui->randomButton, &QAbstractButton::pressed, this, &PlotWindow::SlotTest);

    // equations to calculate adjested coordinates
    int x = 0;
    int y = 0;
    int x_adj = x + (ui->plotGraphicsView->frameSize().width() / 2) - Point::get_width()/2;
    int y_adj = (-1 * y + (ui->plotGraphicsView->frameSize().height() / 2))- Point::get_width()/2;
    QColor color (0,0,255);
    Point *p = new Point(color,x_adj,y_adj);
    scene->addItem(p);
    connect(p, &Point::PointSelected, this, &PlotWindow::PointSelectedSlot);


}

// Day 1, Task 5, number 1 here.
void PlotWindow::SlotTest() {
    qDebug() << "random button pressed custom slot!";
}



PlotWindow::~PlotWindow()
{
    delete ui;
}

void PlotWindow::on_randomButton_clicked()
{
    qDebug() << "random button clicked default slot!";
}

void PlotWindow::on_addButton_clicked()
{
    bool safe_x = false;
    int x = ui->xCoord->text().toInt(&safe_x);
    if (!safe_x) {
        return;
    }

    bool safe_y = false;
    int y = ui->yCoord->text().toInt(&safe_y);
    if (!safe_y) {
        return;
    }

    int x_adj = x + (ui->plotGraphicsView->frameSize().width() / 2) - Point::get_width()/2;
    int y_adj = (-1 * y + (ui->plotGraphicsView->frameSize().height() / 2))- Point::get_width()/2;
    QColor color2 (255,255,255);
    Point *p = new Point(color2,x_adj,y_adj);
    scene->addItem(p);
    connect(p, &Point::PointSelected, this, &PlotWindow::PointSelectedSlot);

}

void PlotWindow::PointSelectedSlot(int x, int y)
{
    qDebug() << x << "," << y;
}
