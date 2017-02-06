#include "figure.h"
#include <QPainter>
#include "QTime"


Figure::Figure()
{
    m_i = 0;
    m_j = 0;
    MakeRandomColors();
}

void Figure::MakeRandomColors()
{
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
    for (uint i = 0; i < 3; i++)
    {
        ColorType x = static_cast<ColorType>(qrand() % 6);
        switch (x)
        {
        case RED:
            fig[i] = QColor(255,0,0);
            break;
        case GREEN:
            fig[i] = QColor(0,255,0);
            break;
        case BLUE:
            fig[i] = QColor(0,0,255);
            break;
        case YELLOW:
            fig[i] = QColor(255,255,0);
            break;
        case ORANGE:
            fig[i] = QColor(255,128,0);
            break;
        case PURPLE:
            fig[i] = QColor(255,0,255);
            break;
        default:
            break;
        }
    }
}

void Figure::rotateUp()
{
    QColor tmp = fig[0];
    fig[0] = fig[1];
    fig[1] = fig[2];
    fig[2] = tmp;
}

void Figure::rotateDown()
{
    QColor tmp = fig[2];
    fig[2] = fig[1];
    fig[1] = fig[0];
    fig[0] = tmp;
}

void Figure::paintFigure(QPainter& p)
{
    for (uint i = 0; i < 3; i++)
    {
        p.fillRect(cell_size*m_j,cell_size*(m_i + i),cell_size-1,cell_size-1,fig[i]);
    }
}
