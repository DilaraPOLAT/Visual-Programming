#ifndef NOT_ISLEMLERI_H
#define NOT_ISLEMLERI_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QMessageBox>

namespace Ui {
class Not_islemleri;
}

class Not_islemleri : public QDialog
{
    Q_OBJECT

public:
    explicit Not_islemleri(QSqlDatabase ,QWidget *parent = nullptr);
    ~Not_islemleri();
    void listele();
     void listele2();

private slots:
    void on_btn_DersKE_clicked();

    void on_tbvTumOgr_clicked(const QModelIndex &index);

    void on_tbvTumDers_clicked(const QModelIndex &index);

private:
    Ui::Not_islemleri *ui;
    QSqlQuery *sorgu;
    QSqlQueryModel *model;
    QSqlQueryModel *model1;
    QSqlQueryModel *model2;
};

#endif // NOT_ISLEMLERI_H
