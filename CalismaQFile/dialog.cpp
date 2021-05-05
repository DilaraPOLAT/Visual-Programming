#include "dialog.h"
#include "ui_dialog.h"

int sayac1=0;
int sayac2=0;
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QFile my_file("Bilgiler.txt");
    if(!my_file.exists())
    {
        QMessageBox::information(this,"UYARI",my_file.errorString());
        return;
    }
    if(!my_file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this,"UYARI",my_file.errorString());
        return;
    }
        QTextStream stream(&my_file);
        while(!stream.atEnd())
        {
           ui->listWBilgiler->addItem(stream.readLine());
        }
        my_file.close();



      QFile my_file1("Saglikli.txt");
      if(!my_file1.exists())
      {
          QMessageBox::information(this,"UYARI",my_file1.errorString());
          return;
      }
      if(!my_file1.open(QIODevice::ReadOnly))
      {
          QMessageBox::information(this,"UYARI",my_file1.errorString());
          return;
      }
          QTextStream stream1(&my_file1);
          while(!stream1.atEnd())
          {
             ui->listWSaglik->addItem(stream1.readLine());
             sayac1++;
          }
          my_file1.close();


          QFile my_file2("Hastalikli.txt");
          if(!my_file2.exists())
          {
              QMessageBox::information(this,"UYARI",my_file2.errorString());
              return;
          }
          if(!my_file2.open(QIODevice::ReadOnly))
          {
              QMessageBox::information(this,"UYARI",my_file2.errorString());
              return;
          }
              QTextStream stream2(&my_file2);
              while(!stream2.atEnd())
              {
                 ui->listW_Kilo->addItem(stream2.readLine());
                 sayac2++;
              }
              my_file2.close();

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnHesapla_clicked()
{
   QFile my_file("Bilgiler.txt");

  if(!my_file.open(QIODevice::WriteOnly|QIODevice::Append))
   {
       QMessageBox::information(this,"UYARI",my_file.errorString());
       return;
   }
  double hesapla;
  hesapla=ui->ln_Kilo->text().toDouble()/(ui->ln_Boy->text().toDouble()*ui->ln_Boy->text().toDouble());
   ui->listWBilgiler->addItem(ui->ln_Ad->text()+" "+ui->ln_Soyad->text()+" "+"Kilo:"+QString::number(ui->ln_Kilo->text().toDouble())+" "+"Yaş:"+QString::number(ui->ln_Yas->text().toInt())+" "+"Boy:"+QString::number(ui->ln_Boy->text().toDouble())+" "+"Vücut Kitle indexsi:"+QString::number(hesapla)+"\n ");
   QTextStream stream(&my_file);
   stream<<ui->ln_Ad->text()+" "+ui->ln_Soyad->text()+" "+"Kilo:"+QString::number(ui->ln_Kilo->text().toDouble())+" "+"Yaş:"+QString::number(ui->ln_Yas->text().toInt())+" "+"Boy:"+QString::number(ui->ln_Boy->text().toDouble())+" "+"Vücut Kitle indexsi:"+QString::number(hesapla)+"\n ";
   my_file.close();
   if(25>hesapla && hesapla>18)
   {
         sayac1++;
       QFile my_file1("Saglikli.txt");

      if(!my_file1.open(QIODevice::WriteOnly|QIODevice::Append))
       {
           QMessageBox::information(this,"UYARI",my_file1.errorString());
           return;
       }
      ui->listWSaglik->addItem(ui->ln_Ad->text()+" "+ui->ln_Soyad->text()+" "+"Kilo:"+QString::number(ui->ln_Kilo->text().toDouble())+" "+"Yaş:"+QString::number(ui->ln_Yas->text().toInt())+" "+"Boy:"+QString::number(ui->ln_Boy->text().toDouble())+" "+"Vücut Kitle indexsi:"+QString::number(hesapla)+"\n ");
       QTextStream stream1(&my_file1);
       stream1<<ui->ln_Ad->text()+" "+ui->ln_Soyad->text()+" "+"Kilo:"+QString::number(ui->ln_Kilo->text().toDouble())+" "+"Yaş:"+QString::number(ui->ln_Yas->text().toInt())+" "+"Boy:"+QString::number(ui->ln_Boy->text().toDouble())+" "+"Vücut Kitle indexsi:"+QString::number(hesapla)+"\n ";
      my_file1.close();
   }
   else
   {
         sayac2++;
       QFile my_file2("Hastalikli.txt");

      if(!my_file2.open(QIODevice::WriteOnly|QIODevice::Append))
       {
           QMessageBox::information(this,"UYARI",my_file2.errorString());
           return;
       }
        ui->listW_Kilo->addItem(ui->ln_Ad->text()+" "+ui->ln_Soyad->text()+" "+"Kilo:"+QString::number(ui->ln_Kilo->text().toDouble())+" "+"Yaş:"+QString::number(ui->ln_Yas->text().toInt())+" "+"Boy:"+QString::number(ui->ln_Boy->text().toDouble())+" "+"Vücut Kitle indexsi:"+QString::number(hesapla)+"\n ");
        QTextStream stream2(&my_file2);
        stream2<<ui->ln_Ad->text()+" "+ui->ln_Soyad->text()+" "+"Kilo:"+QString::number(ui->ln_Kilo->text().toDouble())+" "+"Yaş:"+QString::number(ui->ln_Yas->text().toInt())+" "+"Boy:"+QString::number(ui->ln_Boy->text().toDouble())+" "+"Vücut Kitle indexsi:"+QString::number(hesapla)+"\n ";
     my_file2.close();
   }

}

void Dialog::on_rdioKiloSay_clicked()
{
   ui->ln_Sayac->setText("Hasta Sayısı:"+QString::number(sayac2));
}

void Dialog::on_rdioSaglikSay_clicked()
{
  ui->ln_Sayac->setText("Sağlıklı Sayısı:"+QString::number(sayac1));
}
