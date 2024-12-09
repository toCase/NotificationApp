#pragma once
#include <QDialog>


namespace Ui {
class NotificationDialog;
}

class NotificationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NotificationDialog(QWidget *parent = nullptr);
    ~NotificationDialog();

    enum NotificationTypes : int {
        ERROR = 0,
        WARNING = 1,
        NOTIFY = 2,
        SUCCESS = 3
    };

private:
    Ui::NotificationDialog *ui;

public slots:
    void showNotification(QPoint position, const QString& message, int type);
};
