#ifndef DERS_ISLEMLERI_H
#define DERS_ISLEMLERI_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QMessageBox>

namespace Ui {
class Ders_islemleri;
}

class Ders_islemleri : public QDialog
{
    Q_OBJECT

public:
    explicit Ders_islemleri(QSqlDatabase ,QWidget *parent = nullptr);
    ~Ders_islemleri();
    void listele();

private slots:
    void on_btn_yeniKayit_clicked();

    void on_btn_Guncelle_clicked();

    void on_btn_Sil_clicked();

    void on_tbv_Tum_clicked(const QModelIndex &index);

private:
    Ui::Ders_islemleri *ui;
    QSqlQuery *sorgu;
    QSqlQueryModel *model;
    QSqlQueryModel *model1;
};

#endif // DERS_ISLEMLERI_H
