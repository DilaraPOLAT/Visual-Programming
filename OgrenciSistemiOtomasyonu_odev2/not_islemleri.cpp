#include "not_islemleri.h"
#include "ui_not_islemleri.h"

Not_islemleri::Not_islemleri(QSqlDatabase db,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Not_islemleri)
{
    ui->setupUi(this);
    sorgu=new QSqlQuery(db);
    listele();
    listele2();
}

Not_islemleri::~Not_islemleri()
{
    delete ui;
}

void Not_islemleri::on_btn_DersKE_clicked()
{
    if(ui->lnedt_FinalNotu->text().isEmpty() ||ui->lnedt_DersKodu->text().isEmpty()||ui->lnedt_VizeNotu->text().isEmpty()||ui->lnedt_FinalNotu->text().isEmpty())
    {
        QMessageBox::information(this,"HATA!","Gerekli Alanları Doldurunuz!");
    }
    else
    {
        QSqlQuery qry;
        qry.prepare("SELECT ders_kodu FROM notlar WHERE ders_kodu  = ? AND ogr_no =? ;");
        qry.addBindValue(ui->lnedt_DersKodu->text().toInt());
        qry.addBindValue(ui->lnedt_ogrNo->text().toInt());
        qry.exec();
        int sayac=0;
        while(qry.next())
        {
            sayac++;
        }
        if(sayac==1)
        {
            QMessageBox::critical(this,"HATA","Bu öğrenci üzerinde bu ders zaten tanımlı!");
        }
        else{
            int gcm_notu=(ui->lnedt_VizeNotu->text().toInt()*0.4) + (ui->lnedt_FinalNotu->text().toInt()*0.6);
            sorgu->prepare("INSERT INTO notlar(ogr_no,ders_kodu,vize_not,final_not, gecme_notu)VALUES(?,?,?,?,?)");
            sorgu->addBindValue(ui->lnedt_ogrNo->text().toInt());
            sorgu->addBindValue(ui->lnedt_DersKodu->text().toInt());
            sorgu->addBindValue(ui->lnedt_VizeNotu->text().toInt());
            sorgu->addBindValue(ui->lnedt_FinalNotu->text().toInt());
            sorgu->addBindValue(gcm_notu);
            if(!sorgu->exec())
            {
                QMessageBox::critical(this,"HATA",sorgu->lastError().text());
            }

             model = new QSqlQueryModel();
            if(sorgu->exec("SELECT *FROM notlar"))
            {
                model->setQuery(*sorgu);
                ui->tbvTumOgrDers->setModel(model);
            }
            else
            {
              qDebug()<< sorgu->lastError();
            }
            }
        }
}

void Not_islemleri::listele()
{
    model1 = new QSqlQueryModel();
   if(sorgu->exec("SELECT *FROM ogrenci"))
   {
       model1->setQuery(*sorgu);
       ui->tbvTumOgr->setModel(model1);
   }
   else
   {
     qDebug()<< sorgu->lastError();
   }
}
void Not_islemleri::listele2()
{
    model2 = new QSqlQueryModel();
    if(sorgu->exec("SELECT *FROM dersler"))
    {
        model2->setQuery(*sorgu);
        ui->tbvTumDers->setModel(model2);
    }
    else
    {
      qDebug()<< sorgu->lastError();
    }
}

void Not_islemleri::on_tbvTumOgr_clicked(const QModelIndex &index)
{
  ui->lnedt_ogrNo->setText(model1->index(index.row(),0).data().toString());
}

void Not_islemleri::on_tbvTumDers_clicked(const QModelIndex &index)
{
    ui->lnedt_DersKodu->setText(model2->index(index.row(),0).data().toString());
}
