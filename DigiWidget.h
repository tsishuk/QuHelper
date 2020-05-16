#ifndef DIGIWIDGET_H
#define DIGIWIDGET_H
#include <QtWidgets>


class DigiWidget : public QWidget
{
    Q_OBJECT

public:
    DigiWidget(QWidget* parent = nullptr, int gridWidth = 0);
    void clearHighlight();

signals:
    void widgetActivated();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QPoint m_startSelect;
    QPoint m_stopSelect;
    QRect m_highlightedRect;
    int m_gridWidth;
};


#endif // DIGIWIDGET_H