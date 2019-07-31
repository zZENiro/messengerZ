#include "loginplatform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginPlatform w;
    w.show();

    return a.exec();
}
