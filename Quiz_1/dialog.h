#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_radioButtonTO_clicked();

    void on_radioButtonIO_clicked();

    void on_pushButtonRastgeleSay_clicked();

    void on_pushButtonYarsBasla_clicked();


private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
