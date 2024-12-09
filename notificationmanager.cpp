#include "notificationmanager.h"

NotificationManager::NotificationManager(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer(this);
}

bool NotificationManager::eventFilter(QObject *watched, QEvent *event)
{
    // Проверяем, что это событие изменения размера
    if (event->type() == QEvent::Resize) {
        // Получаем виджет, который изменил размер
        QWidget* resizedWidget = qobject_cast<QWidget*>(watched);

        if (resizedWidget) {
            // Находим все связанные с этим виджетом уведомления
            for (auto notification : activeNotifications) {
                if (notification->property("sourceWidget").value<QWidget*>() == resizedWidget) {
                    // Пересчитываем позицию уведомления
                    repositionNotification(notification, resizedWidget);
                }
            }
        }
    }
    // Возвращаем false, чтобы событие продолжило распространяться
    return false;
}


void NotificationManager::showMessage(QWidget *widget, int type, const QString &message)
{
    int duration = 0;

    switch (type) {
    case NotificationDialog::WARNING:
        duration = 5000;

        break;
    case NotificationDialog::NOTIFY:
        duration = 3000;

        break;
    case NotificationDialog::SUCCESS:
        duration = 3000;

        break;
    case NotificationDialog::ERROR:
        duration = 7000;

        break;
    default:
        break;
    }

    parentSize = widget->size();
    widget->installEventFilter(this);

    int x = parentSize.width() - (500 + 20);
    int y = parentSize.height() - ((activeNotifications.count() + 1)  * (80 + 20));

    QPoint position(x, y);

    NotificationDialog *nd = new NotificationDialog(widget);
    // Сохраняем ссылку на исходный виджет как свойство
    nd->setProperty("sourceWidget", QVariant::fromValue(widget));
    nd->showNotification(position, message, type);

    activeNotifications.append(nd);

    QTimer::singleShot(duration, this, [this, nd]() {
        removeNotification(nd);
    });
}

void NotificationManager::positionNotifications()
{
    for (int i = 0; i < activeNotifications.count(); i++) {
        int x = parentSize.width() - (500 + 20);
        int y = parentSize.height() - ((i + 1) * (80 + 20));
        QPoint position(x, y);

        auto notification = activeNotifications.at(i);
        notification->move(position);
    }
}

void NotificationManager::repositionNotification(NotificationDialog *notification, QWidget *widget)
{
    parentSize = widget->size();
    positionNotifications();
}

void NotificationManager::removeNotification(NotificationDialog *notification)
{
    activeNotifications.removeOne(notification);
    notification->close();
    positionNotifications();
}
