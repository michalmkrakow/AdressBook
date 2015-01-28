#ifndef CSVCONTACTSERIALIZER_H
#define CSVCONTACTSERIALIZER_H

#include "contactserializer.h"

class CsvContactSerializer : public ContactSerializer
{
    Q_OBJECT
public:
    explicit CsvContactSerializer(QObject *parent = 0);
    QList<Contact *> readContacts(QString &string);
    QString writeContacts(QList<Contact*> contacts);

signals:

public slots:

};

#endif // CSVCONTACTSERIALIZER_H
