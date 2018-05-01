# Auto-A-Sketch
ECE 4180 Sring 2017
Team Members: Jon Dolan, Austin Spalding, Eric Rafalovsky

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
* 2x Geared DC Motors
* 1x Motor Controllers
* 1x Arduino
* 1x Raspberry Pi - Running Ubuntu
* 1x Etch-A-Sketch
* 2x 3D printed knob to motor connectors
* 1x Mounting System
* Wires
* 1x Motor Power Supply

## Software Implementation
The Node.js script converts JPEG to an SVG and uses an on online tool to convert the SVG to G-code.
The C++ Parser reads G-code and interpolates points along the provided curves. The C++ also scales the values to fit in the Etch-A-Sketch frame.
The points are sent over the virtual com port to the Arduino to be drawn by the motors. 
