#include <QApplication>
#include <QFile>
#include "widget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//------------加载qss-------------
    QFile qss(":/music2.qss");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
    Widget w;

    w.show();
    
    return a.exec();
}
