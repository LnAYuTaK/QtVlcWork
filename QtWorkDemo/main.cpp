#include "MainWidget/widget.h"
#include <QApplication>
#include "Vlc/vlcwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VlcWidget w;
    w.show();
    return a.exec();
}
