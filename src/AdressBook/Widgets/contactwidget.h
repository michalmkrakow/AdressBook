#ifndef CONTACTWIDGET_H
#define CONTACTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QFormLayout>
#include <QPushButton>
#include <QMessageBox>
#include "../Data/contact.h"

/**
 * @brief ContactWidget class odpowiada za wyświetlenie jednego kontaktu.
 *
 * @class ContactWidget class wyświetla kontakt w formie formularza który pozwala modyfikować pola na bierząco.
 * Pola są umieszczone w układzie formularza i automatycznie dostosowują się do rozmiaru okna.
 *
 * @author (mielecmichal@gmail.com)
 *
 * @see QWidget
 * @see QFormLayout
 */
class ContactWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ContactWidget(QWidget *parent = 0);

    /**
     * @brief getContact zwraca aktualnie wyświetlany kontakt
     * @return aktualnie wyświetlany kontakt
     */
    Contact *getContact() const;

    /**
     * @brief setContact ustawia kontakt do wyświetlenia
     * @param value wskaźnik na nowy kontakt do wyświetlenia
     */
    void setContact(Contact *value);

signals:
    /**
     * @brief contactCreated emitowany gdy użytkownik wpisał nowy kontakt do pustego formularza
     */
    void contactCreated(Contact*);

protected slots:
    void createContact();

protected:
    void prepareFormLayout();
    void fillFields();

    QLineEdit * nameEdit;
    QLineEdit * surnameEdit;
    QLineEdit * emailEdit;
    QLineEdit * phoneEdit;
    QTextEdit * commentEdit;

    QPushButton * addButton;
    QFormLayout * formLayout;

    Contact * contact;
};

#endif // CONTACTWIDGET_H
