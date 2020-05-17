#include "MainWidget.h"


//[1]
MainWidget::MainWidget(QWidget* parent):
    QWidget(parent),m_lastActiveWidget(nullptr)
{
    m_globalGridWidth = 50;
    m_digiWidgetsCount = 3;
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


void MainWidget::digiWidgetActivate()
{
    DigiWidget* sender = qobject_cast<DigiWidget*>(QObject::sender());
    for (int i=0; i< (m_digiWidgetsCount);i++){
        if (sender == m_digiWidget[i]){
            m_lastActiveWidget = m_digiWidget[i];
            //qDebug()<<"Activate "<< i << " digiwidget";
        }
        else
            m_digiWidget[i]->clearHighlight();
    }
}


void MainWidget::clearDWActivated()
{
    for (int i=0; i<m_digiWidgetsCount; i++){
        m_digiWidget[i]->clearHighlight();
    }
    m_lastActiveWidget = nullptr;
}


//[]
void MainWidget::setupGui()
{
    QVBoxLayout* mainVertLayout = new QVBoxLayout;
    QHBoxLayout* horLayout1 = new QHBoxLayout;
    QVBoxLayout* vertLayout1 = new QVBoxLayout;
    mainVertLayout->setSpacing(5);
    horLayout1->setSpacing(0);


    m_clockWidget = new ClockWidget;
    m_digiWidget[0] = new DigiWidget(this, m_globalGridWidth);
    m_digiWidget[1] = new DigiWidget(this, m_globalGridWidth);
    m_digiWidget[2] = new DigiWidget(this, m_globalGridWidth);
    QPushButton* btnHigh = new QPushButton("1");
    QPushButton* btnLow = new QPushButton("0");


    connect(btnHigh, SIGNAL(clicked()), this, SLOT(btnHighClick()));
    connect(btnLow, SIGNAL(clicked()), this, SLOT(btnLowClick()));
    for (int i=0; i<m_digiWidgetsCount; i++){
        connect(m_digiWidget[i], SIGNAL(widgetActivated()), this, SLOT(digiWidgetActivate()));
        connect(m_digiWidget[i], SIGNAL(clearActivated()), this, SLOT(clearDWActivated()));
    }
    connect(m_digiWidget[0], SIGNAL(widgetActivated()), this, SLOT(digiWidgetActivate()));
    connect(m_digiWidget[1], SIGNAL(widgetActivated()), this, SLOT(digiWidgetActivate()));
    connect(m_digiWidget[2], SIGNAL(widgetActivated()), this, SLOT(digiWidgetActivate()));


    vertLayout1->addWidget(btnHigh);
    vertLayout1->addWidget(btnLow);

    horLayout1->addWidget(m_clockWidget);
    horLayout1->addStretch(1);
    horLayout1->addLayout(vertLayout1);

    mainVertLayout->addLayout(horLayout1);
    mainVertLayout->addWidget(m_digiWidget[0]);
    mainVertLayout->addWidget(m_digiWidget[1]);
    mainVertLayout->addWidget(m_digiWidget[2]);
    mainVertLayout->addStretch(1);
    this->setLayout(mainVertLayout);
}
//[]



