#include <QtGui/QApplication>
#include "mainwindow.h"
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //database   my_database;

    w.show();

   return a.exec();
}
