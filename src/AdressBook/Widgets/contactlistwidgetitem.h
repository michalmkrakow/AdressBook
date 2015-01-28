#ifndef CONTACTLISTWIDGETITEM_H
#define CONTACTLISTWIDGETITEM_H

#include <QListWidgetItem>
#include "../Data/contact.h"

class ContactListWidgetItem : public QListWidgetItem
{
public:
    ContactListWidgetItem(Contact *contact, QListWidget * parent = 0, int type = UserType);
    QVariant data(int role) const;
    Contact *getContact() const;
private:
    Contact * contact;
};

#endif // CONTACTLISTWIDGETITEM_H
