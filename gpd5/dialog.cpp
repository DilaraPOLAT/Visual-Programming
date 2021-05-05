#include "dialog.h"
#include "ui_dialog.h"
#include"QString"
#include "QMessageBox"
#include"QtDebug"
#include"QSettings"
#include"QVariant"

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



void Dialog::on_cmbRenk_currentIndexChanged(const QString &arg1)
{
    QString yazi="Seçtiğiniz Renk ...:"+arg1;
    ui->lRenk->setText(yazi+" "+arg1);
    this->setStyleSheet("background-color: "+arg1);
}


