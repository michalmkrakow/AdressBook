#include "adressbook.h"

AdressBook::AdressBook(QObject *parent) : QObject(parent)
{
    serializer = new CsvContactSerializer(this);

    Contact * contact;
    contact = new Contact();
    contact->setName("Bill");
    contact->setSurname("Gates");
    contact->setEmail("gates@microsoft.com");
    contact->setPhone("48 545 454 987");
    contact->setComment("Rich Man");
    contacts.append(contact);

    contact = new Contact();
    contact->setName("Justin");
    contact->setSurname("Bieber");
    contact->setEmail("bieber@xxx.com");
    contact->setPhone("48 222 333 444");
    contact->setComment("Canadian singer and songwriter. Bieber's current manager, Scooter Braun first discovered him through his YouTube videos in 2007.");
    contacts.append(contact);

    contact = new Contact();
    contact->setName("Steve");
    contact->setSurname("Jobs");
    contact->setEmail("steve@apple.com");
    contact->setPhone("48 236 743 672");
    contact->setComment("Dead");
    contacts.append(contact);

    contact = new Contact();
    contact->setName("Donald");
    contact->setSurname("Tusk");
    contact->setEmail("tusk@eu.eu");
    contact->setPhone("48 213 157 222");
    contact->setComment("In exile");
    contacts.append(contact);
}

QList<Contact *> &AdressBook::getContacts()
{
    return contacts;
}

void AdressBook::importFromCsv(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug("Could not open a file!!!\n");
        return;
    }
    QString input(file.readAll());
    contacts.append(serializer->readContacts(input));
    emit dataChanged();
    file.close();
}

void AdressBook::exportToCsv(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qDebug("%d\n", file.error());
        qDebug("Could not open a file!!!\n");
        return;
    }
    QTextStream out(&file);
    out << serializer->writeContacts(contacts) << "\n";
    file.close();
}

void AdressBook::addContact(Contact *contact)
{
    contacts.append(contact);
    dataChanged();
}

