#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QTimer"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *zamanlayici = new QTimer(this);
    connect(zamanlayici,SIGNAL(timeout()),this,SLOT(degistir()));
    zamanlayici->start(500);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
     yenibuttonlabel *buton=new yenibuttonlabel(this);
    buton->setGeometry(event->x(),event->y(),100,50);
    buton->show();
    butonlar.push_back(buton);//butonun adrsini tutuyor
    buton->setText(QString::number((butonlar.size())));
    ui->statusbar->showMessage("X = " + QString::number(event->x()) +
                               " Y = " + QString::number(event->y()));
    buton->setStyleSheet("background-color: white");
}



void MainWindow::degistir()
{
    int sayisi = butonlar.size();
    for (int i = 0; i < sayisi; ++i) {
        if(butonlar[i]->tiklandimi) {
            butonlar[i]->setGeometry(butonlar[i]->x() + 10,
                                 butonlar[i]->y(),
                                 butonlar[i]->width(),
                                 butonlar[i]->height());
        }
    }
}

void MainWindow::on_cmbBox_Renk_currentTextChanged(const QString &arg1)
{
    QString yazi="Seçtiğiniz Renk ...:"+arg1;
    this->setStyleSheet("background-color: "+arg1);
}
