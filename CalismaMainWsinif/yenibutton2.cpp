#include "yenibutton2.h"

yenibutton2::yenibutton2(QWidget *parent) :
    QWidget(parent)

{
        tiklandimi = false;
        connect(this,SIGNAL(clicked()),this,SLOT(tikla()));
}

void yenibutton2::tikla2()
{
    tiklandimi = !tiklandimi;
}
