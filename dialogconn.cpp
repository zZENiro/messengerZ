#include "dialogconn.h"
#include "ui_dialogconn.h"


DialogConn::DialogConn(QWidget *parent) :
    QDialog(parent),
    _nextBlockSize(0),
    ui(new Ui::DialogConn)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::WindowType::Popup, true);

    sock = new QTcpSocket(this);
    connect(sock, SIGNAL(connected()), this, SLOT(emitQuestToServer()));
    connect(sock, SIGNAL(readyRead() ), SLOT(getDataFromServer()));
    connect(sock, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(getFromServerError(QAbstractSocket::SocketError)));
    connect(ui->close, SIGNAL(clicked()), this, SLOT(close()));
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
                        sock->flush();

                        sock->disconnectFromHost();
}

void DialogConn::getDataFromServer()
{
    QDataStream in(sock);
    for(; ;)
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
        in >> person >> registrationNeeded >> _badPassword;
    }
    qDebug() << registrationNeeded;
    Registration(registrationNeeded);
    badPassword(_badPassword);
}

void DialogConn::Registration(bool state)
{
    if (state)
    {
        // форма регистрации
        // формой инициализирую объект person
        // и отсылаю на сервер для добавления в БД
        qDebug() << "reggg!";
        //registrationForServer();
        registrationNeeded = false;
    } else {
        // если регистрация не нужна, подключаем пользователя к клиенту
        // и используем настройки Person для персонализации рабочего стола
        return;
    }
}

void DialogConn::badPassword(bool state)
{
    if (state)
    {
        // выдаём ошибку о wrong password
        qDebug() << "Wrong password";
        _badPassword = false;
    }
    else {
        // включаем клиент
    }
}

void DialogConn::emitQuestToServer()
{
    qDebug() << "connected!";
    ui->StateChecker->setText("Connected to server: " + sock->peerName());
    // нужно запросить сервер на существование Логина и Пароля в БД на нём.

    QByteArray info;
    QDataStream out(&info, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Version::Qt_5_12);
    out << quint16(0) << *this->login << *this->password << this->person;

    out.device()->seek(0);
    out << quint16(info.size() - sizeof(quint16));

    sock->write(info);
}

void DialogConn::toConnect(QString adress, quint16 port)
{

    qDebug() << "IP: " + adress + "port: " + QString::number(port);
    sock->connectToHost(adress, port);
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
