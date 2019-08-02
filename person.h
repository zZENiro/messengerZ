#ifndef PERSON_H
#define PERSON_H

#include <QPixmap>
#include <QtCore>

class Person : public QString
{
    QPixmap* _photo;
    QString* _name;
    QString* _email;

public:
    explicit Person();
    explicit Person(const Person&);

    QPixmap& photo() { return *this->_photo; }
    QString& name() { return *this->_name; }
    QString& email() { return *this->_email; }
};

#endif // PERSON_H
