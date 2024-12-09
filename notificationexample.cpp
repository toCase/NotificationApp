#include "notificationexample.h"
#include "./ui_notificationexample.h"

NotificationExample::NotificationExample(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NotificationExample)
{
    ui->setupUi(this);

    notificationManager = new NotificationManager(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &NotificationExample::generator);
    timer->start(3000);
}

NotificationExample::~NotificationExample()
{
    delete ui;
}

void NotificationExample::generator()
{
    auto gen =  QRandomGenerator::global();
    int type = gen->bounded(0, 4);
    QString message;

    switch (type) {
    case NotificationDialog::ERROR:
        message = QString("%1 - ERROR Message")
                      .arg(QDateTime::currentDateTime().toString("hh:mm:ss"));
        break;
    case NotificationDialog::WARNING:
        message = QString("%1 - WARNING Message")
                      .arg(QDateTime::currentDateTime().toString("hh:mm:ss"));
        break;
    case NotificationDialog::NOTIFY:
        message = QString("%1 - NOTIFY Message")
                      .arg(QDateTime::currentDateTime().toString("hh:mm:ss"));
        break;
    case NotificationDialog::SUCCESS:
        message = QString("%1 - SUCCESS Message")
                      .arg(QDateTime::currentDateTime().toString("hh:mm:ss"));
        break;
    default:
        break;
    }
    notificationManager->showMessage(this, type, message);
}
