#include "ui_dialogconn.h"

DialogConn::DialogConn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConn)
{
    ui->setupUi(this);

    //connect(sock, SIGNAL(connected()), this, SLOT());
}

void DialogConn::toConnect(QString &adress, QString &port)
{
    sock = new QTcpSocket;
    sock->connectToHost(adress, (uint16_t)port.toInt());

}

void DialogConn::getFromServerError()
{
    // реализую уведомление от сервера, что нет данной уч.записи


}

void DialogConn::getFromServerData(QSettings &setts)
{
    // получаем с сервера Настройки

    emit giveSettings(setts);
}

void DialogConn::setData(QString &log, QString &pass)
{

}

DialogConn::~DialogConn()
{
    delete ui;
}
