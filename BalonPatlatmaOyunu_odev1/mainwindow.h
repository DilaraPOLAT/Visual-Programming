#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include "yenibuton.h"
#include"QMessageBox"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void degistir();
     void degistir1();
       void kapat();

private:
    Ui::MainWindow *ui;
    QList<yeniButon*> butonlar2;
    QList<yeniButon*> butonlar;

};

#endif // MAINWINDOW_H
