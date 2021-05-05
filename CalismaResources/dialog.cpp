#include "dialog.h"
#include "ui_dialog.h"
#include "QFile"
#include "QMessageBox"
#include "QTextStream"
#include "QPushButton"
#include "QIcon"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);//ilk setup olussun sonrada asagıdaki kodlar
    //Burada kendi iconumu ve buttonlarımı kendim yazacagım
    QPushButton *btnAccept=new QPushButton(QIcon(":dialog/images/accept.png"),"Accept",this);
    QPushButton *btnReject=new QPushButton("Reject",this);
    btnReject->setIcon(QIcon(":dialog/images/cancel.png"));
    ui->buttonBox->addButton(btnAccept,QDialogButtonBox::ButtonRole::AcceptRole);
    ui->buttonBox->addButton(btnReject,QDialogButtonBox::ButtonRole::RejectRole);

    connect(btnAccept,&QPushButton::clicked,this,&Dialog::kaydet);





}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnYeni_clicked()
{
    ui->txtMetin->clear();
}

void Dialog::on_btnOku_clicked()
{
   oku();
}

void Dialog::on_btnKaydet_clicked()
{
    kaydet();
}

void Dialog::kaydet()
{
    QFile file("metin.txt");
    if (!file.open(QIODevice::WriteOnly))// Dosyanın yazma islemi icin acılıp acılmadıgı bilgisi
    {
        QMessageBox::critical(this,"HATA",file.errorString());
        return;
    }
    QTextStream stream(&file);//bu dosya icin bir nesne onu niteliyor.
    stream << ui->txtMetin->toPlainText();//file icine  txtmetin yazıyor.
    file.close();
    m_saved=true;
    QMessageBox::information(this,"Bilgi","Metin Kaydedildi");

}

void Dialog::oku()
{
   QFile file("metin.txt");
   if (!file.exists())//Dosya var mı?
   {
       return;
   }
   if (!file.open(QIODevice::ReadOnly))// Dosyanın okuma islemi icin acılıp acılmadıgı bilgisi
   {
       QMessageBox::critical(this,"HATA",file.errorString());
       return;
   }
   QTextStream stream(&file);
   ui->txtMetin->setPlainText(stream.readAll());//txtmetine file icindeki bilgiyi okuyor ve yazıyor
   file.close();

}

void Dialog::on_txtMetin_textChanged()
{
   m_saved=false;
}
void Dialog::closeEvent(QCloseEvent *event)
{
    if (!m_saved) {//kaydedilmedi ise
        QMessageBox::StandardButton btn=QMessageBox::question(this,"Kayıt Edilsin mi?","Metin Kutusunun icerigi değişmiştir. Kaydetmek ister misiniz?");
        if (btn==QMessageBox::StandardButton::Yes)
            kaydet();
    }
    event->accept();//eventi kabul ederek dialog box kapatıyorum
}


