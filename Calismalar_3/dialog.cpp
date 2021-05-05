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


void Dialog::on_rdBtn_Lise_clicked()
{
  ui->grp_Lise->setEnabled(true);
  ui->grp_LiseK->setEnabled(true);
  ui->grp_Uni->setEnabled(false);
  ui->grp_UniK->setEnabled(false);

}

void Dialog::on_rdBtn_Universite_clicked()
{
    ui->grp_Lise->setEnabled(false);
    ui->grp_LiseK->setEnabled(false);
    ui->grp_Uni->setEnabled(true);
    ui->grp_UniK->setEnabled(true);
}

void Dialog::on_btnListele_clicked()
{
    QString ad,soyad,numara,seviye;
    ad=ui->lnAd->text();
    soyad=ui->lnSoyad->text();
    numara=ui->lnNumara->text();
    QObject* obj=ui->grp_OgrenimDurumu;
        QList<QRadioButton* >liste = obj->findChildren<QRadioButton* >(QString(),Qt::FindDirectChildrenOnly);
        foreach(QRadioButton* rd,liste)
        {
            if(rd->isChecked())
            {
                seviye=rd->text();
            }
        }
       // ui->textEdit->append("Öğrenci Bilgileri" , "Ad:"+ad+"\n"+"Soyad:"+soyad+"\n"+"Bolum:"+numara+"\n" + "Seviye:"+seviye+"\n");
        ui->textEdit->setPlainText(ad+"\n"+soyad+"\n"+numara+"\n"+seviye);
        if(ui->rdBtn_Lise->isChecked())
        {
            QString lise=secimAl(ui->grp_Lise);
            QString alt_secimler="Lise:"+lise+"\r\n";

            QString lisek=secimAl2(ui->grp_LiseK);
            QString alt_secimlerk="Kitaplar:"+lisek+"\r\n";

            ui->textEdit->append(alt_secimler+alt_secimlerk);

            //QMessageBox::information(this,"SECIMLERINIZ",alt_secimler+alt_secimlerk);
        }
        else if(ui->rdBtn_Universite->isChecked())
        {
            QString Uni=secimAl(ui->grp_Uni);
            QString alt_secimler="Üniversite:"+Uni+"\r\n";
            QString Unik=secimAl2(ui->grp_UniK);
            QString alt_secimlerk="Kitaplar:"+Unik+"\r\n";
            ui->textEdit->append(alt_secimler+alt_secimlerk);

            //QMessageBox::information(this,"SECIMLERINIZ",alt_secimler+alt_secimlerk);
        }
}

QString Dialog::secimAl(QObject* obj)
{
    QString deger="Hicbiri";
    QList<QRadioButton*> lst = obj->findChildren<QRadioButton*>(QString(),Qt::FindDirectChildrenOnly);
    foreach(QRadioButton* rdo,lst){
        if(rdo->isChecked()){
            deger =rdo->text();
            break;
        }
    }
    return deger;
}

QString Dialog::secimAl2(QObject *obj)
{
    QString deger;
    QList<QCheckBox*> lst = obj->findChildren<QCheckBox*>(QString(),Qt::FindDirectChildrenOnly);
    foreach(QCheckBox* ch,lst){
        if(ch->isChecked()){

            deger +=ch->text();
           deger+=" , ";

        }
    }
    if(deger.isEmpty())
    {
        deger="HiçBiri";
    }
    return deger;
}








