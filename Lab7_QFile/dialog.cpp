#include "dialog.h"
#include "ui_dialog.h"
#include "Ogrenci.cpp"

QList<Ogrenci*> ogrler;//global olarak tanımladık cunku her yerde ulasmak icin


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);







    /*QFile my_file("gecenler.txt");
    if(!my_file.exists())//Boyle bir dosya var mı?
    {
        QMessageBox::information(this,"UYARI","Böyle bir dosya bulunmamaktadır!","Tamama");
        return;
    }
    else if(!my_file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this,"UYARI",my_file.errorString(),"Tamam");
        return ;
    }

    QTextStream stream(&my_file);
    while(!stream.atEnd())
    {
       ui->list_Gecenler->addItem(stream.readLine());
    }
    my_file.close();

    QFile my_file2("kalanlar.txt");
    if(!my_file2.exists())//Boyle bir dosya var mı?
    {
        QMessageBox::information(this,"UYARI","Böyle bir dosya bulunmamaktadır!","Tamama");
        return;
    }
    else if(!my_file2.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this,"UYARI",my_file2.errorString(),"Tamam");
        return ;
    }

    QTextStream stream2(&my_file2);
    while(!stream2.atEnd())//satır sonuna kadar
    {
       ui->list_Kalanlar->addItem(stream2.readLine());
    }
    my_file2.close();*/


}

Dialog::~Dialog()
{
    QFile my_file("tumogrenciler.txt");
    if(!my_file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(this,"UYARI",my_file.errorString(),"Tamam");
        return ;
    }
    QTextStream stream(&my_file);
    Ogrenci *ogr;
    foreach(ogr,ogrler)
    {
        stream<< ogr->ad+" "+ogr->soyad+" "+"Geçme Notu:"+ QString::number(ogr->GecmeNotuHesapla(ogr->vize_notu,ogr->final_notu))+"\n";
    }
    my_file.close();

    delete ui;
}


void Dialog::on_btn_Hesapla_clicked()
{
    Ogrenci *ogr=new Ogrenci(ui->ln_Ad->text(),ui->ln_Soyad->text(),ui->ln_Vize->text().toInt(),ui->ln_Final->text().toInt());
    ogrler.append(ogr);
    double gecme_notu=ogr->GecmeNotuHesapla(ogr->vize_notu,ogr->final_notu);
    if(gecme_notu>=60)
    {
     ui->list_Gecenler->addItem(ogr->ad+" "+ogr->soyad+" "+"Geçme Notu :"+QString::number(gecme_notu)+"\n");
     QFile my_file("gecenler.txt");
     if(!my_file.open(QIODevice::WriteOnly |QIODevice::Append))
     {
         QMessageBox::information(this,"UYARI",my_file.errorString(),"Tamam");
         return ;
     }
     QTextStream stream(&my_file);
     stream << ogr->ad+" "+ogr->soyad+" "+"Geçme Notu :"+QString::number(gecme_notu)+"\n";
     my_file.close();
    }
    else
    {
        ui->list_Kalanlar->addItem(ogr->ad+" "+ogr->soyad+" "+"Geçme Notu :"+QString::number(gecme_notu)+"\n");
        QFile my_file("kalanlar.txt");
        if(!my_file.open(QIODevice::WriteOnly|QIODevice::Append))//|QDevice::Append dosyanın sonuna yazıyor silip yazmıyor
        {
            QMessageBox::information(this,"UYARI",my_file.errorString(),"Tamam");
            return;
        }
        QTextStream stream(&my_file);
        stream << ogr->ad+" "+ogr->soyad+" "+"Geçme Notu :"+QString::number(gecme_notu)+"\n";
        my_file.close();
     }











    /*double gecme_notu;
    gecme_notu=(ui->ln_Vize->text().toDouble()*0.4)+(ui->ln_Final->text().toDouble()*0.6);
    if(gecme_notu>=60)
    {
     ui->list_Gecenler->addItem(ui->ln_Ad->text()+" "+ui->ln_Soyad->text()+" "+"Geçme Notu :"+QString::number(gecme_notu)+"\n");
     QFile my_file("gecenler.txt");
     if(!my_file.open(QIODevice::WriteOnly |QIODevice::Append))
     {
         QMessageBox::information(this,"UYARI",my_file.errorString(),"Tamam");
         return ;
     }
     QTextStream stream(&my_file);
     stream << ui->ln_Ad->text()+" "+ui->ln_Soyad->text()+" "+"Geçme Notu :"+QString::number(gecme_notu)+"\n";
     my_file.close();
    }
    else
    {
        ui->list_Kalanlar->addItem(ui->ln_Ad->text()+" "+ui->ln_Soyad->text()+" "+"Geçme Notu :"+QString::number(gecme_notu)+"\n");
        QFile my_file("kalanlar.txt");
        if(!my_file.open(QIODevice::WriteOnly|QIODevice::Append))//|QDevice::Append dosyanın sonuna yazıyor silip yazmıyor
        {
            QMessageBox::information(this,"UYARI",my_file.errorString(),"Tamam");
            return;
        }
        QTextStream stream(&my_file);
        stream << ui->ln_Ad->text()+" "+ui->ln_Soyad->text()+" "+"Geçme Notu :"+QString::number(gecme_notu)+"\n";
        my_file.close();
     }*/

}
