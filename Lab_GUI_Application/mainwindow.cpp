#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->yazi_alani->setText("Merhaba Qt!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

