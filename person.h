#ifndef PERSON_H
#define PERSON_H

#include <QPixmap>
#include <QtCore>

class Person
{
    QPixmap* photo;
    QString* name;
    QString* email;

public:
    explicit Person();
    explicit Person(const Person&);

};

#endif // PERSON_H
