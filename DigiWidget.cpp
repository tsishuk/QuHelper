#include "DigiWidget.h"



//[]
DigiWidget::DigiWidget(QWidget* parent, int gridWidth):
    QWidget(parent), m_gridWidth(gridWidth)
{
    setMinimumSize(WIDGETS_WIDTH, 50);
    setMaximumSize(WIDGETS_WIDTH, 50);
    m_valuesCount = WIDGETS_WIDTH/m_gridWidth;
    m_values = new int[m_valuesCount];
    m_leftBorder = m_rightBorder = -1;
    //qDebug()<<"m_values size = "<< m_valuesCount;
    for (int i=0; i<m_valuesCount;i++)
        m_values[i] = 0;
    //m_values[1] = 1;
    m_highlightedRect = QRect();
}
//[]


//[]
void DigiWidget::mousePressEvent(QMouseEvent *event)
{
    m_leftBorder = m_rightBorder = -1;
    m_startSelect = event->pos();
    m_stopSelect = event->pos();
    m_highlightedRect = QRect();
    emit clearActivated();
    update();
}
//[]


//[]
void DigiWidget::mouseMoveEvent(QMouseEvent *event)
{
    m_stopSelect = event->pos();
    m_leftBorder = m_startSelect.x()/m_gridWidth;
    m_rightBorder = m_stopSelect.x()/m_gridWidth;
    int left = (m_leftBorder) * m_gridWidth;
    int right = (m_rightBorder + 1) * m_gridWidth;
    if (right > m_gridWidth*m_valuesCount)
        right = m_gridWidth*m_valuesCount;
    m_highlightedRect = QRect(QPoint(left, 2), QPoint(right, this->height() - 2));
    emit widgetActivated(m_leftBorder, m_rightBorder);
    update();
}
//[]


//[]
void DigiWidget::setHigh(DigiWidget* current)
{
    if (current == this){
        for (int i=m_leftBorder; i<=m_rightBorder; i++)
            m_values[i] = 1;
        update();
    }
}
//[]


//[]
void DigiWidget::setLow(DigiWidget* current)
{
    if (current == this){
        for (int i=m_leftBorder; i<=m_rightBorder; i++)
            m_values[i] = 0;
        update();
    }
}
//[]


//[]
void DigiWidget::setInvert(DigiWidget* current)
{
    if (current == this){
        for (int i=m_leftBorder; i<=m_rightBorder; i++)
            m_values[i] ^= 1;
        update();
    }
}
//[]


//[]
void DigiWidget::clearHighlight()
{
    m_highlightedRect = QRect();
    update();
}
//[]


//[]
void DigiWidget::paintEvent(QPaintEvent *event)
{
    int W = this->width();
    int H = this->height();
    QPainter painter(this);

    painter.setBrush(QColor("#ECFDAC"));
    painter.fillRect(event->rect(), painter.brush());

    QPen pen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);

    //paint signal
    for (int i=0; i<m_valuesCount; i++){
        if (m_values[i] == 0)
            painter.drawLine(i*m_gridWidth, 40, (i+1)*m_gridWidth, 40);
        else
            painter.drawLine(i*m_gridWidth, 10, (i+1)*m_gridWidth, 10);
        if ((m_values[i] != m_values[i-1]) and (i!=0))
            painter.drawLine(i*m_gridWidth, 10, i*m_gridWidth, 40);
    }


    pen.setStyle(Qt::DotLine);
    pen.setWidth(1);
    painter.setPen(pen);

    //paint grid lines
    pen.setColor(QColor("#A4A4A4"));
    painter.setPen(pen);
    for (int i=m_gridWidth; i<W; i+= m_gridWidth)
        painter.drawLine(i, 0, i, H);

    //fill highlighted Rect
    QBrush brush = QBrush(Qt::Dense5Pattern);
    brush.setColor(QColor("#A0CFFE"));
    painter.setBrush(brush);

    //paint frame of highlighting
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(2);
    pen.setColor(QColor("#238FFA"));
    painter.setPen(pen);

    painter.fillRect(m_highlightedRect, painter.brush());
    painter.drawRect(m_highlightedRect);
}
//[]
