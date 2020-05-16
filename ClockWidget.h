#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H
#include <QtWidgets>

class ClockWidget : public QWidget
{
public:
    ClockWidget(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // CLOCKWIDGET_H
