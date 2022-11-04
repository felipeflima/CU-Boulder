#include "plotwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    PlotWindow w;
    w.show();

    return a.exec();
}
