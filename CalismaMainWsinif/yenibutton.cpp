#include "yenibutton.h"

YeniButton::YeniButton(QWidget*parent):
    QPushButton(parent)

{
    tiklandimi = false;
    connect(this,SIGNAL(clicked()),this,SLOT(tikla()));
}
void YeniButton::tikla()
{
    tiklandimi = !tiklandimi;
}
