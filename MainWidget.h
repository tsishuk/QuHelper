#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtWidgets>
#include "DigiWidget.h"
#include "ClockWidget.h"


class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget* parent = nullptr);

public slots:
    void btnHighClick();
    void btnLowClick();

private:
    void setupGui();
    ClockWidget* m_clockWidget;
    DigiWidget* m_digiWidget1;
    DigiWidget* m_digiWidget2;
    int m_globalGridWidth;
    DigiWidget* m_lastActiveWidget;
};

#endif // MAINWIDGET_H
