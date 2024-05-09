#include <QtWidgets>
#include "mainwindow.h"
#include "areapintar.h"


MainWindow::MainWindow() //interfaz basica
{
    areaPintar = new AreaPintar;
    setCentralWidget(areaPintar);
    createActions(); //llamado
    createMenus();   //llamado
    setWindowTitle(tr("Paintando")); //titulo principal

    resize(500, 500);
}

void MainWindow::closeEvent(QCloseEvent *event){  //cerrar app
    if(maybeSave()){
        event->accept(); //si da aceptar, cierre
    }else{
        event->ignore();  //evita que cierre
    }
}

void MainWindow::abrir()  //verifique si quiere guardar cambios, y luego dialogo
                           //que deje escoger que archivo abrir
{
    if (maybeSave()) {

        QString fileName = QFileDialog::getOpenFileName(this,
                                                        tr("Abrir archivo"), QDir::currentPath());
        if (!fileName.isEmpty())        //Nombre de archivo no vacio
            areaPintar->abrirImagen(fileName);
    }
}

void MainWindow::guardar() {
    QAction *action = qobject_cast<QAction *>(sender());
    QByteArray fileFormat = action->data().toByteArray();
    guardarArchivo(fileFormat);
}


void MainWindow::colorLapiz(){  //cambiar color
    QColor nuevoColor = QColorDialog::getColor(areaPintar->colorLapiz());
    if(nuevoColor.isValid())
        areaPintar->setColorLapiz(nuevoColor); //actualiza en area de pintura
}

void MainWindow::anchoLapiz(){
    bool valido;
    int nuevoAncho = QInputDialog::getInt(this, tr("Cambiar ancho"),  //dialogo principal
                                          tr("Seleccione ancho del lápiz : "),
                                          areaPintar->anchoLapiz(),
                                          1, 200, 1, &valido); //minimo, maximo y seguido de a 1

    if(valido)
        areaPintar->setAnchoLapiz(nuevoAncho);
}


void MainWindow::createActions(){

    abrirAct = new QAction(tr("&Abrir..."), this);
    connect(abrirAct, SIGNAL(triggered()), this, SLOT(abrir()));

    salirAct = new QAction(tr("&Salir"), this);
    connect(salirAct, SIGNAL(triggered()), this, SLOT(close()));

    colorLapizAct = new QAction(tr("&Color del lapiz..."), this);
    connect(colorLapizAct, SIGNAL(triggered()), this, SLOT(colorLapiz()));

    anchoLapizAct = new QAction(tr("Ancho del &Trazo..."), this);
    connect(anchoLapizAct, SIGNAL(triggered()), this, SLOT(anchoLapiz()));

    borrarPantallaAct = new QAction(tr("&Borrar pantalla..."), this);
    connect(borrarPantallaAct, SIGNAL(triggered()), areaPintar, SLOT(clearImage()));

    borradorAct = new QAction(tr("&Borrador..."), this);
    connect(borradorAct, SIGNAL(triggered()), areaPintar, SLOT(borrador()));

    figurasAct = new QAction(tr("&Figuras..."), this);
    connect(figurasAct, SIGNAL(triggered()), areaPintar, SLOT(figuras()));

    foreach (QAction *action, guardarComoActs)
        connect(action, SIGNAL(triggered()), this, SLOT(guardar()));

}


void MainWindow::createMenus()
{

    guardarComoMenu = new QMenu(tr("&Guardar como"), this);
    foreach (QAction *action, guardarComoActs)
        guardarComoMenu->addAction(action);

    //darle funciones al apartado de archivo
    archivoMenu = new QMenu(tr("&Archivo"), this);
    archivoMenu->addAction(abrirAct);
    archivoMenu->addMenu(guardarComoMenu);
    archivoMenu->addSeparator();
    archivoMenu->addAction(salirAct);

    //darle funciones apartado menu
    opcionMenu = new QMenu(tr("&Opciones"), this);
    opcionMenu->addAction(colorLapizAct);
    opcionMenu->addAction(anchoLapizAct);
    opcionMenu->addAction(borradorAct);
    opcionMenu->addAction(figurasAct);
    opcionMenu->addSeparator();
    opcionMenu->addAction(borrarPantallaAct);


    //añade los menus a la barra de menus
    menuBar()->addMenu(archivoMenu);
    menuBar()->addMenu(opcionMenu);
}

bool MainWindow::maybeSave()
{
    // revisar si hay cambios
    if (areaPintar->isModified()) {
        QMessageBox::StandardButton advertencia;


        advertencia = QMessageBox::warning(this, tr("Advertencia"),
                                   tr("La imagen ha sido modificada.\n"
                                      "¿Deseas Guardar los cambios?"),
                                   QMessageBox::Save | QMessageBox::Discard
                                       | QMessageBox::Cancel);


        if (advertencia == QMessageBox::Save) {
            return guardarArchivo("png");


        } else if (advertencia == QMessageBox::Cancel) {
            return false;
        }
    }
    return true;  //no hay cambios
}
bool MainWindow::guardarArchivo(const QByteArray &fileFormat) {
    QString initialPath = QDir::currentPath() + "/untitled." + QString(fileFormat);
    QString filter = tr("%1 Files (*.%2);;All Files (*)")
                         .arg(QString::fromLatin1(fileFormat.toUpper()))
                         .arg(QString::fromLatin1(fileFormat));
    QString fileName = QFileDialog::getSaveFileName(this, tr("Guardar como"), initialPath, filter);

    if (fileName.isEmpty())
        return false;
    else
        return areaPintar->guardarImagen(fileName, fileFormat.constData());
}


