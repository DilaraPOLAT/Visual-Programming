/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QCheckBox *checkBox_bold;
    QCheckBox *checkBox_italik;
    QLabel *label_5;
    QLineEdit *ln_yaz;
    QPushButton *btn_uygula;
    QLabel *label_goster;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QFontComboBox *fontComboBox;
    QSpinBox *spinBox_fontsize;
    QComboBox *comboBox_renk;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(466, 367);
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 10, 191, 16));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label->setFont(font);
        checkBox_bold = new QCheckBox(Dialog);
        checkBox_bold->setObjectName(QString::fromUtf8("checkBox_bold"));
        checkBox_bold->setGeometry(QRect(150, 180, 70, 17));
        checkBox_italik = new QCheckBox(Dialog);
        checkBox_italik->setObjectName(QString::fromUtf8("checkBox_italik"));
        checkBox_italik->setGeometry(QRect(220, 180, 70, 17));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(110, 210, 91, 16));
        ln_yaz = new QLineEdit(Dialog);
        ln_yaz->setObjectName(QString::fromUtf8("ln_yaz"));
        ln_yaz->setGeometry(QRect(210, 210, 181, 20));
        btn_uygula = new QPushButton(Dialog);
        btn_uygula->setObjectName(QString::fromUtf8("btn_uygula"));
        btn_uygula->setGeometry(QRect(180, 240, 75, 23));
        label_goster = new QLabel(Dialog);
        label_goster->setObjectName(QString::fromUtf8("label_goster"));
        label_goster->setEnabled(false);
        label_goster->setGeometry(QRect(110, 280, 251, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Vivaldi"));
        font1.setPointSize(22);
        font1.setItalic(true);
        label_goster->setFont(font1);
        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(100, 50, 96, 111));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        widget1 = new QWidget(Dialog);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(200, 50, 190, 111));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        fontComboBox = new QFontComboBox(widget1);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        verticalLayout_2->addWidget(fontComboBox);

        spinBox_fontsize = new QSpinBox(widget1);
        spinBox_fontsize->setObjectName(QString::fromUtf8("spinBox_fontsize"));
        spinBox_fontsize->setMinimum(5);

        verticalLayout_2->addWidget(spinBox_fontsize);

        comboBox_renk = new QComboBox(widget1);
        comboBox_renk->addItem(QString());
        comboBox_renk->addItem(QString());
        comboBox_renk->addItem(QString());
        comboBox_renk->addItem(QString());
        comboBox_renk->addItem(QString());
        comboBox_renk->addItem(QString());
        comboBox_renk->setObjectName(QString::fromUtf8("comboBox_renk"));

        verticalLayout_2->addWidget(comboBox_renk);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Yaz\304\261 Bi\303\247imlendirme Aray\303\274z\303\274", nullptr));
        checkBox_bold->setText(QCoreApplication::translate("Dialog", "Bold", nullptr));
        checkBox_italik->setText(QCoreApplication::translate("Dialog", "\304\260talik", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "Yaz\304\261 Giriniz:", nullptr));
        btn_uygula->setText(QCoreApplication::translate("Dialog", "Uygula", nullptr));
        label_goster->setText(QString());
        label_2->setText(QCoreApplication::translate("Dialog", "Yaz\304\261 Tipi:", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "Yaz\304\261 Tipi B\303\274y\303\274kl\303\274\304\237\303\274:", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "Renk:", nullptr));
        comboBox_renk->setItemText(0, QCoreApplication::translate("Dialog", "red", nullptr));
        comboBox_renk->setItemText(1, QCoreApplication::translate("Dialog", "green", nullptr));
        comboBox_renk->setItemText(2, QCoreApplication::translate("Dialog", "blue", nullptr));
        comboBox_renk->setItemText(3, QCoreApplication::translate("Dialog", "yellow", nullptr));
        comboBox_renk->setItemText(4, QCoreApplication::translate("Dialog", "cyan", nullptr));
        comboBox_renk->setItemText(5, QCoreApplication::translate("Dialog", "magenta", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
