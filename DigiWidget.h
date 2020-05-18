#ifndef DIGIWIDGET_H
#define DIGIWIDGET_H
#include <QtWidgets>


class DigiWidget : public QWidget
{
    Q_OBJECT

public:
    DigiWidget(QWidget* parent = NULL, int gridWidth = 0);
    void clearHighlight();
    static const int WIDGETS_WIDTH = 1000;
    int getLeftBorder(){return m_leftBorder;}
    int getRightBorder(){return m_rightBorder;}

signals:
    void widgetActivated(int leftBorder, int rightBorder);
    void clearActivated();

public slots:
    void setHigh(DigiWidget* current);
    void setLow(DigiWidget* current);
    void setInvert(DigiWidget* current);
    void setTactsCount(int newTactsCount);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QPoint m_startSelect;
    QPoint m_stopSelect;
    QRect m_highlightedRect;
    int m_gridWidth;
    int* m_values;
    int m_valuesCount;
    int m_leftBorder;
    int m_rightBorder;
    int m_tactsCount;
};


#endif // DIGIWIDGET_H
