#include "MainWindow.h"

#include <QApplication>
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    application.setApplicationName("PurpleNavigator");
    application.setOrganizationName("PurpleNavigator");

    QFont font = application.font();
    font.setPointSize(font.pointSize() + 1);
    application.setFont(font);

    MainWindow window;
    window.show();

    return application.exec();
}