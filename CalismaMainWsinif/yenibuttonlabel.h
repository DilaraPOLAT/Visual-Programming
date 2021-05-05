#ifndef YENIBUTTONLABEL_H
#define YENIBUTTONLABEL_H

#include <QLabel>
#include <QMainWindow>
#include <QObject>
#include <QWidget>


class yenibuttonlabel : public QLabel
{
     Q_OBJECT
public:
    explicit yenibuttonlabel (QWidget *parent = 0);

     bool tiklandimi;

signals:
public slots:
    void tikla2();
};

#endif // YENIBUTTONLABEL_H
