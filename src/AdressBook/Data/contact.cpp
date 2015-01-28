#include "contact.h"

Contact::Contact(QObject *parent) : QObject(parent)
{
    name = QString("");
    surname = QString("");
    email = QString("");
    phone = QString("");
    comment = QString("");
}
QString Contact::getName() const
{
    return name;
}

void Contact::setName(const QString &value)
{
    name = value;
}
QString Contact::getSurname() const
{
    return surname;
}

void Contact::setSurname(const QString &value)
{
    surname = value;
}
QString Contact::getEmail() const
{
    return email;
}

void Contact::setEmail(const QString &value)
{
    email = value;
}
QString Contact::getPhone() const
{
    return phone;
}

void Contact::setPhone(const QString &value)
{
    phone = value;
}
QString Contact::getComment() const
{
    return comment;
}

void Contact::setComment(const QString &value)
{
    comment = value;
}

void Contact::fromString(const QString &string)
{
    const QList<QString>& fields = string.split(":");
    if(fields.size() != 5)
    {
        return;
    }

    QListIterator<QString> i(fields);
    while(i.hasNext())
    {
        QString& field = (QString&)i.next();
        field.remove("[\"]*");
    }

    setName(fields.at(0));
    setSurname(fields.at(1));
    setEmail(fields.at(2));
    setPhone(fields.at(3));
    setComment(fields.at(4));
}

QString Contact::toString()
{
    return QString("%1:%2:%3:%4:%5")
            .arg(getName())
            .arg(getSurname())
            .arg(getEmail())
            .arg(getPhone())
            .arg(getComment());

}

bool Contact::isEmpty()
{
    if(name.isEmpty() && surname.isEmpty() && email.isEmpty() && phone.isEmpty() && comment.isEmpty())
    {
        return true;
    }
    return false;
}






