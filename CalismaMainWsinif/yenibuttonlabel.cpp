#include "yenibuttonlabel.h"

yenibuttonlabel::yenibuttonlabel(QWidget*parent):
    QLabel(parent)

{
        tiklandimi = false;
        connect(this,SIGNAL(clicked()),this,SLOT(tikla()));
}

void yenibuttonlabel::tikla2()
{
    tiklandimi = !tiklandimi;
}
