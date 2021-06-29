#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

int sayac3=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *zamanlayici = new QTimer(this);
    connect(zamanlayici,SIGNAL(timeout()),this,SLOT(degistir()));
    zamanlayici->start(15);
    QTimer *zamanlayici1 = new QTimer(this);
    connect(zamanlayici1,SIGNAL(timeout()),this,SLOT(degistir1()));
    zamanlayici1->start(1800);
    QTimer *zamanlayici3 = new QTimer(this);
    connect(zamanlayici3,SIGNAL(timeout()),this,SLOT(kapat()));
    zamanlayici3->start(1000);
    //ui->label_suredeger->setText(QString::number(zamanlayici1->timerId()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::degistir()
{
   int sayac=0,sayac1=0;
   int sayisi = butonlar.size();
   for (int i = 0; i < sayisi; ++i) {
    if(butonlar[i]->tiklandimi)
    {
      butonlar[i]->setStyleSheet( "border-image: url(:/patlatma/images/patlama.jpg)");
      sayac++;
      ui->label_vurulandeger->setText(QString::number(sayac));
    }
    if(butonlar[i]->y()>=800 && butonlar[i]->tiklandimi==false)
    {
       sayac1++;
       ui->label_kacandeger->setText(QString::number(sayac1));
    }
   }
   for (int i = 0; i < sayisi; ++i) {
           butonlar[i]->setGeometry(butonlar[i]->x() ,butonlar[i]->y()+1, butonlar[i]->width(), butonlar[i]->height());
   }
}

void MainWindow::degistir1()
{
        int sayi,sayi1;
        sayi=rand()%(0-7);
        sayi1=rand()%(0-30);
        yeniButon *buton = new yeniButon(this);
        buton->setGeometry(sayi1*49.5,82,50,50);
        buton->show();
        butonlar.push_back(buton);//butonun adrsini tutuyor
        buton->setStyleSheet( "border-image: url(:/balon/images/"+ QString::number(sayi)+ ".jpg)");
}
void MainWindow::kapat()
{
  sayac3++;
  ui->label_suredeger->setText(QString::number(sayac3));
}
