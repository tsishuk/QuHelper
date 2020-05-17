#include "MainWidget.h"


//[1]
MainWidget::MainWidget(QWidget* parent):
    QWidget(parent),m_lastActiveWidget(nullptr)
{
    m_globalGridWidth = 30;

    m_digiWidgetsCount = 3;
    m_currentBorders.first = -1;
    m_currentBorders.second = -1;
    setMinimumSize(600, 300);
    setMaximumSize(600, 300);
    setupGui();
}
//[1]


//[]
void MainWidget::btnHighClick()
{
    //qDebug()<< "btnHigh click";
    emit setHigh(m_lastActiveWidget);
    //qDebug()<<"left = "<<m_currentBorders.first<<" right = "<<m_currentBorders.second;
}
//[]


//[]
void MainWidget::btnLowClick()
{
    emit setLow(m_lastActiveWidget);
    //qDebug()<< "btnLow click";
}
//[]


//[]
void MainWidget::btnInvertClick()
{
    emit setInvert(m_lastActiveWidget);
}
//[]


//[]
void MainWidget::digiWidgetActivate(int leftBorder, int rightBorder)
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
    m_currentBorders.first = leftBorder;
    m_currentBorders.second = rightBorder;
}
//[]


//[]
void MainWidget::clearDWActivated()
{
    for (int i=0; i<m_digiWidgetsCount; i++){
        m_digiWidget[i]->clearHighlight();
    }
    m_lastActiveWidget = nullptr;
    m_currentBorders.first = -1;
    m_currentBorders.second = -1;
}
//[]


//[]
void MainWidget::setupGui()
{
    QVBoxLayout* mainVertLayout = new QVBoxLayout;
    QHBoxLayout* horLayout1 = new QHBoxLayout;
    QVBoxLayout* vertLayout1 = new QVBoxLayout;
    mainVertLayout->setSpacing(2);
    horLayout1->setSpacing(0);


    m_clockWidget = new ClockWidget(this, m_globalGridWidth);
    m_digiWidget[0] = new DigiWidget(this, m_globalGridWidth);
    m_digiWidget[1] = new DigiWidget(this, m_globalGridWidth);
    m_digiWidget[2] = new DigiWidget(this, m_globalGridWidth);
    QPushButton* btnHigh = new QPushButton("1");
    QPushButton* btnLow = new QPushButton("0");
    QPushButton*btnInvert = new QPushButton("<->");
    btnHigh->setFont(QFont( "helvetica", 20, QFont::Bold, false ));
    btnLow->setFont(QFont( "helvetica", 20, QFont::Bold, false ));
    btnInvert->setFont(QFont( "helvetica", 20, QFont::Bold, false ));


    connect(btnHigh, SIGNAL(clicked()), this, SLOT(btnHighClick()));
    connect(btnLow, SIGNAL(clicked()), this, SLOT(btnLowClick()));
    connect(btnInvert, SIGNAL(clicked()), this, SLOT(btnInvertClick()));
    for (int i=0; i<m_digiWidgetsCount; i++){
        connect(m_digiWidget[i], SIGNAL(widgetActivated(int, int)), this, SLOT(digiWidgetActivate(int, int)));
        connect(m_digiWidget[i], SIGNAL(clearActivated()), this, SLOT(clearDWActivated()));
        connect(this, SIGNAL(setHigh(DigiWidget*)), m_digiWidget[i], SLOT(setHigh(DigiWidget*)));
        connect(this, SIGNAL(setLow(DigiWidget*)), m_digiWidget[i], SLOT(setLow(DigiWidget*)));
        connect(this, SIGNAL(setInvert(DigiWidget*)), m_digiWidget[i], SLOT(setInvert(DigiWidget*)));
    }

    //vertLayout1->addWidget(btnHigh);
    //vertLayout1->addWidget(btnLow);
    //vertLayout1->addWidget(btnInvert);

    //horLayout1->addWidget(m_clockWidget);
    //horLayout1->addLayout(vertLayout1);

    //mainVertLayout->addLayout(horLayout1);
    horLayout1->setSpacing(0);
    horLayout1->addWidget(btnHigh);
    horLayout1->addWidget(btnLow);
    horLayout1->addWidget(btnInvert);
    horLayout1->addStretch(1);

    mainVertLayout->addWidget(m_clockWidget);
    mainVertLayout->addWidget(m_digiWidget[0]);
    mainVertLayout->addWidget(m_digiWidget[1]);
    mainVertLayout->addWidget(m_digiWidget[2]);
    mainVertLayout->addLayout(horLayout1);
    mainVertLayout->addStretch(1);
    this->setLayout(mainVertLayout);
}
//[]



