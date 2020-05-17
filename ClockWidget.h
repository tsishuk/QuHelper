#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H
#include <QtWidgets>

class ClockWidget : public QWidget
{
    Q_OBJECT

public:
    ClockWidget(QWidget* parent = nullptr, int gridSize = 50);
    static const int WIDGETS_WIDTH = 500;

public slots:
    void setTactsCount(int newTactsCount);


protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int m_gridWidth;
    int m_tactsCount;
};

#endif // CLOCKWIDGET_H
