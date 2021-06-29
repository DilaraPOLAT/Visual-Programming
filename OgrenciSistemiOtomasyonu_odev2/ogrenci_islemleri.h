#ifndef OGRENCI_ISLEMLERI_H
#define OGRENCI_ISLEMLERI_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QMessageBox>

namespace Ui {
class ogrenci_islemleri;
}

class ogrenci_islemleri : public QDialog
{
    Q_OBJECT

public:
    explicit ogrenci_islemleri(QSqlDatabase ,QWidget *parent = nullptr);
    ~ogrenci_islemleri();
      void listele();

private slots:
    void on_btn_yeniKayit_clicked();

    void on_btn_Sil_clicked();

    void on_btn_Guncelle_clicked();

    void on_tbv_Tum_clicked(const QModelIndex &index);

private:
    Ui::ogrenci_islemleri *ui;
    QSqlQuery *sorgu;
    QSqlQueryModel *model;

};

#endif // OGRENCI_ISLEMLERI_H
