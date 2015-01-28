#include "adressbookwidget.h"

AdressBookWidget::AdressBookWidget(QWidget *parent) : QMainWindow(parent), contacts(model.getContacts())
{
    prepareMainLayout();
    prepareMenuBar();
    connect(&model, SIGNAL(dataChanged()), this, SLOT(refreshContactList()));
    connect(contactWidget, SIGNAL(contactCreated(Contact*)), &model, SLOT(addContact(Contact*)));
}

void AdressBookWidget::changeContact(QListWidgetItem *item)
{
    ContactListWidgetItem * contactItem = dynamic_cast<ContactListWidgetItem*>(item);
    if(!contactItem)
    {
        contactWidget->setContact(NULL);
        return;
    }

    contactWidget->setContact(contactItem->getContact());
}

void AdressBookWidget::askAboutImportFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open csv File"), "C:\\", tr("csv (*.csv)"));
    model.importFromCsv(fileName);
}

void AdressBookWidget::askAboutExportFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save csv File"), "C:\\", tr("csv (*.csv)"));
    model.exportToCsv(fileName);
}

void AdressBookWidget::refreshContactList()
{
    contactListWidget->clear();
    ContactListWidgetItem * contactItem;
    foreach (Contact* contact, contacts)
    {
        contactItem = new ContactListWidgetItem(contact);
        contactListWidget->addItem(contactItem);
    }

    contactListWidget->addItem(tr("Add new"));
}

void AdressBookWidget::prepareMainLayout()
{
    mainWidget = new QWidget(this);
    mainLayout = new QHBoxLayout(mainWidget);
    prepareContactList();
    mainLayout->addWidget(contactListWidget);
    prepareContactWidget();
    mainLayout->addWidget(contactWidget);
    setCentralWidget(mainWidget);
}

void AdressBookWidget::prepareContactList()
{
    contacts = model.getContacts();

    contactListWidget = new QListWidget();
    ContactListWidgetItem * contactItem;
    foreach (Contact* contact, contacts)
    {
        contactItem = new ContactListWidgetItem(contact);
        contactListWidget->addItem(contactItem);
    }

    contactListWidget->addItem(tr("Add new"));

    connect(contactListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(changeContact(QListWidgetItem*)));
}

void AdressBookWidget::prepareContactWidget()
{
    contactWidget = new ContactWidget();
}

void AdressBookWidget::prepareMenuBar()
{
    menuBar = new QMenuBar();
    setMenuBar(menuBar);
    QMenu * fileMenu = menuBar->addMenu(tr("&File"));

    importCsvAction = new QAction(tr("&Open .csv"), this);
    fileMenu->addAction(importCsvAction);
    connect(importCsvAction, SIGNAL(triggered()), this, SLOT(askAboutImportFile()));

    exportCsvAction = new QAction(tr("&Save .csv"), this);
    fileMenu->addAction(exportCsvAction);
    connect(exportCsvAction, SIGNAL(triggered()), this, SLOT(askAboutExportFile()));

}
