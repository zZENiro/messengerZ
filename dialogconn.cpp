#include "dialogconn.h"
#include "ui_dialogconn.h"


DialogConn::DialogConn(QWidget *parent) :
    QDialog(parent),
    _nextBlockSize(0),
    ui(new Ui::DialogConn)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::WindowType::Popup, true);

    sock = new QTcpSocket;
    connect(sock, SIGNAL(connected()), this, SLOT(emitQuestToServer()));
    connect(sock, SIGNAL(readyRead() ), SLOT(getDataFromServer()));
    connect(sock, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(getFromServerError(QAbstractSocket::SocketError)));
}

void DialogConn::getFromServerError(QAbstractSocket::SocketError err)
{
    QString strError =
    "Error: "+ (err == QAbstractSocket::HostNotFoundError?
    "The host was not found." :
    err == QAbstractSocket::RemoteHostClosedError?
    "The remote host is closed." :
                        err == QAbstractSocket::ConnectionRefusedError?
                        "The connection was refused." :
                        QString(sock->errorString())
                        ) ;
                        ui->StateChecker->setText(strError);
}

void DialogConn::getDataFromServer()
{
    // получаю объект класса QSettings и вызываю сигнал
    // giveSettings(QSettings&) который передаёт этот объект
    // для основного виджета
    Person person;

    QDataStream in(sock);
    for(;;)
    {
        if(!this->_nextBlockSize)
        {
            if(sock->bytesAvailable() < sizeof(quint16))
            {
                break;
            }
            in >> this->_nextBlockSize;
        }
        if (sock->bytesAvailable() < this->_nextBlockSize){
            break;
        }
        in >> person;
    }

    emit giveSettings(person);
}

void DialogConn::emitQuestToServer()
{
    qDebug() << "connected!";
    // нужно запросить сервер на существование Логина и Пароля в БД на нём.

    QByteArray info;
    QDataStream out(&info, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Version::Qt_5_12);
    out << quint16(0) << this->login << this->password;

    out.device()->seek(0);
    out << quint16(info.size() - sizeof(quint16));

    sock->write(info);
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
