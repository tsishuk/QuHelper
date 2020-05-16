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
    void digiWidgetActivate();

private:
    void setupGui();
    ClockWidget* m_clockWidget;
    DigiWidget* m_digiWidget[3];
    DigiWidget* m_lastActiveWidget;
    int m_globalGridWidth;
};

#endif // MAINWIDGET_H
