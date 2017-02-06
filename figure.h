#ifndef FIGURE_H
#define FIGURE_H

#include <QColor>
class QPainter;

class Figure
{
    enum ColorType : uint {RED, GREEN, BLUE, YELLOW, ORANGE, PURPLE};

    QColor fig[3];
    uint m_i, m_j;
    const uint cell_size = 20;

public:
    Figure();
    void MakeRandomColors();

    uint getRowIndex() const { return m_i; }
    uint getColIndex() const { return m_j; }
    QColor getColor(uint i) const { return fig[i]; }
    void setRowIndex(uint i) { m_i = i; }
    void setColIndex(uint j) { m_j = j; }
    void moveLeft() { m_j--; }
    void moveRight() { m_j++; }
    void rotateUp();
    void rotateDown();
    void paintFigure(QPainter& p);
};

#endif // FIGURE_H
