#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->btnConnect, &QPushButton::clicked, this, &Dialog::yazDbg);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_2_clicked()
{
    qDebug() << "yazDbg ile butonun zamani yazdiracagim";
    yazDbg();
}

void Dialog::yazDbg()
{
    qInfo()<<"Buton tıklanma zamanı: "<<QDateTime::currentDateTime().toString();//QInfo cout gibi
    accept();//pencereyi kapatır
}


