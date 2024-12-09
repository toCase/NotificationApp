#pragma once

#include <QObject>
#include <QTimer>
#include <QEvent>

#include "notificationdialog.h"

class NotificationManager : public QObject
{
    Q_OBJECT
public:
    explicit NotificationManager(QObject *parent = nullptr);


    bool eventFilter(QObject *watched, QEvent *event);
private:
    QSize parentSize = QSize(0, 0);
    QTimer *timer;

    QList<NotificationDialog*> activeNotifications;

public slots:
    void showMessage(QWidget *widget, int type, const QString& message);

    void positionNotifications();
    void repositionNotification(NotificationDialog *notification, QWidget *widget);
    void removeNotification(NotificationDialog *notification);

};

