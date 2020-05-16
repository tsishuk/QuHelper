#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtWidgets>
#include "DigiWidget.h"


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
    DigiWidget* m_digiWidget1;
    int m_globalGridWidth;
};

#endif // MAINWIDGET_H
