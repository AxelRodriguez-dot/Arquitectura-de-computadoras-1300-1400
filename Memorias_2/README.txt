Descripción

Genera una memoria bidimensional, para poder crear el juego del Gato
La computadora debe ser capaz de iniciarlizar el juego con la siguiente secuencia
-usuario hace la primer elección
-computadora genera dos selecciones aleatorias con las que intentará posicionar su turno
-computadora evalua si el espacio en la memoria (3x3) tiene ya una seleccion, sea por parte del usuario o por la computadora. en caso de que la seleccion tenga ya un dato asignado debera generarse un nuevo par de coordenadas para intentar fijar el turno de la computadora
-una vez asignado cualquier turno, la computadora debera realizar un barrido en la memoria para definir si ya existe un ganador, en caso de no encontrar una combinacion ganadora continuar con el juego.

El resultado se muestra en el siguiente video de demostración:
https://youtu.be/dpX9KO1T8J4?si=eLeANQ7VUmvxZNPR
Materiales utilizados

Arduino Leonardo R3

Cable USB para alimentación y programación

6 LED externo con resistencia de 220 Ω si se desea visualizar con mayor brillo

Computadora con el IDE de Arduino instalado

Especificaciones técnicas del Arduino Leonardo R3
Característica	Descripción
Microcontrolador	ATmega32u4
Voltaje de operación	5 V
Voltaje de entrada recomendado	7 V – 12 V
Pines digitales I/O	20 (de los cuales 7 pueden ser PWM)
Entradas analógicas	12
Corriente máxima por pin I/O	40 mA
Memoria Flash	32 KB (4 KB usados por el bootloader)
SRAM	2.5 KB
EEPROM	1 KB
Frecuencia de reloj	16 MHz
Comunicación USB	Nativa (sin chip FTDI, usa el propio ATmega32u4)
LED integrado	Pin 13
Conexión USB	Micro-USB
Características especiales	Puede emular teclado, ratón y otros dispositivos HID

Funcionamiento general

El usuario al hacer una seleccion en una matriz 3x3, luego la computadora va a evaluar que espacio esta disponible en la matriz y asi hasta que la computadora defina un ganador

Conecta el Arduino Leonardo R3 al equipo mediante el cable USB.

Abre el IDE de Arduino.

Copia el código anterior en un nuevo sketch.

En Herramientas → Placa, selecciona Arduino Leonardo.

En Herramientas → Puerto, selecciona el puerto correspondiente.

Sube el código.



Explicación de la lógica
Al tener un espacio seleccionado la computadora encontrara un espacio sin usar para poder utilizarlo y asi compitiendo con el usuario para poder obtener la victoria



dependiendo de quien junte en linea ya sea circulo o tache en la matriz 3x3 sera el ganador y en pantalla mostrara en ganador ya sea la computadora o el usuario

.


Autor y créditos

Autor: Axel Johab Rodriguez Ortiz  y Damián Alexander Díaz Piña
Numeros de control: 231512112 y 23151247
Placa utilizada: Arduino Leonardo R3