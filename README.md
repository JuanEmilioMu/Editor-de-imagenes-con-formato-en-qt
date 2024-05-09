# Editor-de-imagenes-con-formato-en-qt
Este repositorio aloja un editor de imagen creado con Qt Creator que facilita la edición de imagen con formato. Incluye características como cambio de color del lapiz, tamaño del lapiz, borrador, y más. Los usuarios también tienen la opción de subir imagenes que tengan guardadas en sus computadoras.

# Manual de usuario
Una vez ejecutado el programa, va a ver la siguiente ventana:

 ![image](https://github.com/JuanEmilioMu/Editor-de-imagenes-con-formato-en-qt/assets/159585399/2f6817cf-6005-4638-8123-69e27adb8131)

La cual es la ventana principal del programa. Se aprecia que por defecto, tiene dos menús, estos son "Archivo" y "Opciones."

# Archivo
Al darle click en el boton de "Archivo" se te abre el siguiente menú :

![image](https://github.com/JuanEmilioMu/Editor-de-imagenes-con-formato-en-qt/assets/159585399/8f0b0417-31f5-44e4-960c-ea28c9dc28e8)


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

-Si al darle click al boton de "Salir" ya has modificado tu archivo se abrira la siguiente ventana:

![image](https://github.com/JuanEmilioMu/Editor-de-imagenes-con-formato-en-qt/assets/159585399/4ea53fb8-8e19-45b7-9115-389ef8b7be2e)

Si le das click a la opcion "Save", se te abrira una ventana en la cual puedes escoger en donde guardar tu archivo y tambien en que formato lo quieres guardar. La ventana sale de la siguiente manera:

![image](https://github.com/JuanEmilioMu/Editor-de-imagenes-con-formato-en-qt/assets/159585399/de402a85-d250-487e-b508-388ccf4b4cff)

Si le das click a la opcion "Discard" el editor de imagen se cierra automaticamente sin guardar ningun cambio.

- Si al darle click al boton de "Salir" no has modificado el archivo: El editor de imagen se cierra automaticamente.




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






