#ifndef DIGIWIDGET_H
#define DIGIWIDGET_H
#include <QtWidgets>


class DigiWidget : public QWidget
{
    Q_OBJECT

public:
    DigiWidget(QWidget* parent = nullptr, int gridWidth = 0);
    void clearHighlight();
    static const int WIDGETS_WIDTH = 500;
    int getLeftBorder(){return m_leftBorder;}
    int getRightBorder(){return m_rightBorder;}

signals:
    void widgetActivated();
    void clearActivated();

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
};


#endif // DIGIWIDGET_H
