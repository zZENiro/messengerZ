#include "loginplatform.h"
#include "ui_loginplatform.h"
#include <QRegExpValidator>
#include <QKeyEvent>
#include <QDialog>

// client

LoginPlatform::LoginPlatform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginPlatform)
{
    ui->setupUi(this);
    settingsForUi();



}

void LoginPlatform::settingsForUi()
{
    ui->ip_1st->installEventFilter(this);
    ui->ip_2nd->installEventFilter(this);
    ui->ip_3rd->installEventFilter(this);
    ui->ip_4th->installEventFilter(this);

    QRegExp rx ( "^(0|[1-9]|[1-9][0-9]|1[0-9][0-9]|2([0-4][0-9]|5[0-5]))$" );
    QValidator *validator = new QRegExpValidator(rx, this);

    ui->ip_1st->setValidator(validator);
    ui->ip_2nd->setValidator(validator);
    ui->ip_3rd->setValidator(validator);
    ui->ip_4th->setValidator(validator);
}

bool LoginPlatform::eventFilter(QObject *target, QEvent *kevent)
{
    if(kevent->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = dynamic_cast<QKeyEvent *>(kevent);
        if(keyEvent)
        {
            //F O R W A R D :
            if(target == ui->ip_1st ||
                    target == ui->ip_2nd ||
                    target == ui->ip_3rd)
            {
                switch(keyEvent->key())
                {
                case Qt::Key_Period:
                    focusNextChild();
                    return true;
                    break;

                case Qt::Key_Comma:
                    focusNextChild();
                    return true;
                    break;

                case Qt::Key_Right:
                    if(target == ui->ip_1st)
                    {
                        if(ui->ip_1st->text().isEmpty() ||
                                (ui->ip_1st->text().size() == ui->ip_1st->cursorPosition()))
                        {
                            ui->ip_2nd->setFocus();
                            ui->ip_2nd->setCursorPosition(0);
                        }
                        else break;
                    }
                    else if(target == ui->ip_2nd)
                    {
                        if(ui->ip_2nd->text().isEmpty() ||
                                (ui->ip_2nd->text().size() == ui->ip_2nd->cursorPosition()))
                        {
                            ui->ip_3rd->setFocus();
                            ui->ip_3rd->setCursorPosition(0);
                        }
                        else break;
                    }
                    else if(target == ui->ip_3rd)
                    {
                        if(ui->ip_3rd->text().isEmpty() ||
                                (ui->ip_3rd->text().size() == ui->ip_3rd->cursorPosition()))
                        {
                            ui->ip_4th->setFocus();
                            ui->ip_4th->setCursorPosition(0);
                        }
                        else break;
                    }
                    return true;
                    break;

                case Qt::Key_0:
                    if(target == ui->ip_1st)
                    {
                        if(ui->ip_1st->text() == "0")
                        {
                            focusNextChild();
                        }
                        else break;
                    }
                    if(target == ui->ip_2nd)
                    {
                        if(ui->ip_2nd->text() == "0")
                        {
                            focusNextChild();
                        }
                        else break;
                    }
                    if(target == ui->ip_3rd)
                    {
                        if(ui->ip_3rd->text() == "0")
                        {
                            focusNextChild();
                        }
                        else break;
                    }
                    return true;
                    break;

                case Qt::Key_Delete:
                    if(target == ui->ip_1st)
                    {
                        if(ui->ip_1st->text().isEmpty() ||
                                ui->ip_1st->text().size() == ui->ip_1st->cursorPosition())
                        {
                            ui->ip_2nd->setFocus();
                            ui->ip_2nd->setCursorPosition(0);
                        }
                        else break;
                    }
                    if(target == ui->ip_2nd)
                    {
                        if(ui->ip_2nd->text().isEmpty() ||
                                ui->ip_2nd->text().size() == ui->ip_2nd->cursorPosition())
                        {
                            ui->ip_3rd->setFocus();
                            ui->ip_3rd->setCursorPosition(0);
                        }
                        else break;
                    }
                    if(target == ui->ip_3rd)
                    {
                        if(ui->ip_3rd->text().isEmpty() ||
                                ui->ip_3rd->text().size() == ui->ip_3rd->cursorPosition())
                        {
                            ui->ip_4th->setFocus();
                            ui->ip_4th->setCursorPosition(0);
                        }
                        else break;
                    }
                    return true;
                    break;
                default:
                    break;
                }
            }

            //B A C K W A R D :
            if(target == ui->ip_2nd ||
                    target == ui->ip_3rd ||
                    target == ui->ip_4th)
            {
                switch(keyEvent->key())
                {
                case Qt::Key_Left:
                    if(target == ui->ip_4th)
                    {
                        if(ui->ip_4th->text().isEmpty() ||
                                ui->ip_4th->cursorPosition() == 0)
                        {
                            ui->ip_3rd->setFocus();
                            ui->ip_3rd->setCursorPosition(ui->ip_3rd->text().size());
                        }
                        else break;
                    }
                    if(target == ui->ip_3rd)
                    {
                        if(ui->ip_3rd->text().isEmpty() ||
                                ui->ip_3rd->cursorPosition() == 0)
                        {
                            ui->ip_2nd->setFocus();
                            ui->ip_2nd->setCursorPosition(ui->ip_2nd->text().size());
                        }
                        else break;
                    }
                    if(target == ui->ip_2nd)
                    {
                        if(ui->ip_2nd->text().isEmpty() ||
                                ui->ip_2nd->cursorPosition() == 0)
                        {
                            ui->ip_1st->setFocus();
                            ui->ip_1st->setCursorPosition(ui->ip_1st->text().size());
                        }
                        else break;
                    }
                    return true;
                    break;

                case Qt::Key_Backspace:
                    if(target == ui->ip_4th)
                    {
                        if(ui->ip_4th->text().isEmpty() ||
                                ui->ip_4th->cursorPosition() == 0)
                        {
                            ui->ip_3rd->setFocus();
                            ui->ip_3rd->setCursorPosition(ui->ip_3rd->text().size());
                        }
                        else break;
                    }
                    if(target == ui->ip_3rd)
                    {
                        if(ui->ip_3rd->text().isEmpty() ||
                                ui->ip_3rd->cursorPosition() == 0)
                        {
                            ui->ip_2nd->setFocus();
                            ui->ip_2nd->setCursorPosition(ui->ip_2nd->text().size());
                        }
                        else break;
                    }
                    if(target == ui->ip_2nd)
                    {
                        if(ui->ip_2nd->text().isEmpty() ||
                                ui->ip_2nd->cursorPosition() == 0)
                        {
                            ui->ip_1st->setFocus();
                            ui->ip_1st->setCursorPosition(ui->ip_1st->text().size());
                        }
                        else break;
                    }
                    return true;
                    break;

                default:
                    break;
                }
            }
        }
    }

    return QMainWindow::eventFilter(target, kevent);
}

LoginPlatform::~LoginPlatform()
{
    delete ui;
}

void LoginPlatform::on_ip_1st_textChanged(const QString&)
{
    IPadress_1 = ui->ip_1st->text();
    IPadress = IPadress_1 + "." + IPadress_2 + "." + IPadress_3 + "." + IPadress_4;
    if(ui->ip_1st->text().size() == 3 &&
            ui->ip_1st->text().size() == ui->ip_1st->cursorPosition())
    {
        ui->ip_2nd->setFocus();
        ui->ip_2nd->selectAll();
    }
}

void LoginPlatform::on_ip_2nd_textChanged(const QString&)
{
    IPadress_2 = ui->ip_2nd->text();
    IPadress = IPadress_1 + "." + IPadress_2 + "." + IPadress_3 + "." + IPadress_4;
    if(ui->ip_2nd->text().size() == 3 &&
            ui->ip_2nd->text().size() == ui->ip_2nd->cursorPosition())
    {
        ui->ip_3rd->setFocus();
        ui->ip_3rd->selectAll();
    }
}

void LoginPlatform::on_ip_3rd_textChanged(const QString&)
{
    IPadress_3 = ui->ip_3rd->text();
    IPadress = IPadress_1 + "." + IPadress_2 + "." + IPadress_3 + "." + IPadress_4;
    if(ui->ip_3rd->text().size() == 3 &&
            ui->ip_3rd->text().size() == ui->ip_3rd->cursorPosition())
    {
        ui->ip_4th->setFocus();
        ui->ip_4th->selectAll();
    }
}

void LoginPlatform::on_ip_4th_textChanged(const QString&)
{
    IPadress_4 = ui->ip_4th->text();
    IPadress = IPadress_1 + "." + IPadress_2 + "." + IPadress_3 + "." + IPadress_4;
}

void LoginPlatform::on_passEdit_6_textChanged(const QString&)
{
    port = ui->port_lbl->text();
}
