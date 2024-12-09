#pragma once

#include <QMainWindow>
#include <QRandomGenerator>
#include <QDateTime>
#include <QTimer>

#include "notificationmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class NotificationExample;
}
QT_END_NAMESPACE

class NotificationExample : public QMainWindow
{
    Q_OBJECT

public:
    NotificationExample(QWidget *parent = nullptr);
    ~NotificationExample();

    QTimer *timer;
    void generator();

private:
    Ui::NotificationExample *ui;

    NotificationManager *notificationManager;



};
