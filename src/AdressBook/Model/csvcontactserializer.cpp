#include "csvcontactserializer.h"
#include <QDebug>
CsvContactSerializer::CsvContactSerializer(QObject *parent) : ContactSerializer(parent)
{
}

QList<Contact *> CsvContactSerializer::readContacts(QString & string)
{
    Contact* contact;
    QList<Contact*> contacts;
    const QList<QString>& rows = string.split("\n");
    foreach(const QString& row, rows)
    {
        if(!row.isEmpty())
        {
            contact = new Contact();
            contact->fromString(row);
            contacts.append(contact);
        }
    }
    return contacts;
}

QString CsvContactSerializer::writeContacts(QList<Contact *> contacts)
{
    QString output;
    foreach(Contact* contact, contacts)
    {
        output.append(contact->toString());
        output.append("\n");
    }
    return output;
}
