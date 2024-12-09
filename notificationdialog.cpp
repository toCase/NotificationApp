#include "notificationdialog.h"
#include "ui_notificationdialog.h"

NotificationDialog::NotificationDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NotificationDialog)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_TransparentForMouseEvents);
    setWindowFlags(Qt::FramelessWindowHint);

    setModal(false);
    setSizeGripEnabled(false);
}

NotificationDialog::~NotificationDialog()
{
    delete ui;
}

void NotificationDialog::showNotification(QPoint position, const QString &message, int type)
{
    QString style;
    switch (type) {
    case NOTIFY:
        style = "background-color: rgba(0, 85, 127, .3);";
        break;
    case ERROR:
        style = "background-color: rgba(153, 0, 0, .3);";
        break;
    case WARNING:
        style = "background-color: rgba(185, 113, 0, .3);";
        break;
    case SUCCESS:
        style = "background-color: rgba(81, 159, 106, .3);";
        break;
    default:
        break;
    }

    setStyleSheet(style);
    ui->l_note->setText(message);
    this->move(position);
    this->show();
}
