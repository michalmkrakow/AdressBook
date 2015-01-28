#ifndef ADRESSBOOK_H
#define ADRESSBOOK_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include "csvcontactserializer.h"
#include "../Data/contact.h"

class AdressBook : public QObject
{
    Q_OBJECT
public:
    explicit AdressBook(QObject *parent = 0);
    QList<Contact*>& getContacts();

signals:
    void dataChanged();

public slots:
    void importFromCsv(const QString& fileName);
    void exportToCsv(const QString& fileName);
    void addContact(Contact * contact);
private:
    ContactSerializer * serializer;
    QList<Contact*> contacts;

};

#endif // ADRESSBOOK_H
