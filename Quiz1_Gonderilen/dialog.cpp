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

    ui->label_4->setText("0 ile " +QString::number(arg1)+"sayıları arasında sayı tahmin oyunu başlıyor.");
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

    while(ui->radioButtonTO->isChecked())
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
            ui->listWidget_oyuncu1->addItem("Doğru Tahmin:"+QString::number(ilkds));
            break;
        }
    }
    while(ui->radioButtonIO->isChecked())
    {

        int tahmin=rand()%(0-aralik);
        ikids++;

        if(sayi!=tahmin)
        {

            ui->listWidget_oyuncu2->addItem(QString::number(tahmin));

        }
        else
        {
            ui->listWidget_oyuncu2->addItem(QString::number(tahmin));
            ui->listWidget_oyuncu2->addItem("Doğru Tahmin:"+QString::number(ikids));
            if(ikids>ilkds)
            {
                QMessageBox::information(this,"Kazanan","Oyuncu1");
            }
            else
            {
                  QMessageBox::information(this,"Kazanan","Oyuncu2");
            }
            break;
        }
    }


}






