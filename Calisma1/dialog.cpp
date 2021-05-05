#include "dialog.h"
#include "ui_dialog.h"
#include"QMessageBox"


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


void Dialog::on_btnSonuc_clicked()
{
  int deger1 = ui->spbxSayi1->value();
  int deger2 = ui->spbxSayi2->value();
  QString islem = ui->cmbIslem->currentText();
  int sonuc;
  if(islem=="+")
  {
      sonuc=deger1+deger2;
  }
  else if(islem=="-")
  {
      sonuc=deger1-deger2;
  }
  else if(islem=="*")
  {
      sonuc=deger1*deger2;
  }
 else
  {
      sonuc=deger1/deger2;
  }
  ui->textEditSonuc->setText(QString::number(sonuc));

}

void Dialog::on_btnTemizle_clicked()
{
   ui->textEditSonuc->clear();
}








