#include "ogrenci_islemleri.h"
#include "ui_ogrenci_islemleri.h"
#include "QMessageBox"
ogrenci_islemleri::ogrenci_islemleri(QSqlDatabase db,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ogrenci_islemleri)
{
    ui->setupUi(this);
    sorgu=new QSqlQuery(db);
    listele();
}

ogrenci_islemleri::~ogrenci_islemleri()
{
    delete ui;
}

void ogrenci_islemleri::on_btn_yeniKayit_clicked()
{
    sorgu->prepare("INSERT INTO ogrenci(ogr_no,ogr_ad,ogr_soyad)VALUES(?,?,?)");
    int numara=1;
    while(true)
    {
        QSqlQuery qry;
        qry.prepare("SELECT ogr_no FROM ogrenci WHERE ogr_no  = ? ;");
        qry.addBindValue(numara);
        qry.exec();
        int sayac=0;
        while(qry.next())
        {
            sayac++;
        }
        if(sayac!=0)
        {
          numara++;
        }
        else
        {
                sorgu->addBindValue(numara);
                break;
        }
    }
    if(ui->lnedt_ogrAd->text().isEmpty() ||ui->lnedt_ogrSoyad->text().isEmpty())
    {
        QMessageBox::information(this,"HATA!","Gerekli Alanları Doldurunuz!");
    }
    else
    {
        sorgu->addBindValue(ui->lnedt_ogrAd->text());
        sorgu->addBindValue(ui->lnedt_ogrSoyad->text());
        if(!sorgu->exec())
        {
            QMessageBox::critical(this,"HATA",sorgu->lastError().text());
        }
    }
}

void ogrenci_islemleri::on_btn_Sil_clicked()
{
    QSqlQuery qry;
    qry.prepare("SELECT ogr_no FROM notlar WHERE ogr_no  = ? ;");
    qry.addBindValue(ui->lnedt_ogrNo->text().toInt());
    qry.exec();
    int sayac=0;
    while(qry.next())
    {
        sayac++;
    }
    if(sayac!=0)
    {
       QMessageBox::critical(this,"HATA","Bu öğrenci silinemez.Bu öğrencinin üstüne tanımlanmış dersleri vardır!");
    }
    else{
    sorgu->prepare("delete from ogrenci WHERE ogr_no=?");
    sorgu->addBindValue(ui->lnedt_ogrNo->text().toInt());
    if(!sorgu->exec())
    {
        QMessageBox::critical(this,"HATA",sorgu->lastError().text());
    }
    }
}

void ogrenci_islemleri::on_btn_Guncelle_clicked()
{
    listele();
}
void ogrenci_islemleri::listele()
{
    model = new QSqlQueryModel();
    if(sorgu->exec("SELECT *FROM ogrenci"))
    {
        model->setQuery(*sorgu);
        ui->tbv_Tum->setModel(model);
    }
    else
    {
      qDebug()<< sorgu->lastError();
    }
}

void ogrenci_islemleri::on_tbv_Tum_clicked(const QModelIndex &index)
{
     ui->lnedt_ogrNo->setText(model->index(index.row(),0).data().toString());
     ui->lnedt_ogrAd->setText(model->index(index.row(),1).data().toString());
     ui->lnedt_ogrSoyad->setText(model->index(index.row(),2).data().toString());
}
