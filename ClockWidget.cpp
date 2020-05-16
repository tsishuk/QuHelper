#include "ClockWidget.h"

//[]
ClockWidget::ClockWidget(QWidget* parent):
    QWidget(parent)
{
    setMinimumSize(500, 50);
    setMaximumSize(500, 50);
}
//[]


//[]
void ClockWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setBrush(QColor("#FECB6C"));
    painter.fillRect(event->rect(), painter.brush());

}
//[]
