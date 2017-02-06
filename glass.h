#ifndef GLASS_H
#define GLASS_H

#include <QWidget>
#include "figure.h"

class Glass : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(uint rows READ getRows WRITE setRows)
    Q_PROPERTY(uint columns READ getColumns WRITE setColumns)

    const uint cell_size = 20;
    static QColor empty;

    uint m_rows;
    uint m_columns;
    QVector <QVector<QColor>>* glassArray;

    bool isGaming;

    bool checked;
    uint score;
    uint timer_interval;
    int idTimer;

    Figure* cur;
    Figure* next;

public:
    explicit Glass(QWidget *parent = 0);
    ~Glass();
    uint getRows() const { return m_rows; }
    uint getColumns() const { return m_columns; }
    void clearGlass();
    void AcceptColors(uint r, uint c);
    void CheckGlass(bool c);
    bool isEmpty(uint r, uint c);
    bool isEmptyColumn(uint r, uint c);
    uint findEmpty(uint b, uint c);
    bool CheckUp(uint r, uint c);
    bool CheckUpRight(uint r, uint c);
    bool CheckRight(uint r, uint c);
    bool CheckRightDown(uint r, uint c);
    void SetDown();
    void SetColumnDown(uint r, uint c);
    void paintEvent(QPaintEvent*event);
    void keyPressEvent(QKeyEvent*event);
    void timerEvent(QTimerEvent*event);

signals:
    void signalGlassInit();
    void drawPattern(Figure*);
    void signalSetScore(int);

public slots:
    void setRows(uint arg) { m_rows = arg; }
    void setColumns(uint arg) { m_columns = arg; }
    void slotGlassInit();
    void slotNewGame();

    void slotAbout();
    void slotRules();
    void slotSettings();
};

#endif // GLASS_H
