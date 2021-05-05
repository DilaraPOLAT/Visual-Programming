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
    void on_rd_lisans_clicked();

    void on_rd_lisanustu_clicked();

    void on_btn_BilgileriYazdir_clicked();

    void on_btn_MezuniyetSorgula_clicked();

    void on_btn_OgrenciDurumYazdir_clicked();

    bool MezuniyetSorgula();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
