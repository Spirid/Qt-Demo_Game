#ifndef NEXTPATTERN_H
#define NEXTPATTERN_H

#include <QWidget>
#include "figure.h"

class NextPattern : public QWidget
{
    Q_OBJECT

    Figure* pattern;
    const uint cell_size = 20;

public:
    explicit NextPattern(QWidget *parent = 0);
    void paintEvent(QPaintEvent*event);

public slots:
    void slotDrawPattern(Figure*);

};

#endif // NEXTPATTERN_H
