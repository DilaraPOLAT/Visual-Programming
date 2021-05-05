#include "QApplication"
#include"QLabel"
#include"QPushButton"
#include "QLineEdit"
#include "QPlainTextEdit"
int main(int argc,char *argv[])
{
    QApplication app(argc,argv);

    //Program normal bir şekilde dursa with code 0 normal sekilde durmazsa crashed

    //QLabel *label=new QLabel("Merhaba Qt c++");
   /* QLabel *label=new QLabel("<h2>Merhaba</h2><font color=red><h1><b> Qt<b/></h1></font> c++");
    label->show();//labeli goster

    QPushButton *pushBtn=new QPushButton("Kaydet");
    pushBtn->show();*/

    QLineEdit *lnEdit=new QLineEdit("Merhaba");
    lnEdit->show();

    QPlainTextEdit *plainText=new  QPlainTextEdit("Merhaba");
    plainText->show();

    return app.exec();//donguye giriyor applicationları calistiriyor.
}
