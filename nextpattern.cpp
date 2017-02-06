#include "nextpattern.h"
#include <QPainter>

NextPattern::NextPattern(QWidget *parent) :
    QWidget(parent)
{
    pattern = nullptr;
}

void NextPattern::slotDrawPattern(Figure* next)
{
    pattern = next;
    repaint();
}

void NextPattern::paintEvent(QPaintEvent* event)
{
    QPainter p(this);
    if (pattern)
    {
        for (uint i = 0; i < 3; i++)
        {
            p.fillRect(rect().width()/2 - cell_size/2,cell_size*i,cell_size-1,cell_size-1,pattern->getColor(i));
        }
    }
}
