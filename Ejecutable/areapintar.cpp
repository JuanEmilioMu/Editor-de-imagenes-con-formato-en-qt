#include <QtWidgets>
#include <QDebug>
#include "areapintar.h"

// Constructor
AreaPintar::AreaPintar(QWidget *parent) : QWidget(parent)
{
    modified = false;
    dibujando = false;
    myAnchoLapiz = 10;
    myColorLapiz = Qt::black;
    dibujarCuadrado = false;
    dibujarCirculo = false;
    dibujarTriangulo = false;
    dibujarLineaActiva = false;
    dibujarLapiz = true;
}

// Carga imagenes y se almacena en image
bool AreaPintar::abrirImagen(const QString &fileName)
{
    if (!QFile::exists(fileName)) {
        QMessageBox::critical(nullptr, tr("Error"), tr("El archivo especificado no existe."));
        return false;
    }
    QImage loadedImage;
    if (!loadedImage.load(fileName))
        return false;

    QSize newSize = loadedImage.size().expandedTo(size());
    redimensionImagen(&loadedImage, newSize);
    image = loadedImage;
    modified = false;
    update();
    return true;
}

// Guarda la imagen
bool AreaPintar::guardarImagen(const QString &fileName, const char *fileFormat)
{
    QImage visibleImage = image;
    redimensionImagen(&visibleImage, size());

    if (visibleImage.save(fileName, fileFormat)) {
        modified = false;
        return true;
    } else {
        return false;
    }
}

// Cambia el color del lápiz
void AreaPintar::setColorLapiz(const QColor &nuevoColor)
{
    myColorLapiz = nuevoColor;
}

// Cambia el ancho del lápiz
void AreaPintar::setAnchoLapiz(int nuevoAncho)
{
    myAnchoLapiz = nuevoAncho;
}

// Limpia la imagen
void AreaPintar::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    modified = true;
    update();
}

// Funciones para dibujar las formas
void AreaPintar::cuadrado()  //ignorar todas menos cuadrado
{
    dibujarCuadrado = true;
    dibujarCirculo = false;
    dibujarTriangulo = false;
    dibujarLineaActiva = false;
    dibujarLapiz = false;
}

void AreaPintar::triangulo()  //ignorar todas menos triangulo
{
    dibujarCuadrado = false;
    dibujarCirculo = false;
    dibujarTriangulo = true;
    dibujarLineaActiva = false;
    dibujarLapiz = false;
}

void AreaPintar::circulo()  //ignorar todas menos circulo
{
    dibujarCuadrado = false;
    dibujarCirculo = true;
    dibujarTriangulo = false;
    dibujarLineaActiva = false;
    dibujarLapiz = false;
}

void AreaPintar::linea()   //ignorar todas menos linea
{
    dibujarCuadrado = false;
    dibujarCirculo = false;
    dibujarTriangulo = false;
    dibujarLineaActiva = true;
    dibujarLapiz = false;
}

void AreaPintar::lapiz()   //ignorar todas menos lapiz
{
    dibujarCuadrado = false;
    dibujarCirculo = false;
    dibujarTriangulo = false;
    dibujarLineaActiva = false;
    dibujarLapiz = true;
}

// Cambia el lápiz a borrador
void AreaPintar::borrador()
{
    myColorLapiz = Qt::white;

    dibujarLapiz = true;
}

// Eventos del mouse
void AreaPintar::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        inicioMouse = event->pos();
        dibujando = true;
    }
}

void AreaPintar::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && dibujando && dibujarLapiz) {
        dibujarLinea(event->pos());
    }
}

void AreaPintar::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && dibujando) {  //verifica si suelta el boton y si esta dibujando
        finalMouse = event->pos(); //guarda donde termina
        dibujando = false; //no dibuja
        if (dibujarLineaActiva) {
            dibujarLineaRecta(inicioMouse, finalMouse);
        } else if (dibujarCuadrado) { //si cuadrado es V haga:
            QPainter painter(&image); //Cree lienzo
            QPen pen(myColorLapiz, myAnchoLapiz, Qt::SolidLine, Qt::SquareCap);  //tome los ultimos valores del lapiz
            painter.setPen(pen);
            QRect rect(inicioMouse, finalMouse);  //hace el cuadrado de donde empieza el mouse hasta donde lo suelta
            painter.drawRect(rect);
            modified = true;
        } else if (dibujarTriangulo) {  //si esta triangulo v haga:
            QPainter painter(&image); //Cree lienzo
            QPen pen(myColorLapiz, myAnchoLapiz, Qt::SolidLine, Qt::SquareCap); //tome los ultimos valores del lapiz
            painter.setPen(pen);
            QPolygon triangle; //poligono tipo triangulo
            triangle << inicioMouse  //vertice 1
                     << QPoint(finalMouse.x(), inicioMouse.y()) //vertice 2
                     << finalMouse;  //vertice 3
            painter.drawPolygon(triangle);
            modified = true;
        } else if (dibujarCirculo) {  //si circulo es V haga:
            QPainter painter(&image); //cree lienzo
            QPen pen(myColorLapiz, myAnchoLapiz, Qt::SolidLine, Qt::SquareCap); //tome los ultimos valores del lapiz
            painter.setPen(pen);
            QRect rect(inicioMouse, finalMouse); //dibuja elipse desde inicio hasta donde se suelta el mouse
            painter.drawEllipse(rect);
            modified = true;
        }
        update();  //actualiza interfaz
    }
}


// Redibuja la imagen
void AreaPintar::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}

// Redimensiona la imagen
void AreaPintar::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height()) {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        redimensionImagen(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

// Dibuja una línea
void AreaPintar::dibujarLinea(const QPoint &endPoint)
{
    QPainter painter(&image);
    QPen pen(myColorLapiz, myAnchoLapiz, Qt::SolidLine, Qt::SquareCap);
    painter.setPen(pen);
    painter.drawLine(inicioMouse, endPoint);
    modified = true;

    int rad = (myAnchoLapiz / 2) + 2;
    update(QRect(inicioMouse, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
    inicioMouse = endPoint;
}

// Redimensiona la imagen
void AreaPintar::redimensionImagen(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void AreaPintar::dibujarLineaRecta(const QPoint &inicioMouse, const QPoint &finalMouse) {    //funcion que es llamada en
    QPainter painter(&image);                                    //mousereleaseevent (permite linea recta)
    painter.begin(&image); // Inicia el pintor
    QPen pen(myColorLapiz, myAnchoLapiz, Qt::SolidLine, Qt::SquareCap);
    painter.setPen(pen);
    painter.drawLine(inicioMouse, finalMouse);
    modified = true;
    painter.end(); // Termina el pintor
    update();
}

