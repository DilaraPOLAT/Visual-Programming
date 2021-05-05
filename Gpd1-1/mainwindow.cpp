#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnCevap_clicked()
{
    QString cevap = "Verilen cevap";
    if (ui->rdBenzin->isChecked())
        cevap+="\n"+ui->rdBenzin->text();
    if (ui->rdDizel->isChecked())
        cevap+="\n"+ui->rdDizel->text();
    ui->txtCevap->setPlainText(cevap);
}








