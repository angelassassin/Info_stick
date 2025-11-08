#include "info_stick.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Info_stick window;
    window.show();
    return app.exec();
}
