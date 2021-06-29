#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ogrenci_islemleri.h"
#include "ders_islemleri.h"
#include "not_islemleri.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db.setDatabaseName("C:/Qt/GorselProg/Odev_2/SQL_Odev2.db");
    if(!db.open())
    {
        ui->statusbar->showMessage("Veri tabanına bağlanılamadı!");
    }
    else
    {
        ui->statusbar->showMessage("Veri tabanına bağlanıldı!");
    }


}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_btn_ogrenci_clicked()
{
   ogrenci_islemleri *ogr = new ogrenci_islemleri(db);
    ogr->show();
}

void MainWindow::on_btn_ders_clicked()
{
  Ders_islemleri *drs = new Ders_islemleri(db);
  drs->show();
}

void MainWindow::on_btn_not_clicked()
{
  Not_islemleri *nt = new Not_islemleri(db);
  nt->show();
}
