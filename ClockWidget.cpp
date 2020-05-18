#include "ClockWidget.h"


//[]
ClockWidget::ClockWidget(QWidget* parent, int gridSize):
    QWidget(parent), m_gridWidth(gridSize)
{
    setMinimumSize(1000, 60);
    setMaximumSize(1000, 60);
    m_tactsCount = WIDGETS_WIDTH/m_gridWidth;

    for (int i=0; i<30; i++){
        m_lineEdits[i] = new QLineEdit(this);
        m_lineEdits[i]->setText(QString::number(i));
        if (m_lineEdits[i]->text().toInt()>9)
            m_lineEdits[i]->setFixedSize(20,15);
        else
            m_lineEdits[i]->setFixedSize(15,15);
        m_lineEdits[i]->move((m_gridWidth + (i*2*m_gridWidth))-2,0);
        m_lineEdits[i]->setStyleSheet("QLineEdit { background: rgb(236, 253, 172); selection-background-color: rgb(233, 99, 0); }");
        connect(m_lineEdits[i], SIGNAL(textChanged(const QString &)), this, SLOT(lineEditChanged(const QString &)));
    }

}
//[]


//[]
void ClockWidget::lineEditChanged(const QString &text)
{
    //qDebug()<<"Text in lineEdit changed to "<<text;
    for (int i=0; i<30; i++){
        if (QObject::sender() == m_lineEdits[i]){
            int number = text.toInt();
            for (int j=i+1;j<30;j++)
                m_lineEdits[j]->setText(QString::number(++number));
        }
    }
}
//[]


//[]
void ClockWidget::setTactsCount(int newTactsCount)
{
    m_tactsCount = newTactsCount;
    m_gridWidth = WIDGETS_WIDTH/m_tactsCount;
    for (int i=0; i<30; i++){
        m_lineEdits[i]->move((m_gridWidth + (i*2*m_gridWidth))-2,0);
    }
    update();
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
    for (int i=0; i<m_tactsCount; i++){
        if (i%2 == 0)
            painter.drawLine(i*m_gridWidth, 50, (i+1)*m_gridWidth, 50);
        else
            painter.drawLine(i*m_gridWidth, 20, (i+1)*m_gridWidth, 20);
        painter.drawLine((i+1)*m_gridWidth, 20, (i+1)*m_gridWidth, 50);
    }


    qDebug()<<"tactsCount = "<<m_tactsCount;
    qDebug()<<"gridWidth = "<<m_gridWidth;

}
//[]
