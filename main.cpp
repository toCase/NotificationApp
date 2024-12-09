#include "notificationexample.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NotificationExample w;
    w.show();
    return a.exec();
}
