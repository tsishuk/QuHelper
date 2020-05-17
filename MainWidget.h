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
    static const int WIDGETS_WIDTH = 500;

public slots:
    void btnHighClick();
    void btnLowClick();
    void digiWidgetActivate();
    void clearDWActivated();

private:
    void setupGui();
    ClockWidget* m_clockWidget;
    DigiWidget* m_digiWidget[3];
    int m_digiWidgetsCount;
    DigiWidget* m_lastActiveWidget;
    int m_globalGridWidth;
};

#endif // MAINWIDGET_H
