#include "mainwindow.h"

#include <QApplication>

#include "calc.h"

#include "cstmstyle.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CALC calc;
    a.setStyle(new cstmStyle);
    calc.show();
    return a.exec();
}
