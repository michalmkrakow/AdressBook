#include "contactlistwidgetitem.h"

ContactListWidgetItem::ContactListWidgetItem(Contact *contact, QListWidget *parent, int type) : QListWidgetItem(parent, type)
{
    this->contact = contact;
}

QVariant ContactListWidgetItem::data(int role) const
{
    if(role == Qt::DisplayRole)
    {
        return contact->getName() + QString(" ") + contact->getSurname();
    }
    return QVariant();
}
Contact *ContactListWidgetItem::getContact() const
{
    return contact;
}

