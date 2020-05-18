#include "MainWidget.h"


//[1]
MainWidget::MainWidget(QWidget* parent):
    QWidget(parent),m_lastActiveWidget(NULL)
{
    m_globalGridWidth = 30;

    m_digiWidgetsCount = 5;
    m_currentBorders.first = -1;
    m_currentBorders.second = -1;
    setMinimumSize(1140, 350);
    setMaximumSize(1140, 350);
    setupGui();
}
//[1]


//[]
void MainWidget::btnHighClick()
{
    emit setHigh(m_lastActiveWidget);
}
//[]


//[]
void MainWidget::btnLowClick()
{
    emit setLow(m_lastActiveWidget);
}
//[]


//[]
void MainWidget::btnInvertClick()
{
    emit setInvert(m_lastActiveWidget);
}
//[]


//[]
void MainWidget::spinTactsChanged(int newTactsQuantity)
{
    if ((newTactsQuantity > 0) and (newTactsQuantity<50)){
        m_globalGridWidth = WIDGETS_WIDTH/newTactsQuantity;
        emit setTactsCount(newTactsQuantity);
    }
}
//[]


//[]
void MainWidget::digiWidgetActivate(int leftBorder, int rightBorder)
{
    DigiWidget* sender = qobject_cast<DigiWidget*>(QObject::sender());
    for (int i=0; i< (m_digiWidgetsCount);i++){
        if (sender == m_digiWidget[i]){
            m_lastActiveWidget = m_digiWidget[i];
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
    m_lastActiveWidget = NULL;
    m_currentBorders.first = -1;
    m_currentBorders.second = -1;
}
//[]


//[]
void MainWidget::setupGui()
{
    QVBoxLayout* mainVertLayout = new QVBoxLayout;
    QHBoxLayout* horLayout1 = new QHBoxLayout;
    QHBoxLayout* mainHorLayout = new QHBoxLayout;
    QVBoxLayout* secondVertLayout = new QVBoxLayout;
    QVBoxLayout* labelsVerLayout = new QVBoxLayout;
    mainVertLayout->setSpacing(2);
    horLayout1->setSpacing(0);

    QLabel* clkLabel = new QLabel("CLK");
    QLineEdit* aLineEdit = new QLineEdit("a");
    QLineEdit* bLineEdit = new QLineEdit("b");
    QLineEdit* cLineEdit = new QLineEdit("c");
    QLineEdit* dLineEdit = new QLineEdit("d");
    QLineEdit* eLineEdit = new QLineEdit("e");
    clkLabel->setMaximumWidth(30);
    aLineEdit->setMaximumWidth(30);
    bLineEdit->setMaximumWidth(30);
    cLineEdit->setMaximumWidth(30);
    dLineEdit->setMaximumWidth(30);
    eLineEdit->setMaximumWidth(30);
    m_clockWidget = new ClockWidget(this, m_globalGridWidth);
    m_digiWidget[0] = new DigiWidget(this, m_globalGridWidth);
    m_digiWidget[1] = new DigiWidget(this, m_globalGridWidth);
    m_digiWidget[2] = new DigiWidget(this, m_globalGridWidth);
    m_digiWidget[3] = new DigiWidget(this, m_globalGridWidth);
    m_digiWidget[4] = new DigiWidget(this, m_globalGridWidth);
    QPushButton* btnHigh = new QPushButton("1");
    QPushButton* btnLow = new QPushButton("0");
    QPushButton*btnInvert = new QPushButton("<->");


    spinTacts = new QSpinBox();
    spinTacts->setMinimumSize(50,50);
    spinTacts->setValue(31);
    spinTacts->setStyleSheet("QSpinBox::up-button { width: 30px; height: 20px;}"
                             "QSpinBox::up-button:hover { width: 30px; height: 20px;}"
                             "QSpinBox::down-button { width: 30px; height: 20px;}"
                             "QSpinBox::down-button:hover { width: 30px; height: 20px;}");
    spinTacts->clearFocus();
    spinTacts->setMaximum(50);
    btnHigh->setFont(QFont( "helvetica", 20, QFont::Medium, false ));
    btnLow->setFont(QFont( "helvetica", 20, QFont::Medium, false ));
    btnInvert->setFont(QFont( "helvetica", 20, QFont::Medium, false ));
    spinTacts->setFont(QFont( "helvetica", 20, QFont::Medium, false ));


    connect(btnHigh, SIGNAL(clicked()), this, SLOT(btnHighClick()));
    connect(btnLow, SIGNAL(clicked()), this, SLOT(btnLowClick()));
    connect(btnInvert, SIGNAL(clicked()), this, SLOT(btnInvertClick()));
    for (int i=0; i<m_digiWidgetsCount; i++){
        connect(m_digiWidget[i], SIGNAL(widgetActivated(int, int)), this, SLOT(digiWidgetActivate(int, int)));
        connect(m_digiWidget[i], SIGNAL(clearActivated()), this, SLOT(clearDWActivated()));
        connect(this, SIGNAL(setHigh(DigiWidget*)), m_digiWidget[i], SLOT(setHigh(DigiWidget*)));
        connect(this, SIGNAL(setLow(DigiWidget*)), m_digiWidget[i], SLOT(setLow(DigiWidget*)));
        connect(this, SIGNAL(setInvert(DigiWidget*)), m_digiWidget[i], SLOT(setInvert(DigiWidget*)));
        connect(this, SIGNAL(setTactsCount(int)), m_digiWidget[i], SLOT(setTactsCount(int)));
    }
    connect(spinTacts, SIGNAL(valueChanged(int)), this, SLOT(spinTactsChanged(int)));
    connect(this, SIGNAL(setTactsCount(int)), m_clockWidget, SLOT(setTactsCount(int)));

    labelsVerLayout->addSpacing(30);
    labelsVerLayout->addWidget(clkLabel);
    labelsVerLayout->addSpacing(28);
    labelsVerLayout->addWidget(aLineEdit);
    labelsVerLayout->addSpacing(25);
    labelsVerLayout->addWidget(bLineEdit);
    labelsVerLayout->addSpacing(26);
    labelsVerLayout->addWidget(cLineEdit);
    labelsVerLayout->addSpacing(26);
    labelsVerLayout->addWidget(dLineEdit);
    labelsVerLayout->addSpacing(26);
    labelsVerLayout->addWidget(eLineEdit);
    labelsVerLayout->addStretch(1);

    secondVertLayout->setSpacing(0);
    secondVertLayout->addWidget(btnHigh);
    secondVertLayout->addWidget(btnLow);
    secondVertLayout->addWidget(btnInvert);
    secondVertLayout->addStretch(1);
    secondVertLayout->addWidget(spinTacts);


    mainVertLayout->addWidget(m_clockWidget);
    mainVertLayout->addWidget(m_digiWidget[0]);
    mainVertLayout->addWidget(m_digiWidget[1]);
    mainVertLayout->addWidget(m_digiWidget[2]);
    mainVertLayout->addWidget(m_digiWidget[3]);
    mainVertLayout->addWidget(m_digiWidget[4]);
    //mainVertLayout->addLayout(horLayout1);
    mainVertLayout->addStretch(1);

    mainHorLayout->addLayout(labelsVerLayout);
    mainHorLayout->addLayout(mainVertLayout);
    mainHorLayout->addStretch(1);
    mainHorLayout->addLayout(secondVertLayout);
    this->setLayout(mainHorLayout);
    btnHigh->setFocus();
}
//[]



