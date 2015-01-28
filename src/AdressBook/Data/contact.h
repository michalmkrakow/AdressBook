#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>
#include <QListIterator>
#include <QStringList>

class Contact : public QObject
{
    Q_OBJECT
public:
    explicit Contact(QObject *parent = 0);

public slots:
    QString getName() const;
    void setName(const QString &value);
    QString getSurname() const;
    void setSurname(const QString &value);
    QString getEmail() const;
    void setEmail(const QString &value);
    QString getPhone() const;
    void setPhone(const QString &value);
    QString getComment() const;
    void setComment(const QString &value);

    void fromString(const QString& string);
    QString toString();

    bool isEmpty();

signals:
    void dataChanged();

private:
    QString name;
    QString surname;
    QString email;
    QString phone;
    QString comment;

};

#endif // CONTACT_H
