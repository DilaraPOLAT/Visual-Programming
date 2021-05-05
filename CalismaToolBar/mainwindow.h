#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFile>
#include<QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_actionAddition_triggered();

    void on_actionDivision_triggered();

    void on_action_multiplication_triggered();

    void on_action_Subtraction_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
