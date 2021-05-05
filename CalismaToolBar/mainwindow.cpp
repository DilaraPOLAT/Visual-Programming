#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile my_file("kaydet.txt");
    if(!my_file.exists())
    {
        QMessageBox::information(this,"UYARI",my_file.errorString());
        return;
    }
    else if(!my_file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this,"UYARI",my_file.errorString());
        return;
    }
    QTextStream stream(&my_file);
    while(!stream.atEnd())
    {
        ui->plainTextEdit->appendPlainText(stream.readLine());
    }
    my_file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionCopy_triggered()
{
  ui->plainTextEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
  ui->plainTextEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
ui->plainTextEdit->paste();
}

void MainWindow::on_actionNew_triggered()
{
   ui->plainTextEdit->clear();
}

void MainWindow::on_actionSave_triggered()
{
    QFile my_file("kaydet.txt");
    if(!my_file.open(QIODevice::WriteOnly|QIODevice::Append))
    {
        QMessageBox::information(this,"UYARI",my_file.errorString());
        return;
    }
    QTextStream stream(&my_file);
    stream<<ui->lineEdit->text()+"\n";
    my_file.close();

}

void MainWindow::on_actionAddition_triggered()
{
    double sonuc;
    sonuc=(ui->ln_say1->text().toDouble()+ui->ln_say2->text().toDouble());
    ui->ln_sonuc->setText(QString::number(sonuc));

}


void MainWindow::on_actionDivision_triggered()
{
    double sonuc;
    sonuc=(ui->ln_say1->text().toDouble()/ui->ln_say2->text().toDouble());
     ui->ln_sonuc->setText(QString::number(sonuc));
}

void MainWindow::on_action_multiplication_triggered()
{
    double sonuc;
    sonuc=(ui->ln_say1->text().toDouble()*ui->ln_say2->text().toDouble());
    ui->ln_sonuc->setText(QString::number(sonuc));
}

void MainWindow::on_action_Subtraction_triggered()
{
    double sonuc;
    sonuc=(ui->ln_say1->text().toDouble()-ui->ln_say2->text().toDouble());
     ui->ln_sonuc->setText(QString::number(sonuc));
}
