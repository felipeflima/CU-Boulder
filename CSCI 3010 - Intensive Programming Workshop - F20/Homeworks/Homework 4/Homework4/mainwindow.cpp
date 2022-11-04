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
    QColor live(255,0,155);
    QColor dead(0,0,0);
    liveW_ = live;
    deadW_ = dead;

    playing_ = 0;
    speed_ = 0;
    turn_ = 0;

    QSlider *speedSlider = ui->speedSlider;
    connect(ui->playButton, SIGNAL(clicked()), this, SLOT(playGame()));
    connect(ui->stepButton, SIGNAL(clicked()), this, SLOT(stepGame()));
    connect(ui->pauseButton, SIGNAL(clicked()), this, SLOT(pauseGame()));
    connect(ui->comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(LoadGameSlot(QString)));
    connect(speedSlider, SIGNAL(valueChanged(int)), this, SLOT(SliderSlot(int)));
    connect(ui->colorButton, SIGNAL(clicked()), this, SLOT(selectMasterColor()));
    connect(timer, SIGNAL(timeout()), this, SLOT(gamePlaying()));
    timer->start(1000);

    QGraphicsView * view = ui->graphicsView;
    view->setScene(scene);

    view->setSceneRect(0,0,view->size().width()-2,view->size().height()-2);

    // adds the cells in the 2d array in the scene
    Position pos = {0,0};
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 35; j++){
            pos = {i,j};
            scene->addItem(game->get_cell(pos));
            game->num_neighbors(game->get_cell(pos));
//            connect(game->get_cell(pos), &Cell::CellSelected, this, &MainWindow::ChangeColor);
            connect(game->get_cell(pos), &Cell::CellSelected, this, &MainWindow::CellLeftClickedSlot);
            connect(game->get_cell(pos), &Cell::CellRightClicked, this, &MainWindow::CellRightClickedSlot);
        }
    }

    //updates population label
    populationW_ = game->get_population();
    std::string p = "Population: " + std::to_string(populationW_) + " (";
    QString qp(p.c_str());
    ui->population->setText(qp + QString::number((populationW_/525.0)*100, 'g', 3) + "%)");


    scene->addItem(game->get_graph()); //adds graph to view
    scene->addItem(game->get_bar(0)); // adds first bar to view

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * if the play button is clicked a bool variable is turned to true
*/
void MainWindow::playGame(){
    playing_ = 1;
}

/*
 * while the variable playing is true, call step game
*/
void MainWindow::gamePlaying(){
    if (playing_ == 1){
        stepGame();
        update();
    }
}

/*
 * changes color (status) of the cell to the opposite of the current one
*/
void MainWindow::ChangeColor(Cell * c){
    c->ChangeCellStatus();
    game->num_neighbors(c);
    if (c->get_status() == liveW_){
        game->set_population(game->get_population()+1);
    }
    else if (c->get_status() == deadW_){
        game->set_population(game->get_population()-1);
    }
    //updates population
    populationW_ = game->get_population();
    std::string p = "Population: " + std::to_string(populationW_) + " (";
    QString qp(p.c_str());
    ui->population->setText(qp + QString::number((populationW_/525.0)*100, 'g', 3) + "%)");
}

void MainWindow::CellLeftClickedSlot(Cell * c){
    if(c->get_status() == deadW_){
        c->SetCellStatus(liveW_);
        game->num_neighbors(c);
        game->set_population(game->get_population()+1);
        //updates population label
        populationW_ = game->get_population();
        std::string p = "Population: " + std::to_string(populationW_) + " (";
        QString qp(p.c_str());
        ui->population->setText(qp + QString::number((populationW_/525.0)*100, 'g', 3) + "%)");
    }
}

/*
 * handles right click on cell. set it's status to dead.
*/
void MainWindow::CellRightClickedSlot(Cell * c){
    if(c->get_status() == liveW_){
        c->SetCellStatus(deadW_);
        game->num_neighbors(c);
        game->set_population(game->get_population()-1);
        //updates population label
        populationW_ = game->get_population();
        std::string p = "Population: " + std::to_string(populationW_) + " (";
        QString qp(p.c_str());
        ui->population->setText(qp + QString::number((populationW_/525.0)*100, 'g', 3) + "%)");
    }
}

/*
 * handles the step button and the calling for the next turn
*/
void MainWindow::stepGame(){
    turn_++;
    game->turn();
    QColor test(0,0,255);

    //updates turn label
    std::string t = "Turn: " + std::to_string(turn_);
    QString qt(t.c_str());
    ui->turn->setText(qt);

    //updates population label
    populationW_ = game->get_population();
    std::string p = "Population: " + std::to_string(populationW_) + " (";
    QString qp(p.c_str());
    ui->population->setText(qp + QString::number((populationW_/525.0)*100, 'g', 3) + "%)");

    // if the bars can still fit in the graph add another one to the graph
    if (game->get_vec_size() <= 35){
           scene->addItem(game->get_bar(game->get_vec_size()-1));
    }
}

/*
 * changes the playing varible to 0 so the call to stepGame stops
*/
void MainWindow::pauseGame(){
    playing_ = 0;
}

/*
 * handles the value form the slider into the timer to call step
*/
void MainWindow::SliderSlot(int value){
    std::string p = "Speed: " + std::to_string(value+1);
    QString qp(p.c_str());
    ui->speedLabel->setText(qp);
    speed_ = 100 - value;
    timer->start(speed_ * 10);
}

/*
 * Loads a different game pattern to the grid
*/
void MainWindow::LoadGameSlot(QString s){
    Position pos = {0,0};
    turn_ = 0;
    std::string t = "Turn: " + std::to_string(turn_);
    QString qt(t.c_str());
    ui->turn->setText(qt);
    if (s == "Random"){
        int chance = 0;
        for(int i = 0; i < 15; i++){
            for(int j = 0; j < 35; j++){
                pos = {i,j};
                chance = rand() % 100;
                if (chance < 50){
                    game->get_cell(pos)->SetCellStatus(liveW_);
                    populationW_++;
                }
                else{
                   game->get_cell(pos)->SetCellStatus(deadW_);
                }
            }
        }
        game->set_population(populationW_);
        populationW_ = game->get_population();
        std::string p = "Population: " + std::to_string(populationW_) + " (";
        QString qp(p.c_str());
        ui->population->setText(qp + QString::number((populationW_/525.0)*100, 'g', 3) + "%)");
    }
    else if (s != "Random"){
        Position pos = {0,0};
        for(int i = 0; i < 15; i++){
            for(int j = 0; j < 35; j++){
                pos = {i,j};
                game->get_cell(pos)->SetCellStatus(deadW_);
            }
        }

        if (s == "Tumbler"){
            pos = { 10 , 16 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 10 , 15 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 9 , 15 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 10 , 18 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 10 , 19 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 9 , 19 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 8 , 18 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 8 , 16 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 7 , 19 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 6 , 20 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 7 , 21 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 8 , 21 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 7 , 15 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 6 , 14 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 7 , 13 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 8 , 13 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            game->set_population(16);
            populationW_ = game->get_population();
            std::string p = "Population: " + std::to_string(populationW_) + " (";
            QString qp(p.c_str());
            ui->population->setText(qp + QString::number((populationW_/525.0)*100, 'g', 3) + "%)");
        }
        else if (s == "Glider"){
            pos = { 7 , 17 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 8 , 18 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 9 , 18 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 9 , 17 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 9 , 16 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            game->set_population(16);
            populationW_ = game->get_population();
            std::string p = "Population: " + std::to_string(populationW_) + " (";
            QString qp(p.c_str());
            ui->population->setText(qp + QString::number((populationW_/525.0)*100, 'g', 3) + "%)");
        }
        else if (s == "Star"){
            pos = { 13 , 17 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 12 , 17 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 12 , 16 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 12 , 18 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 11 , 18 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 11 , 19 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 11 , 20 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 10 , 20 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 9 , 20 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 9 , 21 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 8 , 21 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 8 , 22 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 11 , 16 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 11 , 15 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 11 , 14 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 10 , 14 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 9 , 14 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 9 , 13 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 8 , 13 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 8 , 12 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 7 , 13 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 7 , 14 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 6 , 14 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 5 , 14 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 5 , 15 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 5 , 16 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 4 , 16 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 4 , 17 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 4 , 18 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 3 , 17 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 5 , 18 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 5 , 19 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 5 , 20 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 6 , 20 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 7 , 20 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            pos = { 7 , 21 };
            game->get_cell(pos)->SetCellStatus(liveW_);
            game->set_population(16);
            populationW_ = game->get_population();
            std::string p = "Population: " + std::to_string(populationW_) + " (";
            QString qp(p.c_str());
            ui->population->setText(qp + QString::number((populationW_/525.0)*100, 'g', 3) + "%)");
        }
    }
}

/*
 * Function handles user input for color
*/
void MainWindow::selectMasterColor()
{
    QColor color = QColorDialog::getColor(liveW_, this, tr("Select color of figures"));
    if(!color.isValid())
        return;
    Position pos = {0,0};
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 35; j++){
            pos = {i,j};
            if(game->get_cell(pos)->get_status() == liveW_){
                game->get_cell(pos)->SetCellStatus(color);
            }
        }
    }
    liveW_ = color;
    game->setMasterColor(liveW_);
    update();
}

