#include <QApplication>
#include "Widgets/adressbookwidget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);;

    AdressBookWidget u;
    u.show();

    return a.exec();
}
