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


# Explicación funciones y librerías areapintar.h

#include <QColor>  Nos permite el manejo de colores dentro de QT.
#include <QImage>  Nos permite el manejo de imagenes dentro de QT.
#include <QPoint>  Nos permite el manejo de puntos dentro de QT, (coordenadas x, y).
#include <QWidget> Nos permite el manejo de widgets, y derivados para la interfaz gráfica.

**mainwindow.ui**

Este es un archivo de diseño de Qt, no se hace uso de este directamente.

**ASDA.pro**

Este es un archivo de proyecto para Qt Creator que define la estructura y dependencias del proyecto. Especifica los archivos de código fuente, encabezados y recursos necesarios para compilar todo lo que esta adentro de la aplicación.

**areapintar.cpp**

Este archivo define la implementación de la clase AreaPintar, que es responsable de dibujar y manejar la entrada del usuario. Proporciona funciones para abrir y guardar imágenes, establecer el color y el ancho de la herramienta de dibujo y manejar eventos de teclado y mouse.


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




