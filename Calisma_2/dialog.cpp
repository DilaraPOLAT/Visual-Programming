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




void Dialog::on_btnSorgula_clicked()
{

    QString sifre="123";
    QString e_posta="polatdilarasevim@gmail.com";

    int a=QString::compare(ui->lnEd_Sifre->text(),sifre,Qt::CaseInsensitive);
    int b=QString::compare(ui->lnEd_Eposta->text(),e_posta,Qt::CaseInsensitive);
    if(a==0&&b==0)
    {
        QMessageBox::information(this,"Giriş ","Başarılı Giriş");
    }
    else
       QMessageBox::information(this,"Giriş ","Başarısız Giriş");
}
