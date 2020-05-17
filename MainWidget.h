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

signals:
    void setHigh(DigiWidget* currentDigi);
    void setLow(DigiWidget* currentDigi);
    void setInvert(DigiWidget* currentDigi);

public slots:
    void btnHighClick();
    void btnLowClick();
    void btnInvertClick();
    void digiWidgetActivate(int leftBorder, int RightBorder);
    void clearDWActivated();

private:
    void setupGui();
    ClockWidget* m_clockWidget;
    DigiWidget* m_digiWidget[3];
    int m_digiWidgetsCount;
    DigiWidget* m_lastActiveWidget;
    int m_globalGridWidth;
    QPair<int, int> m_currentBorders;
};

#endif // MAINWIDGET_H
