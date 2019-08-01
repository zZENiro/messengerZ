#include "dialogconn.h"
#include "ui_dialogconn.h"

DialogConn::DialogConn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConn)
{
    ui->setupUi(this);

    sock = new QTcpSocket;
    connect(sock, SIGNAL(connected()), this, SLOT(emitQuestToServer()));
}

void DialogConn::getDataFromServer()
{
    // получаю объект класса QSettings и вызываю сигнал
    // giveSettings(QSettings&) который передаёт этот объект
    // для основного виджета


    // emit GiveSettings(settings)
}

void DialogConn::emitQuestToServer()
{
    qDebug() << "connected!";
    // нужно запросить сервер на существование Логина и Пароля в БД на нём.


}

void DialogConn::toConnect(QString &adress, QString &port)
{
    qDebug() << "IP: " + adress + "port: " + port;
    sock->connectToHost(adress, (uint16_t)port.toInt());
}

void DialogConn::setData(QString &log, QString &pass)
{
    this->login = &log;
    this->password = &pass;
    qDebug() << "log: " + *this->login + "pass: " + *this->password;
}

DialogConn::~DialogConn()
{
    delete ui;
}
