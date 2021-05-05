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

int sayi;
int aralik;


void Dialog::on_spinBox_valueChanged(int arg1)
{

    ui->label_4->setText("0 ile " +QString::number(arg1)+" sayıları arasında sayı tahmin oyunu başlıyor...");
}

void Dialog::on_radioButtonTO_clicked()
{
    ui->listWidget_oyuncu1->setEnabled(true);
    ui->listWidget_oyuncu2->setEnabled(false);
}

void Dialog::on_radioButtonIO_clicked()
{
     ui->listWidget_oyuncu2->setEnabled(true);
     ui->listWidget_oyuncu1->setEnabled(true);
}

void Dialog::on_pushButtonRastgeleSay_clicked()
{

    aralik=ui->spinBox->value();
    sayi=rand()%(0-aralik);
    qDebug()<<sayi;
    ui->label_5->setText("Üretilen Sayı:"+QString::number(sayi));

}

void Dialog::on_pushButtonYarsBasla_clicked()
{
 int ilkds=0;
 int ikids=0;

   if(ui->radioButtonTO->isChecked())
    {
       while(true)
       {
        int tahmin=rand()%(0-aralik);
        ilkds++;

        if(sayi!=tahmin)
        {

            ui->listWidget_oyuncu1->addItem(QString::number(tahmin));
        }
        else
        {
            ui->listWidget_oyuncu1->addItem(QString::number(tahmin));
            ui->listWidget_oyuncu1->addItem("Deneme Sayısı:"+QString::number(ilkds));
            QMessageBox::information(this,"Tebrikler!!!","Tebrikler Oyuncu 1 ,"+QString::number(ilkds)+" denemede KAZANDINIZ!!!");
            break;
        }
       }
    }

  else  if(ui->radioButtonIO->isChecked())
    {

        while(true)
        {
            int tahmin1=rand()%(0-aralik);
            ilkds++;
            if(sayi!=tahmin1)
            {
                ui->listWidget_oyuncu1->addItem(QString::number(tahmin1));
            }

            else
            {
                ui->listWidget_oyuncu1->addItem(QString::number(tahmin1));
                ui->listWidget_oyuncu1->addItem("Deneme Sayısı:"+QString::number(ilkds));
                break;
            }
        }

        while(true)
        {
            int tahmin2=rand()%(0-aralik);
            ikids++;
            if(sayi!=tahmin2)
            {
                ui->listWidget_oyuncu2->addItem(QString::number(tahmin2));
            }
            else
            {
                ui->listWidget_oyuncu2->addItem(QString::number(tahmin2));
                ui->listWidget_oyuncu2->addItem("Deneme Sayısı:"+QString::number(ikids));
                break;
            }
        }

            if(ilkds<ikids)
            {
                QMessageBox::information(this,"Tebrikler!!!","Tebrikler Oyuncu 1 ,"+QString::number(ilkds)+" denemede KAZANDINIZ!!!");
            }
            else if(ilkds>ikids)
            {
                QMessageBox::information(this,"Tebrikler!!!","Tebrikler Oyuncu 2 ,"+QString::number(ikids)+" denemede KAZANDINIZ!!!");
            }
            else
            {
               QMessageBox::information(this,"Tebrikler!!!","Tebrikler  ,"+QString::number(ilkds)+" denemede BERABERE KALDINIZ!!!");
            }
    }

}






