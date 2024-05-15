#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Qlist>
#include <QMainWindow>

class AreaPintar; //donde se pinta

class MainWindow : public QMainWindow //hereda de mainwindow
{
    Q_OBJECT

public:
    MainWindow();


protected:
    void closeEvent(QCloseEvent *event) override;  //cerrar ventana principal

private slots:  // ranuras privadas
    void abrir();
    void guardar();
    void colorLapiz();
    void anchoLapiz();

private:
    void createActions();
    void createMenus();
    bool maybeSave(); //verifica el guardado
    bool guardarArchivo(const QByteArray &fileFormat); //devuelve true si se guarod bien
    AreaPintar *areaPintar;
    QMenu *archivoMenu; //menu
    QMenu *opcionMenu; //menu
    QMenu *figurasMenu; //menu
    QAction *abrirAct;
    QAction *salirAct;
    QAction *colorLapizAct;
    QAction *anchoLapizAct;
    QAction *borrarPantallaAct;
    QAction *borradorAct;
    QAction *figurasAct;
    QAction *guardarComoAct;
    QAction *CuadradoAct;
    QAction *CirculoAct;
    QAction *TrianguloAct;
    QAction *LineaAct;
    QAction *LapizAct;


};
#endif// MAINWINDOW_H
