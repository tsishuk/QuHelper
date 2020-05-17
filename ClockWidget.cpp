#include "ClockWidget.h"

//[]
ClockWidget::ClockWidget(QWidget* parent, int gridSize):
    QWidget(parent), m_gridWidth(gridSize)
{
    setMinimumSize(500, 50);
    setMaximumSize(500, 50);
    m_valuesCount = WIDGETS_WIDTH/m_gridWidth;
}
//[]


//[]
void ClockWidget::paintEvent(QPaintEvent *event)
{
    int W = this->width();
    int H = this->height();
    QPainter painter(this);

    painter.setBrush(QColor("#ECFDAC"));
    painter.fillRect(event->rect(), painter.brush());

    QPen pen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);

    //paint Low Level line(paint this line by default with startup)
    for (int i=0; i<m_valuesCount; i++){
        if (i%2 == 0)
            painter.drawLine(i*m_gridWidth, 40, (i+1)*m_gridWidth, 40);
        else
            painter.drawLine(i*m_gridWidth, 10, (i+1)*m_gridWidth, 10);
    }

    for (int i=m_gridWidth; i<W; i+= m_gridWidth)
        painter.drawLine(i, 10, i, 40);

}
//[]
