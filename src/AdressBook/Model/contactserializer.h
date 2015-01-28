#ifndef CONTACTSERIALIZER_H
#define CONTACTSERIALIZER_H

#include <QObject>
#include "../Data/contact.h"

class ContactSerializer : public QObject
{
    Q_OBJECT
public:
    explicit ContactSerializer(QObject *parent = 0);
    virtual QList<Contact *> readContacts(QString &string) = 0;
    virtual QString writeContacts(QList<Contact*> contacts) = 0;
};

#endif // CONTACTSERIALIZER_H
