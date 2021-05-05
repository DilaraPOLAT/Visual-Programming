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


    void on_roBtnK_clicked();

    void on_rdoBtnE_clicked();

    void on_rdBtnKUstG_clicked();

    void on_rdBtnKAltG_clicked();

    void on_rdBtnEUstG_clicked();

    void on_rdBtnEAltG_clicked();

    void on_cmbBoxRenk_currentTextChanged(const QString &arg1);

    void on_btnListele_clicked();
    QString secimAl(QObject* obj);


private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
