#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setTabText(0, tr("Résumé"));
    ui->tabWidget->setTabText(1, tr("Informations"));
    ui->tabWidget->setTabText(2, tr("Contacts"));
    ui->tabWidget->setTabText(3, tr("Notes"));
    ui->tabWidget->setTabText(4, tr("Historique des ventes"));
    ui->tabWidget->setTabText(5, tr("Parc machine"));
    ui->tabWidget->setTabText(6, tr("Activités"));
    ui->sous_parc_instru->setTabText(0, tr("Instruments hématologie"));
    ui->sous_parc_instru->setTabText(1, tr("Instruments biochimie"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


// PERMET DE FAIRE SE CONNECTER PLUSIEURS SCROLL BARS ENTRE ELLES
//self.tableWidget.verticalScrollBar().valueChanged.connect(self.table_scrolled)
// self.tableWidget_2.verticalScrollBar().valueChanged.connect(self.table_2_scrolled)
// QtCore.QMetaObject.connectSlotsByName(MainWindow)


//def table_scrolled(self, value):
// self.tableWidget_2.verticalScrollBar().setValue(value)

//def table_2_scrolled(self, value):
// self.tableWidget.verticalScrollBar().setValue(value)
