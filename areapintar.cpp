#include <QtWidgets>
#include<QDebug>
#include "areapintar.h"

//funcion inicial
AreaPintar::AreaPintar(QWidget *parent) : QWidget(parent) //constructor que hereda de qwidget
{
    modified = false;
    dibujando = false;
    myAnchoLapiz = 10; //ancho inicial
    myColorLapiz = Qt::black; //color inicial
}

//Carga imagenes y se almacena en image
bool AreaPintar::abrirImagen(const QString &fileName)  //manejo de archivos
{
    if (!QFile::exists(fileName)) { //sino existe
        // Mostrar un mensaje de error al usuario si el archivo no existe
        QMessageBox::critical(nullptr, tr("Error"), tr("El archivo especificado no existe."));
        return false;
    }
    QImage loadedImage;  //si si existe carga la imagen
    if (!loadedImage.load(fileName))
        return false; //de lo contrario false

            //verifica si esa imagen que subio cumple con las medidas
    QSize newSize = loadedImage.size().expandedTo(size());
    redimensionImagen(&loadedImage, newSize);
    image = loadedImage;
    modified = false;
    update();
    return true;
}

//igualo visibleimage con image, si el guardado es exitoso devuelva verdadero
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

//cambiar color lapiz
void AreaPintar::setColorLapiz(const QColor &nuevoColor){
    myColorLapiz = nuevoColor;
}
//Cambiar ancho lapiz
void AreaPintar::setAnchoLapiz(int nuevoAncho){
    myAnchoLapiz = nuevoAncho;
}

//pone blanco toda la pantalla
void AreaPintar::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    modified = true;
    update();
}

//borrador
void AreaPintar::borrador(){
    myColorLapiz = Qt::white;
    myAnchoLapiz = 10;
}

//cuando se presione el boron izquierdo, guarda la posicion
//en ultimo punto
void AreaPintar::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        ultimoPunto = event->pos();
        dibujando = true;
    }
}

// si el mouse se mueve mientras esta clickeado se llama la funcion dibujarlinea que hace una linea
//desde donde estaba a donde quedo
void AreaPintar::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && dibujando)
        dibujarLinea(event->pos());
}

//Dejar de dibujar
void AreaPintar::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton && dibujando){
        dibujarLinea(event ->pos());
        dibujando = false;
    }
}

void AreaPintar::paintEvent(QPaintEvent *event) //crea un rectangulo sucio en
//dond ehay una modficacion para saber donde fue actualizad y rinda mejor
{
    QPainter painter(this);
    QRect rectSucio = event->rect();
    painter.drawImage(rectSucio, image, rectSucio);
}


void AreaPintar::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height()) { //comprueba si se tiene que redimensionar o no
        int nuevoAncho = qMax(width() + 135, image.width()); //VAL MAX entre 2 numeros, 128 pixeles mas que
        int nuevoAlto = qMax(height() + 135, image.height()); //alto y el ancho
        redimensionImagen(&image, QSize(nuevoAncho, nuevoAlto));
        update();
    }
    QWidget::resizeEvent(event);
}

void AreaPintar::dibujarLinea(const QPoint &puntoFinal)
{
    // dibujar en la imagen
    QPainter painter(&image);

    // establecer la configuracioon del lapiz
    painter.setPen(QPen(myColorLapiz, myAnchoLapiz, Qt::SolidLine, Qt::SquareCap));

    painter.drawLine(ultimoPunto, puntoFinal);

    modified = true;

    int rad = (myAnchoLapiz / 2) + 2; //+2 por cualquer variacion pixeles
                                     //cercanos

    update(QRect(ultimoPunto, puntoFinal).normalized()
               .adjusted(-rad, -rad, +rad, +rad)); //ajusta los limites del
                    //rectangulo, -rad limites izquierdo y superior
                    //+rad limites derecho superior

    //actualiza ultimo punto como el final
    ultimoPunto = puntoFinal;
}


void AreaPintar::redimensionImagen(QImage *image, const QSize &newSize)
{
    // verifica si cumple con la medida o no
    if (image->size() == newSize)
        return;

    // nueva imagen y ponerlo blanco
    QImage nuevaImagen(newSize, QImage::Format_RGB32);
    nuevaImagen.fill(qRgb(255, 255, 255)); //Cualquier espacio adicional que
   //no haya llenado nuevaImagen, llenelo blanco

    QPainter painter(&nuevaImagen);
    painter.drawImage(QPoint(0, 0), *image);
    *image = nuevaImagen;
}




