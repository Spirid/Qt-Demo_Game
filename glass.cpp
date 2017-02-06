#include "glass.h"
#include <QPainter>
#include <QKeyEvent>
#include <QMessageBox>

QColor Glass::empty = QColor(150,150,150);

Glass::Glass(QWidget *parent) :
    QWidget(parent)
{
    m_rows = 0;
    m_columns = 0;
    glassArray = new QVector <QVector<QColor>>();
    isGaming = false;

    checked = false;
    idTimer = 0;
    //Asynchronous connection + delayed signal
    connect(this, SIGNAL(signalGlassInit()), SLOT(slotGlassInit()), Qt::QueuedConnection);
    emit(signalGlassInit());
    cur = new Figure();
    next = new Figure();
}

Glass::~Glass()
{
    delete glassArray;
    delete cur;
    delete next;
}

void Glass::slotGlassInit()
{
    glassArray->resize(m_rows);
    for (uint i = 0; i < m_rows; i++)
    {
        (*glassArray)[i].resize(m_columns);
    }
    clearGlass();
    QSize s(m_columns*cell_size, m_rows*cell_size);
    setFixedSize(s);
}

void Glass::clearGlass()
{
    (*glassArray)[0].fill(empty);
    glassArray->fill((*glassArray)[0]);
    score = 0;
    emit(signalSetScore(score));
    timer_interval = 2000;
    repaint();
}

void Glass::slotNewGame()
{
    isGaming = true;
    clearGlass();
    cur->setRowIndex(0);
    cur->setColIndex(m_columns/2);
    next->setRowIndex(0);
    next->setColIndex(0);
    //emit signal of redrawing
    emit(drawPattern(next));
    killTimer(idTimer);
    idTimer = startTimer(timer_interval);
    setFocus();
    repaint();
}

void Glass::slotAbout()
{
    killTimer(idTimer);
    QMessageBox::about(this, "About this", "It can be information about the program.");
}

void Glass::slotRules()
{
    killTimer(idTimer);
    QMessageBox::about(this, "Rules", "It can be rules.");
}

void Glass::slotSettings()
{
    killTimer(idTimer);
    QMessageBox::about(this, "Settings", "ToDo add sttings");
}

void Glass::paintEvent(QPaintEvent* event)
{
    QPainter p(this);
    for (uint i = 0; i < m_rows; i++)
    {
        for (uint j = 0; j < m_columns; j++)
        {
            p.fillRect(cell_size*j,cell_size*i,cell_size-1,cell_size-1,(*glassArray)[i][j]);
        }
    }
    if(isGaming)
    {
        cur->paintFigure(p);
    }
}

void Glass::keyPressEvent(QKeyEvent* event)
{
    if(isGaming)
    {
        uint r = 0;
        uint c = 0;
        uint b = 0;
        switch(event->key())
        {
        case Qt::Key_Left:
            //If is possible, redraw to the left
            if (isEmpty(cur->getRowIndex()+2,cur->getColIndex()-1)) cur->moveLeft();
            break;
        case Qt::Key_Right:
            //If is possible, redraw to the right
            if (isEmpty(cur->getRowIndex()+2,cur->getColIndex()+1)) cur->moveRight();
            break;
        case Qt::Key_Down:
            //Cycle repaint color
            cur->rotateDown();
            break;
        case Qt::Key_Up:
            //Cycle repaint color
            cur->rotateUp();
            break;
        case Qt::Key_Space:
            //Drop pole: find where
            b = cur->getRowIndex()+2;
            c = cur->getColIndex();
            r = findEmpty(b,c);
            if (r>b)
            {
                cur->setRowIndex(r-2);
            }
            //Call the helper method
            //when the drop down the pole will have no plase
            AcceptColors(r-2,c);
            break;
        default:
            //For any other key call basic event handle
            QWidget::keyPressEvent(event);
        }
    }
    else
    {
        //Add base class possibility to handle an event
        QWidget::keyPressEvent(event);
    }
    repaint();
}

void Glass::AcceptColors(uint r, uint c)
{
    //Add pole
    for (uint i = 0; i < 3; i++)
    {
        (*glassArray)[r + i][c] = cur->getColor(i);
    }
    //Analyze and reset current statys of glass
    checked = false;
    CheckGlass(checked);
    //Swap next and cur
    Figure* tmp = cur;
    cur = next;
    next = tmp;
    tmp = nullptr;
    //Config next и cur (foe next zero index, for cur state them)
    //Generate color for next pole
    next->setRowIndex(0);
    next->setColIndex(0);
    next->MakeRandomColors();
    cur->setRowIndex(0);
    cur->setColIndex(m_columns/2);
    //Emit signal drawPattern(next); while draw next pole
    emit(drawPattern(next));
    if (!isEmpty(2,m_columns/2))
    {
        isGaming = false;
        killTimer(idTimer);
        QMessageBox::about(this, "", "Game over.");
    }
}

void Glass::CheckGlass(bool c)
{
    if (c)
    {
        idTimer = startTimer(timer_interval);
        return;
    }
    killTimer(idTimer);
    for (uint j = 0; j<m_columns; j++)
    {
        for (int i = m_rows-1; i>=0; i--)
        {
            if (isEmptyColumn(i,j)) break;
            bool clear = false;
            if (CheckUp(i,j)) clear = true;
            if (CheckUpRight(i,j)) clear = true;
            if (CheckRight(i,j)) clear = true;
            if (CheckRightDown(i,j)) clear = true;
            if (clear)
            {
                (*glassArray)[i][j] = empty;
                score += 1;
            }
        }
    }
    checked = true;
    SetDown();
    emit(signalSetScore(score));
}

bool Glass::isEmpty(uint r, uint c)
{
    if (r<m_rows && c<m_columns) return (*glassArray)[r][c] == empty;
    return false;
}

bool Glass::isEmptyColumn(uint r, uint c)
{
    if (c<m_columns)
    {
        for (int i=r; i>=0; i--)
        {
            if (!isEmpty(i,c)) return false;
        }
        return true;
    }
    return false;
}

uint Glass::findEmpty(uint b, uint c)
{
    uint r;
    for (r=m_rows-1; r>b; r--)
    {
        if (isEmpty(r,c)) break;
    }
    return r;
}

bool Glass::CheckUp(uint r, uint c)
{
    if (isEmpty(r,c) || r<2) return false;
    bool three = ((*glassArray)[r][c] == (*glassArray)[r-1][c]) && ((*glassArray)[r][c] == (*glassArray)[r-2][c]);
    bool four = false;
    bool five = false;
    if (r>=3) four = three && ((*glassArray)[r][c] == (*glassArray)[r-3][c]);
    if (r>=4) five = four && ((*glassArray)[r][c] == (*glassArray)[r-4][c]);
    if (five)
    {
        for (uint i = 4; i>0; i--) (*glassArray)[r-i][c] = empty;
        score += 4;
        return true;
    }
    if (four)
    {
        for (uint i = 3; i>0; i--) (*glassArray)[r-i][c] = empty;
        score += 3;
        return true;
    }
    if (three)
    {
        for (uint i = 2; i>0; i--) (*glassArray)[r-i][c] = empty;
        score += 2;
        return true;
    }
    return false;
}

bool Glass::CheckUpRight(uint r, uint c)
{
    if (isEmpty(r,c) || r<2 || c>m_columns-3) return false;
    bool three = ((*glassArray)[r][c] == (*glassArray)[r-1][c+1]) && ((*glassArray)[r][c] == (*glassArray)[r-2][c+2]);
    bool four = false;
    bool five = false;
    if (r>=3 && c<=m_columns-4) four = three && ((*glassArray)[r][c] == (*glassArray)[r-3][c+3]);
    if (r>=4 && c<=m_columns-5) five = four && ((*glassArray)[r][c] == (*glassArray)[r-4][c+4]);
    if (five)
    {
        for (uint i = 4; i>0; i--) (*glassArray)[r-i][c+i] = empty;
        score += 4;
        return true;
    }
    if (four)
    {
        for (uint i = 3; i>0; i--) (*glassArray)[r-i][c+i] = empty;
        score += 3;
        return true;
    }
    if (three)
    {
        for (uint i = 2; i>0; i--) (*glassArray)[r-i][c+i] = empty;
        score += 2;
        return true;
    }
    return false;
}

bool Glass::CheckRight(uint r, uint c)
{
    if (isEmpty(r,c) || c>m_columns-3) return false;
    bool three = ((*glassArray)[r][c] == (*glassArray)[r][c+1]) && ((*glassArray)[r][c] == (*glassArray)[r][c+2]);
    bool four = false;
    bool five = false;
    if (c<=m_columns-4) four = three && ((*glassArray)[r][c] == (*glassArray)[r][c+3]);
    if (c<=m_columns-5) five = four && ((*glassArray)[r][c] == (*glassArray)[r][c+4]);
    if (five)
    {
        for (uint i = 4; i>0; i--) (*glassArray)[r][c+i] = empty;
        score += 4;
        return true;
    }
    if (four)
    {
        for (uint i = 3; i>0; i--) (*glassArray)[r][c+i] = empty;
        score += 3;
        return true;
    }
    if (three)
    {
        for (uint i = 2; i>0; i--) (*glassArray)[r][c+i] = empty;
        score += 2;
        return true;
    }
    return false;
}

bool Glass::CheckRightDown(uint r, uint c)
{
    if (isEmpty(r,c) || r>m_rows-3 || c>m_columns-3) return false;
    bool three = ((*glassArray)[r][c] == (*glassArray)[r+1][c+1]) && ((*glassArray)[r][c] == (*glassArray)[r+2][c+2]);
    bool four = false;
    bool five = false;
    if (r<=m_rows-4 && c<=m_columns-4) four = three && ((*glassArray)[r][c] == (*glassArray)[r+3][c+3]);
    if (r<=m_rows-5 && c<=m_columns-5) five = four && ((*glassArray)[r][c] == (*glassArray)[r+4][c+4]);
    if (five)
    {
        for (uint i = 4; i>0; i--) (*glassArray)[r+i][c+i] = empty;
        score += 4;
        return true;
    }
    if (four)
    {
        for (uint i = 3; i>0; i--) (*glassArray)[r+i][c+i] = empty;
        score += 3;
        return true;
    }
    if (three)
    {
        for (uint i = 2; i>0; i--) (*glassArray)[r+i][c+i] = empty;
        score += 2;
        return true;
    }
    return false;
}

void Glass::SetDown()
{
    for (uint j = 0; j<m_columns; j++)
    {
        SetColumnDown(m_rows-1, j);
    }
}

void Glass::SetColumnDown(uint r, uint c)
{
    if (isEmptyColumn(r,c)) return;
    while (isEmpty(r,c))
    {
        for (uint i=r; i>0; i--)
        {
            if (isEmptyColumn(i,c)) break;
            (*glassArray)[i][c] = (*glassArray)[i-1][c];
            (*glassArray)[i-1][c] = empty;
            checked = false;
            idTimer = 0;
        }
    }
    SetColumnDown(r-1,c);
}

void Glass::timerEvent(QTimerEvent* event)
{
    timer_interval -= (score / 500) * 100;
    uint r = cur->getRowIndex();
    uint c = cur->getColIndex();
    if (isEmpty(r+3,c))
    {
        cur->setRowIndex(r+1);
    }
    else
    {
        AcceptColors(r,c);
    }
    repaint();
}
