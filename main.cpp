#include <QApplication>
#include "DigiWidget.h"
#include "MainWidget.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    MainWidget wgt;
    wgt.setWindowTitle("QuHelper (Nikita Edition)");
    wgt.show();

    return app.exec();
}
