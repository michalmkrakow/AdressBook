#ifndef ADRESSBOOKWIDGET_H
#define ADRESSBOOKWIDGET_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QListWidget>
#include <QMenuBar>
#include <QFileDialog>

#include "contactwidget.h"
#include "contactlistwidgetitem.h"
#include "../Data/contact.h"
#include "../Model/adressbook.h"

class AdressBookWidget : public QMainWindow
{
    Q_OBJECT
public:
    explicit AdressBookWidget(QWidget *parent = 0);
public slots:
    void changeContact(QListWidgetItem* item);
    void askAboutImportFile();
    void askAboutExportFile();
private slots:
    void refreshContactList();
private:
    void prepareMainLayout();
    void prepareContactList();
    void prepareContactWidget();
    void prepareMenuBar();

    QListWidget * contactListWidget;
    ContactWidget * contactWidget;
    QWidget * mainWidget;
    QHBoxLayout * mainLayout;

    QMenuBar * menuBar;
    QAction * importCsvAction;
    QAction * exportCsvAction;

    QList<Contact*>& contacts;
    AdressBook model;

};

#endif // ADRESSBOOKWIDGET_H
