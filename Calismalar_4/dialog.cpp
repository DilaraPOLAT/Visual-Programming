#include "dialog.h"
#include "ui_dialog.h"
#include"QMessageBox"
#include"QDialog"

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

void Dialog::on_cmbBoxRenk_currentTextChanged(const QString &arg1)
{
    QString yazi="Seçtiğiniz Renk ...:"+arg1;
    ui->lblRenk->setText(yazi+" "+arg1);
    this->setStyleSheet("background-color: "+arg1);

}



void Dialog::on_roBtnK_clicked()
{
    ui->grpBoxKG->setEnabled(true);
    ui->grpBoxEG->setEnabled(false);
    ui->grpBoxKUG->setEnabled(false);
    ui->grpBoxKAG->setEnabled(false);
    ui->grpBoxEAG->setEnabled(false);
    ui->grpBoxEUG->setEnabled(false);

}

void Dialog::on_rdoBtnE_clicked()
{
    ui->grpBoxEG->setEnabled(true);
    ui->grpBoxKG->setEnabled(false);
    ui->grpBoxKUG->setEnabled(false);
    ui->grpBoxKAG->setEnabled(false);
    ui->grpBoxEAG->setEnabled(false);
    ui->grpBoxEUG->setEnabled(false);

}

void Dialog::on_rdBtnKUstG_clicked()
{
    ui->grpBoxKUG->setEnabled(true);
    ui->grpBoxKAG->setEnabled(false);
    ui->grpBoxEAG->setEnabled(false);
    ui->grpBoxEUG->setEnabled(false);

}

void Dialog::on_rdBtnKAltG_clicked()
{
    ui->grpBoxKUG->setEnabled(false);
    ui->grpBoxKAG->setEnabled(true);
    ui->grpBoxEAG->setEnabled(false);
    ui->grpBoxEUG->setEnabled(false);
}

void Dialog::on_rdBtnEUstG_clicked()
{
    ui->grpBoxKUG->setEnabled(false);
    ui->grpBoxKAG->setEnabled(false);
    ui->grpBoxEAG->setEnabled(false);
    ui->grpBoxEUG->setEnabled(true);
}


void Dialog::on_rdBtnEAltG_clicked()
{
    ui->grpBoxKUG->setEnabled(false);
    ui->grpBoxKAG->setEnabled(false);
    ui->grpBoxEAG->setEnabled(true);
    ui->grpBoxEUG->setEnabled(false);
}



void Dialog::on_btnListele_clicked()
{
    QString ad=ui->lnAd->text();
    QString sAd=ui->lnSoyad->text();
    QString yas=ui->dateEdit->text();
     QString cinsiyet,giyim;
    int kilo=ui->spinBoxKilo->value();

    QObject* obj=ui->groupBox;
        QList<QRadioButton* >liste = obj->findChildren<QRadioButton* >(QString(),Qt::FindDirectChildrenOnly);
        foreach(QRadioButton* rd,liste)
        {
            if(rd->isChecked())
            {
                cinsiyet=rd->text();
            }
        }

   ui->textEditBilgi->setPlainText(cinsiyet+"\n"+ad+"\n"+sAd+"\n"+yas+"\n"+QString::number(kilo)+"\n");
   if(ui->rdoBtnE->isChecked())
   {
       if(ui->rdBtnEAltG->isChecked())
       {
        giyim=secimAl(ui->grpBoxEAG);
       }
       else if(ui->rdBtnEUstG->isChecked())
       {
         giyim=secimAl(ui->grpBoxEUG);
       }
   }
   else if(ui->roBtnK->isChecked())
   {
       if(ui->rdBtnKAltG->isChecked())
       {
         giyim=secimAl(ui->grpBoxKAG);
       }
       else if(ui->rdBtnKUstG->isChecked())
       {
           giyim=secimAl(ui->grpBoxKUG);
       }
   }
    ui->textEditBilgi->append(giyim);
}

QString Dialog::secimAl(QObject *obj)
{
    QString deger;
    QList<QCheckBox*> lst = obj->findChildren<QCheckBox*>(QString(),Qt::FindDirectChildrenOnly);
    foreach(QCheckBox* ch,lst){
        if(ch->isChecked()){

            deger +=ch->text();
            deger+=" , ";
            //QMessageBox::information(this,"cdc",deger);

        }
    }
    if(deger.isEmpty())
    {
        deger="Seçim yok";
    }

    return deger;
}
