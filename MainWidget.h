#ifndef MAINWIDGET_H
#define MAINWIDGET_H


#include <QtWidgets>
#include "DigiWidget.h"
#include "ClockWidget.h"


class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget* parent = NULL);
    static const int WIDGETS_WIDTH = 1000;

signals:
    void setHigh(DigiWidget* currentDigi);
    void setLow(DigiWidget* currentDigi);
    void setInvert(DigiWidget* currentDigi);
    void set1X(DigiWidget* currentDigi);
    void set2X(DigiWidget* currentDigi);
    void set3X(DigiWidget* currentDigi);
    void setTactsCount(int newTactsCount);

public slots:
    void btnHighClick();
    void btnLowClick();
    void btnInvertClick();
    void btn1XClicked();
    void btn2XClicked();
    void btn3XClicked();
    void digiWidgetActivate(int leftBorder, int RightBorder);
    void clearDWActivated();
    void spinTactsChanged(int newTactsQuantity);

private:
    void setupGui();
    ClockWidget* m_clockWidget;
    DigiWidget* m_digiWidget[5];
    int m_digiWidgetsCount;
    DigiWidget* m_lastActiveWidget;
    QPair<int, int> m_currentBorders;
    QSpinBox* spinTacts;

    int m_globalGridWidth;
    int m_tactsQuantity;
};

#endif // MAINWIDGET_H
