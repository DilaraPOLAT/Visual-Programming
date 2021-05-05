#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
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
    void on_btnCheckable_clicked();

    void on_btnIsCheck_clicked();

    void on_btnAutoRepeat_clicked();

    void on_btnToggleAutoRepeat_clicked();

    void on_btnDefault_clicked();

    void on_btnToggleDefault_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
