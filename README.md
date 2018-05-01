# Auto-A-Sketch

## Introduction
The Auto-A-Sketch is a raspberry pi and arduino based project. The system draws JPEG images on an Etch-A-Sketch. The pi generates motor instructions, and the arduino operates as a position motor controller. A simulator also shows the image on a monitor as the image is drawn on the Etch-A-Sketch.

## Picture

![alt text](https://github.com/jondolan/auto-a-sketch/blob/master/images/nasaworm.jpg?raw=true)

Original Nasa Logo

![alt text](https://github.com/jondolan/auto-a-sketch/blob/master/images/Screen%20Shot%202018-05-01%20at%203.14.48%20PM.png?raw=true)

Nasa logo drawn on an Etch-A-Sketch

## Video Link
https://drive.google.com/open?id=1rDCuUlOLcpyP9IXyiEQ-IIzM8CH1AX6q

## Parts
* Geared DC Motors
* Motor Controllers
* Arduino
* Raspberry Pi - Running Ubuntu
* Etch-A-Sketch


## Software Implementation
Node.js converts JPEG to an SVG and uses on online tool to convert the SVG to G-code.
C++ Parser reads G-code and interpolates points along the provided curves. The C++ also scales the values to fit in the Etch-A-Sketch frame.
The points are sent over the virtual com port to the Arduino to be drawn by the motors. 
