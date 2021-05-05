#ifndef YENIBUTTON_H
#define YENIBUTTON_H

#include <QPushButton>
#include <QMainWindow>
#include <QObject>
#include <QWidget>

class YeniButton : public QPushButton
{
    Q_OBJECT
public:
    explicit YeniButton(QWidget *parent = 0);
    bool tiklandimi;

signals:
public slots:
    void tikla();
};

#endif // YENIBUTTON_H
