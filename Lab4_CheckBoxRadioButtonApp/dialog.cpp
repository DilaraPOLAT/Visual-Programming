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


void Dialog::on_rd_lisans_clicked()
{
    ui->grp_sinif->setEnabled(true);
    ui->grp_zorunluderslerLisan->setEnabled(true);
    ui->grp_Durum->setEnabled(false);
    ui->grp_ZorunluDerslerLisansustu->setEnabled(false);
}

void Dialog::on_rd_lisanustu_clicked()
{
    ui->grp_sinif->setEnabled(false);
    ui->grp_zorunluderslerLisan->setEnabled(false);
    ui->grp_Durum->setEnabled(true);
    ui->grp_ZorunluDerslerLisansustu->setEnabled(true);
}

void Dialog::on_btn_BilgileriYazdir_clicked()
{
    QString ad,soyad,bolum,seviye;
    ad=ui->ln_ad->text();
    soyad=ui->ln_soyad->text();
    bolum=ui->ln_bolum->text();

    //1.Yontem;
   /* QObjectList objler=this->children();
    foreach(QObject* obj,objler)
    { if(obj->inherits("QRadioButton"))
       {
        QRadioButton* rd = qobject_cast<QRadioButton* >(obj);
        if(rd->isChecked())
        {
            seviye=rd->text();
        }
       }
    }*/
    //1.yontemde seviye alamadım cunku ilk once grupbox sonra radiobutton ulasmam gerekiyor bunun için 2.yonteme basvurdum.


    //2.Yöntem
   /* QObject* obj=ui->grp_egitim;
    QList<QRadioButton* >liste = obj->findChildren<QRadioButton* >(QString(),Qt::FindDirectChildrenOnly);
    foreach(QRadioButton* rd,liste)
    {
        if(rd->isChecked())
        {
            seviye=rd->text();
        }
    }*/

    //3.Yöntem:
    if(ui->rd_lisans->isChecked())
    {
     seviye=ui->rd_lisans->text();
    }
    if(ui->rd_lisanustu->isChecked())
    {
     seviye=ui->rd_lisanustu->text();
    }
     QMessageBox::information(this,"Öğrenci Bilgileri" , "Ad:"+ad+"\n"+"Soyad:"+soyad+"\n"+"Bolum:"+bolum+"\n"+"Seviye:"+seviye+"\n");
}


void Dialog::on_btn_MezuniyetSorgula_clicked()
{
    QString ad,soyad,bolum,seviye;
    ad=ui->ln_ad->text();
    soyad=ui->ln_soyad->text();
    bolum=ui->ln_bolum->text();
    if(ui->rd_lisans->isChecked())
    {
     seviye=ui->rd_lisans->text();
    }
    if(ui->rd_lisanustu->isChecked())
    {
     seviye=ui->rd_lisanustu->text();
    }
    if(ui->rd_lisans->isChecked())
    {
        if(ui->rd_sinif4->isChecked()&& ui->ch_AIIT->isChecked()&& ui->ch_ISG->isChecked()&& ui->ch_TurkDili)
        {
            QMessageBox::information(this,"Mezuniyet Bilgileri","Öğrenci lisanstan Mezun Olabilir!","Tamam");
        }
        else
            QMessageBox::information(this,"Mezuniyet Bilgileri","Öğrenci lisanstan Mezun Olamaz!","Tamam");
    }
    if(ui->rd_lisanustu->isChecked())
    {
        if(ui->rd_Tez->isChecked()&& ui->ch_SecmeliDersler->isChecked()&&ui->ch_Seminer->isChecked()&&ui->ch_Tez->isChecked())
        {
            QMessageBox::information(this,"Mezuniyet Bilgileri","Öğrenci lisansüstünden Mezun Olabilir!","Tamam");
        }
        else
             QMessageBox::information(this,"Mezuniyet Bilgileri","Öğrenci lisansüstünden Mezun Olamaz!","Tamam");
    }
}

void Dialog::on_btn_OgrenciDurumYazdir_clicked()
{
    QString ad,soyad,bolum,seviye;
    ad=ui->ln_ad->text();
    soyad=ui->ln_soyad->text();
    bolum=ui->ln_bolum->text();
    if(ui->rd_lisans->isChecked())
    {
     seviye=ui->rd_lisans->text();
    }
    if(ui->rd_lisanustu->isChecked())
    {
     seviye=ui->rd_lisanustu->text();
    }
    bool durum=MezuniyetSorgula();
    if(seviye=="Lisans")
    {
        if(durum)
        {
           QMessageBox::information(this,"Öğrenci Bilgileri","Öğrenci lisans seviyesinde Mezun durumundaki bir öğrencidir!","Tamam");
        }
        else
          QMessageBox::information(this,"Öğrenci Bilgileri","Öğrenci lisans seviyesinde bir öğrencidir!","Tamam");
    }
    if(seviye=="Lisansüstü")
    {
        if(durum)
        {
           QMessageBox::information(this,"Öğrenci Bilgileri","Öğrenci lisansüstü seviyesinde Mezun durumundaki bir öğrencidir!","Tamam");
        }
        else
          QMessageBox::information(this,"Öğrenci Bilgileri","Öğrenci lisansüstü seviyesinde bir öğrencidir!","Tamam");
    }
}

bool Dialog::MezuniyetSorgula()
{
    QString ad,soyad,bolum,seviye;
    ad=ui->ln_ad->text();
    soyad=ui->ln_soyad->text();
    bolum=ui->ln_bolum->text();
    if(ui->rd_lisans->isChecked())
    {
     seviye=ui->rd_lisans->text();
    }
    if(ui->rd_lisanustu->isChecked())
    {
     seviye=ui->rd_lisanustu->text();
    }
    if(ui->rd_lisans->isChecked())
    {
        if(ui->rd_sinif4->isChecked()&& ui->ch_AIIT->isChecked()&& ui->ch_ISG->isChecked()&& ui->ch_TurkDili)
        {
            //QMessageBox::information(this,"Mezuniyet Bilgileri","Öğrenci lisanstan Mezun Olabilir!","Tamam");
            return true;
        }
        else
           // QMessageBox::information(this,"Mezuniyet Bilgileri","Öğrenci lisanstan Mezun Olamaz!","Tamam");
        return false;
    }
    if(ui->rd_lisanustu->isChecked())
    {
        if(ui->rd_Tez->isChecked()&& ui->ch_SecmeliDersler->isChecked()&&ui->ch_Seminer->isChecked()&&ui->ch_Tez->isChecked())
        {
           // QMessageBox::information(this,"Mezuniyet Bilgileri","Öğrenci lisansüstünden Mezun Olabilir!","Tamam");
            return true;
        }
        else
            // QMessageBox::information(this,"Mezuniyet Bilgileri","Öğrenci lisansüstünden Mezun Olamaz!","Tamam");
        return false;
    }
}












