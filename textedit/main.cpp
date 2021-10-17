#include "textedit.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Textedit w;
    w.show();
    return a.exec();
}
