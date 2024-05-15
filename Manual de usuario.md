# Editor-de-imagenes-con-formato-en-qt

Este repositorio aloja un editor de imagen creado con el programa QT Creator en el lenguaje de programación c + +, el programa contiene un algoritmo con una estructura modular por lo que todo el proyecto está subdividido en subproblemas más pequeños que facilita la edición de imagen con formato. Incluye características como cambio de color del lapiz, tamaño del lapiz, borrador, y más. Los usuarios también tienen la opción de subir imagenes que tengan guardadas en sus computadoras. Este proyecto fue elaborado en el programa QT Creator con el lenguaje de programación c + +, el programa contiene un algoritmo con una estructura modular por lo que todo el proyecto está subdividido en subproblemas más pequeños.

# Manual de usuario

Una vez ejecutado el programa, va a ver la siguiente ventana:


 ![image](https://github.com/JuanEmilioMu/Editor-de-imagenes-con-formato-en-qt/assets/159585178/e14610ae-c7f3-4e35-a1ce-16c5cec718b2)


La cual es la ventana principal del programa. Se aprecia que por defecto, tiene tres menús, estos son "Archivo", "Opciones" y "Figuras."

# Archivo

Al darle click en el boton de "Archivo" se te abre el siguiente menú :


![image](https://github.com/JuanEmilioMu/Editor-de-imagenes-con-formato-en-qt/assets/159585399/8f0b0417-31f5-44e4-960c-ea28c9dc28e8)




Es decir, "Archivo" tiene 3 opciones, "Abrir", "Guardar como", "Salir."

Aquí su descripción:

Al darle click en el boton de "Abrir" pueden pasar dos cosas

1. Si has modificado el archivo te saldra la siguiente imagen:

   
![image](https://github.com/JuanEmilioMu/Editor-de-imagenes-con-formato-en-qt/assets/159585399/40e9525f-ca64-427a-902f-87e406711aee)


Si le das click a la opcion "Save", se te abrira una ventana en la cual puedes escoger en donde guardar tu archivo y tambien en que formato lo quieres guardar. La ventana sale de la siguiente manera:


![image](https://github.com/JuanEmilioMu/Editor-de-imagenes-con-formato-en-qt/assets/159585399/de402a85-d250-487e-b508-388ccf4b4cff)


Si le das a la opcion "Discard" pasas directamente a la segunda posibilidad.

2. Si no has modificado o le diste "Discard" te saldra una ventana en la cual escogeras el archivo que quieres ver en el editor de imagen. Te saldra de la siguiente manera:


![image](https://github.com/JuanEmilioMu/Editor-de-imagenes-con-formato-en-qt/assets/159585399/c7858c34-80eb-4cc9-8679-072eabf68b0d)


(Recuerda que si no escoges un archivo en un formato valido el programa no podra abrirlo).

"Guardar como"

Si le das click a la opcion "Guardar como", se te abrira una ventana en la cual puedes escoger en donde guardar tu archivo y tambien en que formato lo quieres guardar. La ventana sale de la siguiente manera:


![image](https://github.com/JuanEmilioMu/Editor-de-imagenes-con-formato-en-qt/assets/159585399/de402a85-d250-487e-b508-388ccf4b4cff)


"Salir"

Si al darle click al boton de "Salir" ya has modificado tu archivo se abrira la siguiente ventana:


![image](https://github.com/JuanEmilioMu/Editor-de-imagenes-con-formato-en-qt/assets/159585399/4ea53fb8-8e19-45b7-9115-389ef8b7be2e)


Si le das click a la opcion "Save", se te abrira una ventana en la cual puedes escoger en donde guardar tu archivo y tambien en que formato lo quieres guardar. La ventana sale de la siguiente manera:


![image](https://github.com/JuanEmilioMu/Editor-de-imagenes-con-formato-en-qt/assets/159585399/de402a85-d250-487e-b508-388ccf4b4cff)


Si ledas click a la opcion "Discard" el editor de imagen se cierra automaticamente sin guardar ningun cambio.

Si al darle click al boton de "Salir" no has modificado el archivo: El editor de imagen se cierra automaticamente.



# Opciones

Al darle click en el boton de "Opciones" se te abre el siguiente menú :


![image](https://github.com/JuanEmilioMu/Editor-de-imagenes-con-formato-en-qt/assets/159585178/8de83231-d6a3-4121-95f4-37f9b498490b)


Al pulsar la primera opción "Color del lapiz...", inmediatamente mostrará la siguiente ventana : 


![image](https://github.com/JuanEmilioMu/Editor-de-imagenes-con-formato-en-qt/assets/159585178/ab90a2c4-9d66-435c-9962-2b3d593a40d5)


Permitiendo al usuario escoger, entre colores predeterminados ó codigo RGB.

Al pulsar la segunda opción "Ancho del Trazo...", inmediatamente mostrará la siguiente ventana : 


![image](https://github.com/JuanEmilioMu/Editor-de-imagenes-con-formato-en-qt/assets/159585178/41cb5513-d176-4769-9466-eeee953e67a4)


Permitiendo ingresar al usuario, con numeros enteros el tamaño del trazo, siendo 1 el mínimo permitido y 250 el número máximo.

Al pulsar la tercera opcion "Borrador...", no saldrá ninguna ventana emergente, sino que automaticamente va a seleccionar el color blanco, logrando asi el efecto de borrador, el ancho va a ser el mismo que se este usando en el ancho del trazo en ese momento, pero tambien se puede modificar en la opcion "Ancho del trazo..." actualizando su valor por el requerido del usuario.

Al pulsar la cuarta opción "Borrar pantalla...", tampoco saldrá ninguna ventana emergente, usa el mismo concepto de la opcion anterior, por medio de los valores RGB, actualiza el lienzo con el color blanco, dando asi la ilusión de que se borró la pantalla.



# Figuras

Al darle click en el boton de "Figuras" se te abre el siguiente menú :


![image](https://github.com/JuanEmilioMu/Editor-de-imagenes-con-formato-en-qt/assets/159585178/2d1c3fe3-0e7a-4fcb-b151-76b256316f04)


Es decir, "Figuras" tiene 4 opciones, "Línea", "Cuadrado", "Triángulo" y "Círculo" Aquí su descripción:

"Línea"

No saldrá ningun aviso o ventana emergente, simplemente vas a arrastrar el mouse en el lienzo y se creará la linea recta, tomará los valores que tenga el lapiz en ese momento, es decir, ancho y color:


![image](https://github.com/JuanEmilioMu/Editor-de-imagenes-con-formato-en-qt/assets/159585178/5c312529-33f1-4706-99e7-030122a7ead4)


"Cuadrado"

Al igual que en "Linea" NO saldrá ningun aviso o ventana emergente, simplemente vas a arrastrar el mouse en el lienzo y se creará tu cuadrado, tomará los valores que tenga el lápiz en ese momento, es decir, ancho y color:

![image](https://github.com/JuanEmilioMu/Editor-de-imagenes-con-formato-en-qt/assets/159585178/f6c0f530-af66-4750-9a97-54dcd668e260)


"Triángulo"

Al igual que en las figuras anteriores NO saldrá ningun aviso o ventana emergente, simplemente vas a arrastrar el mouse en el lienzo y se creará tu triángulo, tomará los valores que tenga el lápiz en ese momento, es decir, ancho y color:

![image](https://github.com/JuanEmilioMu/Editor-de-imagenes-con-formato-en-qt/assets/159585178/53308cb0-f49f-402f-82c2-d39a9d2261d4)


"Círculo"


Al igual que en las figuras anteriores NO saldrá ningun aviso o ventana emergente, simplemente vas a arrastrar el mouse en el lienzo y se creará tu circulo, tomará los valores que tenga el lápiz en ese momento, es decir, ancho y color:


![image](https://github.com/JuanEmilioMu/Editor-de-imagenes-con-formato-en-qt/assets/159585178/32faa38b-fd3f-415d-a415-ee62b0cee3ac)
