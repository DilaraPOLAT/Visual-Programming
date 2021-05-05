#include <QCoreApplication>
#include "QDebug"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug()<<"Merhaba Qt";

    return a.exec();//a.exec ait her seyi calistiriyor
}
