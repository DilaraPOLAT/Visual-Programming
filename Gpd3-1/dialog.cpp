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


void Dialog::on_btnGonder_clicked()
{
   QMessageBox::information(this,"Hosgeldiniz"," Merhaba "+ui->edtIsim->text(),"Tamam") ;
}
