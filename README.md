# Paint-ando

# Editor-de-imagenes-con-formato-en-qt

Este repositorio aloja un editor de imagen creado con el programa QT Creator en el lenguaje de programación c + +, el programa contiene un algoritmo con una estructura modular por lo que todo el proyecto está subdividido en subproblemas más pequeños que facilita la edición de imagen con formato. Incluye características como cambio de color del lapiz, tamaño del lapiz, borrador, y más. Los usuarios también tienen la opción de subir imagenes que tengan guardadas en sus computadoras. 
# Descripcion de la arquitectura 

Este proyecto se desarrolló utilizando Qt Creator y utiliza CMake como sistema de compilación. La arquitectura adopta una estructura modular que simplifica el mantenimiento y la ampliación.

# Descripción de archivos

**main.cpp**

Este es el punto de partida de la aplicación. Crea una instancia de QApplication e inicializa la ventana principal.

**mainwindow.cpp**

Este es el archivo principal de toda la aplicación. Contiene la lógica para crear la ventana principal, configurar la barra de menús y manejar diferentes acciones (por ejemplo, abrir, guardar, imprimir). También define varios slots para manejar las interacciones del usuario, como hacer clic en botones o menús.

**areapintar.cpp**

Este archivo define la clase AreaPintar, que es responsable de dibujar y manejar la entrada del usuario. Proporciona funciones para abrir y guardar imágenes, establecer el color y el ancho del herramienta de dibujo y manejar eventos de teclado y mouse.

**mainwindow.h**

Este es el archivo de cabecera de la clase MainWindow, que es la ventana principal de la aplicación. Define la interfaz pública de la clase, incluyendo funciones para crear acciones y menús, así como slots para manejar las interacciones del usuario.

**areapintar.h**

Este es el archivo de cabecera de la clase AreaPintar, que es responsable de dibujar y manejar la entrada del usuario. Define la interfaz pública de la clase, incluyendo funciones para abrir y guardar imágenes, establecer el color y el ancho de la herramienta de dibujo y manejar eventos de teclado y mouse.

**mainwindow.ui**

Este es un archivo de diseño de Qt, no se hace uso de este directamente.

**ASDA.pro**

Este es un archivo de proyecto para Qt Creator que define la estructura y dependencias del proyecto. Especifica los archivos de código fuente, encabezados y recursos necesarios para compilar todo lo que esta adentro de la aplicación.

**areapintar.cpp**

Este archivo define la implementación de la clase AreaPintar, que es responsable de dibujar y manejar la entrada del usuario. Proporciona funciones para abrir y guardar imágenes, establecer el color y el ancho de la herramienta de dibujo y manejar eventos de teclado y mouse.


# Explicación funciones y librerías areapintar.h


#include <QColor>  Nos permite el manejo de colores dentro de QT.
#include <QImage>  Nos permite el manejo de imagenes dentro de QT.
#include <QPoint>  Nos permite el manejo de puntos dentro de QT, (coordenadas x, y).
#include <QWidget> Nos permite el manejo de widgets, y derivados para la interfaz gráfica.

bool abrirImagen 
La función que va a recibir un objeto tipo QString con el nombre del archivo y su ruta.

bool guardarImagen
La función que va a recibir un objeto tipo QString con el nombre del archivo y su ruta.

void setColorLapiz
La función que recibe el color deseado por el usuario.

void setAnchoLapiz
La función que recibe el ancho dado por el usuario y lo actualiza en la configuración del lápiz.

bool isModified() 
Verifica si a la imagen se le ha modificado algo.

QColor myColorLapiz
Recibe el color seleccionado en setColorLapiz y lo actualiza en la configuración del lápiz.

int myAnchoLapiz 
Recibe el ancho ingresado por el usuario en setAnchoLapiz y lo actualiza en la configuración del lápiz.

void clearImage(); 
Esta función nos permite borrar toda la imagen que tengamos en ese momento en la aplicación.

void borrador();
Esta función nos permite borrar del mismo ancho de lápiz que tengamos en ese momento, sin necesidad de borrar toda la pantalla.

void linea();
Esta función nos permite hacer una linea totalmente recta al darle en la opción de menú "Figuras" y acto seguido seleccionar "Línea."

void circulo();
Esta función nos permite hacer un círculo totalmente perfecto al darle en la opción de menú "Figuras" y acto seguido seleccionar "Círculo."

void cuadrado(); 
Esta función nos permite hacer un cuadrado totalmente perfecto al darle en la opción de menú "Figuras" y acto seguido seleccionar "Cuadrado."

void triangulo();
Esta función nos permite hacer un triángulo totalmente perfecto al darle en la opción de menú "Figuras" y acto seguido seleccionar "Triángulo."

void lapiz();
Esta función nos permite hacer un  totalmente perfecto al darle en la opción de menú "Figurasy acto seguido seleccionar ""

void mousePressEvent(QMouseEvent *event) override;
Esta funcion verifica si se presiona el boton izquierdo del mouse y guarda la posición inicial.

void mouseMoveEvent(QMouseEvent *event) override
Esta funcion verifica si se presiona el boton izquierdo del mouse y a su vez si "dibujando" está en verdadero y permite dibujar por donde se mueva el mouse.

void mouseReleaseEvent(QMouseEvent *event) override
Verifica si se soltó el botón izquierdo y guarda la ultima posicion del mouse, cuenta con los condicionales de las figuras, es decir "Linea", "Circulo", "triángulo", "Cuadrado" dibuja la figura que el usuario seleccione.

void paintEvent(QPaintEvent *event) override;
Esta funcion re-dibuja el cuadrado sucio y crea un nuevo lienzo.

void resizeEvent(QResizeEvent *event) override;
Esta funcion verifica si el nuevo widget es igual  tamaño que la imagen, si es el caso, la redimensiona.

void dibujarLinea(const QPoint &endPoint)
Esta funcion es la encargada de dibujar en el lienzo, con los valores del lapiz dados por el usuario, desde un punto inicial hasta un punto final (tomados gracias a funciones anteriormente explicadas).

void redimensionImagen(QImage *image, const QSize &newSize)
Redimensiona una imagen a un nuevo tamaño, copiando el contenido de la imagen original a la nueva imagen.

bool modified
Esta funcion está diseñada para trabajar de una forma mas ordenada y de fácil acceso, su implementación se basa en verificar si la imagen inicial ha sufrido modificaciones hechas por el usuario.

bool dibujando
Esta funcion está diseñada para trabajar de una forma más ordenada y de fácil acceso, su implementación se basa en verificar si en la imagen se está dibujando, es decir a su vez está sufriendo modificaciones.

QImage image
Funcion que nos permite declarar lo que va en el lienzo como "image", heredado de QImage.

QPoint inicioMouse 
Funcion creada especificamente para el desarrollo del código en figuras, hereda de la libreria QPoint y toma el punto inicial del mouse.

QPoint finalMouse
Funcion creada especificamente para el desarrollo del código en figuras, hereda de la libreria QPoint y toma el punto final del mouse.

bool dibujarCuadrado; 
//funcion dibujar bool retorna f o v
bool dibujarCirculo;  
//funcion dibujar bool retorna f o v
bool dibujarTriangulo;
//funcion dibujar bool retorna f o v
bool dibujarLineaActiva; 
//funcion dibujar bool retorna f o v
bool dibujarLapiz; // Nueva bandera para el modo lápiz

void dibujarLineaRecta(const QPoint &startPoint, const QPoint &endPoint);
Esta función permite dibujar una linea recta, al seleccionar en la opcion de "Figuras" 

# Flujo de ejecución

Inicia en main.cpp y gracias a la interacción del usuario, genera y modifica los eventos del programa, actualiza los valores predeterminados de este, y ocurre gracias a la lógica dada en mainwindow.cpp y areapintar.cpp.


# Hecho por 


Universidad Tecnológica de Pereira 
Ingeniería en Sistemas y Computación
Facultad de Ingenierias 
Programación II
ing(c): Samuel Zuleta Castañeda
ing(c): Juan Emilio Muñoz Arenas
ing(c): Juan David Llano Henao


# Contáctanos

samuel.zuleta@utp.edu.co

emilio.munoz@utp.edu.co

juan.llano@utp.edu.co




