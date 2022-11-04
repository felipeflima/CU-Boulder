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
    scene->addLine(view->frameSize().width()/2, 0, view->frameSize().width()/2, view->frameSize().height());
    scene->addLine(0, view->frameSize().height()/2, view->frameSize().width(), view->frameSize().height()/2);




    // Day 1, Task 5, number 2 here.
    connect(ui->addButton, &QAbstractButton::pressed, this , &PlotWindow::SlotTest);




}

// Day 1, Task 5, number 1 here.



PlotWindow::~PlotWindow()
{
    delete ui;
}

void PlotWindow::on_randomButton_clicked()
{
    qDebug() << "random clicked!";
}

void PlotWindow::SlotTest(){
    qDebug() << "plot Window!";
}
