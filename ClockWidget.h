#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H
#include <QtWidgets>

class ClockWidget : public QWidget
{
public:
    ClockWidget(QWidget* parent = nullptr, int gridSize = 50);
    static const int WIDGETS_WIDTH = 500;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int m_gridWidth;
    int m_valuesCount;
};

#endif // CLOCKWIDGET_H
