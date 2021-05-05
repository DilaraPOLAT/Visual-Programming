#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnCheckable_clicked()
{
    qDebug()<<"Tiklandi mi :"<<ui->btnCheckable->isChecked();
}

void Dialog::on_btnIsCheck_clicked()
{
  QString mesaj;
  if(ui->btnCheckable->isChecked())
  {
      mesaj="EVET tiklandi";
  }
  else
  {
      mesaj="HAYİR tiklanmadi";
  }
  QMessageBox::information(this,"Durum",mesaj);
}

void Dialog::on_btnAutoRepeat_clicked()
{
    qInfo()<<"Buton basili durumda";

}

void Dialog::on_btnToggleAutoRepeat_clicked()
{
    bool durum = !ui->btnAutoRepeat->autoRepeat();
    ui->btnAutoRepeat->setAutoRepeat(durum);
    qDebug()<<"AutoRepeat buton durumu:"<<ui->btnAutoRepeat->autoRepeat();

}

void Dialog::on_btnDefault_clicked()
{
  QMessageBox::information(this,"Durum","Default Klavyeden Tıklandı");
}

void Dialog::on_btnToggleDefault_clicked()
{

}
