#ifndef YENIBUTTON2_H
#define YENIBUTTON2_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<QMouseEvent>

class yenibutton2 : public QWidget
{
    Q_OBJECT
public:
    explicit yenibutton2(QWidget *parent = nullptr);
    bool tiklandimi;



signals:
public slots:
    void tikla2();
};

#endif // YENIBUTTON2_H
