#ifndef AREAPINTAR_H  //predeterminado
#define AREAPINTAR_H //predetermiando

#include <QColor>  //manejo de colores
#include <QImage>  //manejo de imagenes
#include <QPoint>  //manejo de  puntos
#include <QWidget> //manejo de widgets

class AreaPintar : public QWidget //Define la clase hereda de qwidget
{
    Q_OBJECT

public:  //eventos publicos
    AreaPintar(QWidget *parent = 0); //constructor
    bool abrirImagen(const QString &filename);  //funcion abrir imagen
    bool guardarImagen(const QString &filename, const char *fileformat);  //funcion guardarImagen
    void setColorLapiz(const QColor &nuevoColor); //Funcion ponerle color lapzi
    void setAnchoLapiz(int nuevoAncho);  //funcion ancho lapiz

    //van con return porque devuelven un valor en especifico
    bool isModified() const {return modified;}  //si la imagen ha sido modificada
    QColor colorLapiz() const {return myColorLapiz;}
    int anchoLapiz() const {return myAnchoLapiz;}

public slots:
    void clearImage();
    void borrador();
    void linea();
    void circulo();
    void cuadrado();
    void triangulo();
    void lapiz();



protected:  //se accede desde la clase y sus subclases
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override; //ACTUALIZAR DONDE PINTAMOS
    void resizeEvent(QResizeEvent *event) override;

private: //solo donde estan definidos y ya
    void dibujarLinea(const QPoint &endPoint);
    void redimensionImagen(QImage *image, const QSize &newSize);
    bool modified; //F o V depende usuario
    bool dibujando; //F o V depende usuario
    int myAnchoLapiz;
    QColor myColorLapiz;
    QImage image; //almacena la imagen
    QPoint inicioMouse; //variable para figuras
    QPoint finalMouse;  //variable para figuras
    bool dibujarCuadrado; //funcion dibujar bool retorna f o v
    bool dibujarCirculo;  //funcion dibujar bool retorna f o v
    bool dibujarTriangulo;  //funcion dibujar bool retorna f o v
    bool dibujarLineaActiva;  //funcion dibujar bool retorna f o v
    bool dibujarLapiz; // Nueva bandera para el modo lápiz

    void dibujarLineaRecta(const QPoint &startPoint, const QPoint &endPoint);
};

#endif// AREAPINTAR_H
