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
    void setTactsCount(int newTactsCount);

public slots:
    void btnHighClick();
    void btnLowClick();
    void btnInvertClick();
    void digiWidgetActivate(int leftBorder, int RightBorder);
    void clearDWActivated();
        void spinTactsChanged(int newTactsQuantity);

private:
    void setupGui();
    ClockWidget* m_clockWidget;
    DigiWidget* m_digiWidget[3];
    int m_digiWidgetsCount;
    DigiWidget* m_lastActiveWidget;
    QPair<int, int> m_currentBorders;
    QSpinBox* spinTacts;

    int m_globalGridWidth;
    int m_tactsQuantity;
};

#endif // MAINWIDGET_H
