# AVR-Bit_Manipulation
## Video Demo: <https://www.youtube.com/watch?v=YlWptvGyut8>
## Project Description
The goal of this project is to make a program that uses bitwise operations and bitmasks.

The project consists of displaying different patterns on an 8x8 led matrix.

<p align="center">
<img  src="images\hart.jpg"  width="80%" height="80%"><br>
<sub>Hart LED pattern</sub>
</p>

## Hardware schematic
The hardware consists of a ATmega169, a common cathod 8x8 LED matrix and, the corresponding 1k current limiting resistors.

<p align="center">
<img  src="images\schematic.png"  width="80%" height="80%"><br>
<sub>Project schematic</sub>
</p>

## Software description
The software contains several functions that demonstrate the use of different bitwise operations:
* `void activateColumn(uint8_t col)` : Lights up a specific column in the LED matrix by simply setting one bit of the PORTD register.
* `void activateColGoRight(uint8_t time)` : Lights up each column in sequence by setting the bit with a shift left operator on the PORTD register.
The function `void activateColGoLeft(uint8_t time)` does the same but counting down in the for loop.
* `void deactivateColGoRight(uint8_t time)` : Turns of each column in sequence by clearing the bit with a shift left operator on the PORTD register.
The function `void deactivateColGoLeft(uint8_t time)` does the same but counting down in the for loop.
* `void toggleRandomCol(uint8_t time)` : This function selects a random column and toggles the bit corresponding to that column on the PORTD register.
* `void toggleRandomLed(uint8_t time)` : This function selects both the column and the row at random, it sets all rows exept for the selected one and toggles the selected column. The result is a random selection of individual LEDs.