#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMouseEvent>
#include<yenibuttonlabel.h>
#include<QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   void mousePressEvent(QMouseEvent*);


public slots:
    void degistir();

private slots:
    void on_cmbBox_Renk_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QList<yenibuttonlabel*> butonlar2;
    QList<yenibuttonlabel*> butonlar;
};
#endif // MAINWINDOW_H
