#include "MainWidget.h"


//[1]
MainWidget::MainWidget(QWidget* parent):
    QWidget(parent),m_lastActiveWidget(nullptr)
{
    m_globalGridWidth = 50;
    setMinimumSize(600, 300);
    setMaximumSize(600, 300);
    setupGui();
}
//[1]


//[]
void MainWidget::btnHighClick()
{
    qDebug()<< "btnHigh click";
}
//[]


//[]
void MainWidget::btnLowClick()
{
    qDebug()<< "btnLow click";
}
//[]


//[]
void MainWidget::setupGui()
{
    QVBoxLayout* mainVertLayout = new QVBoxLayout;
    QHBoxLayout* horLayout1 = new QHBoxLayout;
    QVBoxLayout* vertLayout1 = new QVBoxLayout;
    mainVertLayout->setSpacing(5);
    horLayout1->setSpacing(0);


    m_clockWidget = new ClockWidget;
    m_digiWidget1 = new DigiWidget(this, m_globalGridWidth);
    m_digiWidget2 = new DigiWidget(this, m_globalGridWidth);
    QPushButton* btnHigh = new QPushButton("1");
    QPushButton* btnLow = new QPushButton("0");


    connect(btnHigh, SIGNAL(clicked()), this, SLOT(btnHighClick()));
    connect(btnLow, SIGNAL(clicked()), this, SLOT(btnLowClick()));


    vertLayout1->addWidget(btnHigh);
    vertLayout1->addWidget(btnLow);

    horLayout1->addWidget(m_clockWidget);
    horLayout1->addStretch(1);
    horLayout1->addLayout(vertLayout1);

    mainVertLayout->addLayout(horLayout1);
    mainVertLayout->addWidget(m_digiWidget1);
    mainVertLayout->addWidget(m_digiWidget2);
    mainVertLayout->addStretch(1);
    this->setLayout(mainVertLayout);
}
//[]



