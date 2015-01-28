#ifndef USER_H
#define USER_H

#include <QObject>
#include "./Model/adressbook.h"

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = 0);

    QString getLogin() const;
    void setLogin(const QString &value);

    QString getPassword() const;
    void setPassword(const QString &value);

    AdressBook getAdressBook() const;
    void setAdressBook(const AdressBook &value);

    void addAdressBook(const AdressBook*);
    void deleteAdressBook(const AdressBook*);

signals:

public slots:

private:
    QString login;
    QString password;
    List<AdressBook*> adressBooks;
};

#endif // USER_H
