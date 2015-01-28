#include "contactwidget.h"

ContactWidget::ContactWidget(QWidget *parent) : QWidget(parent)
{
    this->contact = NULL;
    prepareFormLayout();
}

void ContactWidget::prepareFormLayout()
{
    formLayout = new QFormLayout(this);

    QLabel * nameLabel = new QLabel(tr("Name: "));
    nameEdit = new QLineEdit();
    formLayout->addRow(nameLabel, nameEdit);

    QLabel * surnameLabel = new QLabel(tr("Surname: "));
    surnameEdit = new QLineEdit();
    formLayout->addRow(surnameLabel, surnameEdit);

    QLabel * emailLabel =new QLabel(tr("E-mail: "));
    emailEdit = new QLineEdit();
    formLayout->addRow(emailLabel, emailEdit);

    QLabel * phoneLabel = new QLabel(tr("Phone: "));
    phoneEdit = new QLineEdit();
    formLayout->addRow(phoneLabel, phoneEdit);

    QLabel * commentLabel = new QLabel(tr("Comment: "));
    commentEdit = new QTextEdit();
    formLayout->addRow(commentLabel, commentEdit);

    addButton = new QPushButton(tr("Add"));
    formLayout->addRow(addButton);
    connect(addButton, SIGNAL(clicked()), this, SLOT(createContact()));

    fillFields();
}

void ContactWidget::fillFields()
{
    if(!contact)
    {
        contact = new Contact();
        addButton->setEnabled(true);
    }
    else
    {
        addButton->setEnabled(false);
    }

    nameEdit->setText(contact->getName());
    surnameEdit->setText(contact->getSurname());
    emailEdit->setText(contact->getEmail());
    phoneEdit->setText(contact->getPhone());
    commentEdit->setText(contact->getComment());
}

Contact *ContactWidget::getContact() const
{
    return contact;
}

void ContactWidget::setContact(Contact *value)
{
    contact = value;
    fillFields();
}

void ContactWidget::createContact()
{
    contact->setName(nameEdit->text());
    contact->setSurname(surnameEdit->text());
    contact->setEmail(emailEdit->text());
    contact->setPhone(phoneEdit->text());
    contact->setComment(commentEdit->toPlainText());

    if(contact->isEmpty())
    {
        QMessageBox::information(this, tr("Empty Contact"), tr("You have entered empty contact!\n"), QMessageBox::Ok, 0);
        return;
    }
    emit contactCreated(contact);
}

