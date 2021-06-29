#include "ders_islemleri.h"
#include "ui_ders_islemleri.h"

Ders_islemleri::Ders_islemleri(QSqlDatabase db,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ders_islemleri)
{
    ui->setupUi(this);
    sorgu=new QSqlQuery(db);
    listele();
}

Ders_islemleri::~Ders_islemleri()
{
    delete ui;
}

void Ders_islemleri::on_btn_yeniKayit_clicked()
{
    sorgu->prepare("INSERT INTO dersler(ders_kodu, ders_adi)VALUES(?,?)");
    if(ui->lnedt_DersAdi->text().isEmpty() ||ui->lnedt_DersKodu->text().isEmpty())
    {
        QMessageBox::information(this,"HATA!","Gerekli Alanları Doldurunuz!");
    }
    else
    {
        QSqlQuery qry;
        qry.prepare("SELECT ders_kodu FROM dersler WHERE ders_kodu  = ? ;");
        qry.addBindValue(ui->lnedt_DersKodu->text().toInt());
        qry.exec();
        int sayac=0;
        while(qry.next())
        {
            sayac++;
        }
        if(sayac==1)
        {
            QMessageBox::critical(this,"HATA","Bu kodda başka bir ders vardır.Farklı kodda ders ekleyiniz.");
        }
        else{
            sorgu->addBindValue(ui->lnedt_DersKodu->text().toInt());
            sorgu->addBindValue(ui->lnedt_DersAdi->text());
            if(!sorgu->exec())
            {
                QMessageBox::critical(this,"HATA",sorgu->lastError().text());
            }
        }

    }
}


void Ders_islemleri::on_btn_Guncelle_clicked()
{
    listele();
}

void Ders_islemleri::on_btn_Sil_clicked()
{
    QSqlQuery qry;
    qry.prepare("SELECT ders_kodu FROM dersler WHERE ders_kodu  = ? ;");
    qry.addBindValue(ui->lnedt_DersKodu->text().toInt());
    qry.exec();
    int sayac=0;
    while(qry.next())
    {
        sayac++;
    }
    if(sayac==1)
    {
        QMessageBox::critical(this,"HATA","Bu ders silinemez.Bu derse kayıtlı öğrenciler vardır.");
    }
    else{
    sorgu->prepare("delete from dersler WHERE ders_kodu =?");
    sorgu->addBindValue(ui->lnedt_DersKodu->text().toInt());
    if(!sorgu->exec())
    {
        QMessageBox::critical(this,"HATA",sorgu->lastError().text());
    }
    }
}
void Ders_islemleri::listele()
{
    model = new QSqlQueryModel();
    if(sorgu->exec("SELECT *FROM dersler"))
    {
        model->setQuery(*sorgu);
        ui->tbv_Tum->setModel(model);
    }
    else
    {
      qDebug()<< sorgu->lastError();
    }
}

void Ders_islemleri::on_tbv_Tum_clicked(const QModelIndex &index)
{

    ui->lnedt_DersKodu->setText(model->index(index.row(),0).data().toString());
    ui->lnedt_DersAdi->setText(model->index(index.row(),1).data().toString());
    QSqlQuery qry;
    qry.prepare("SELECT  ogr_no , ders_kodu  , vize_not , final_not , gecme_notu FROM notlar WHERE ders_kodu  = ? ;");
    qry.addBindValue(ui->lnedt_DersKodu->text().toInt());
    qry.exec();

    while(qry.next())
    {
        model1 = new QSqlQueryModel();
        model1->setQuery(qry);
        ui->tbv_Secilen->setModel(model1);
    }







}
