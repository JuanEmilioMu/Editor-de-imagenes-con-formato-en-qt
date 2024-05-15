#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv); //aplicacion principal

    MainWindow window; //crear ventana principal
    window.show();  //mostrar la ventana principal

    return app.exec();  //ejecutar la ventana principal
}
