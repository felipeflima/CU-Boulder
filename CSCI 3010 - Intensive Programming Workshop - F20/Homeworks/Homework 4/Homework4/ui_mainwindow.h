/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *turn;
    QLabel *population;
    QGraphicsView *graphicsView;
    QPushButton *stepButton;
    QPushButton *playButton;
    QPushButton *pauseButton;
    QSlider *speedSlider;
    QLabel *slowerLabel;
    QLabel *fasterLabel;
    QLabel *speedLabel;
    QComboBox *comboBox;
    QPushButton *colorButton;
    QMenuBar *menubar;
    QMenu *menuGame;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 777);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 160, 42));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        turn = new QLabel(verticalLayoutWidget);
        turn->setObjectName(QString::fromUtf8("turn"));

        verticalLayout->addWidget(turn);

        population = new QLabel(verticalLayoutWidget);
        population->setObjectName(QString::fromUtf8("population"));

        verticalLayout->addWidget(population);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 60, 781, 501));
        stepButton = new QPushButton(centralwidget);
        stepButton->setObjectName(QString::fromUtf8("stepButton"));
        stepButton->setGeometry(QRect(10, 621, 71, 31));
        playButton = new QPushButton(centralwidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setGeometry(QRect(80, 620, 71, 31));
        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));
        pauseButton->setGeometry(QRect(150, 620, 71, 31));
        speedSlider = new QSlider(centralwidget);
        speedSlider->setObjectName(QString::fromUtf8("speedSlider"));
        speedSlider->setGeometry(QRect(270, 600, 481, 22));
        speedSlider->setOrientation(Qt::Horizontal);
        slowerLabel = new QLabel(centralwidget);
        slowerLabel->setObjectName(QString::fromUtf8("slowerLabel"));
        slowerLabel->setGeometry(QRect(220, 610, 58, 16));
        fasterLabel = new QLabel(centralwidget);
        fasterLabel->setObjectName(QString::fromUtf8("fasterLabel"));
        fasterLabel->setGeometry(QRect(750, 610, 58, 16));
        speedLabel = new QLabel(centralwidget);
        speedLabel->setObjectName(QString::fromUtf8("speedLabel"));
        speedLabel->setGeometry(QRect(220, 640, 141, 16));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 680, 211, 31));
        colorButton = new QPushButton(centralwidget);
        colorButton->setObjectName(QString::fromUtf8("colorButton"));
        colorButton->setGeometry(QRect(370, 680, 281, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuGame = new QMenu(menubar);
        menuGame->setObjectName(QString::fromUtf8("menuGame"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuGame->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        turn->setText(QApplication::translate("MainWindow", "Turn: 0", nullptr));
        population->setText(QApplication::translate("MainWindow", "Population: ", nullptr));
        stepButton->setText(QApplication::translate("MainWindow", "Step", nullptr));
        playButton->setText(QApplication::translate("MainWindow", "Play", nullptr));
        pauseButton->setText(QApplication::translate("MainWindow", "Pause", nullptr));
        slowerLabel->setText(QApplication::translate("MainWindow", "Slower", nullptr));
        fasterLabel->setText(QApplication::translate("MainWindow", "Faster", nullptr));
        speedLabel->setText(QApplication::translate("MainWindow", "Speed: 0", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "Random", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "Tumbler", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "Glider", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "Star", nullptr));

        colorButton->setText(QApplication::translate("MainWindow", "Set Color", nullptr));
        menuGame->setTitle(QApplication::translate("MainWindow", "Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
