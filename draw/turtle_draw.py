#!/usr/bin/python

import turtle
import time
import sys, signal
import serial

def signal_handler(signal, frame):
    print("\nprogram exiting gracefully")
    sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)

def pleaseexitnow(x, y):
	sys.exit(0)


ser = serial.Serial("/dev/ttyUSB0", 115200)

# micro steps per full step
MICRO_STEPS = 8

# dimensions in full steps * provided micro step number
SCREEN_WIDTH = 108 * MICRO_STEPS
SCREEN_HEIGHT = 80 * MICRO_STEPS

SCREEN_WIDTH = 1150
SCREEN_HEIGHT = 750

turtle.setup(width=SCREEN_WIDTH, height=SCREEN_HEIGHT)
turtle.speed(0)
turtle.hideturtle()

turtle.penup()
turtle.setposition(-SCREEN_WIDTH/2, -SCREEN_HEIGHT/2)
turtle.pendown()

turtle.setposition(SCREEN_WIDTH/2, -SCREEN_HEIGHT/2)
turtle.setposition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2)
turtle.setposition(-SCREEN_WIDTH/2, SCREEN_HEIGHT/2)
turtle.setposition(-SCREEN_WIDTH/2, -SCREEN_HEIGHT/2)

turtle.onscreenclick(pleaseexitnow)

while 1:
	try:
		coords = input()
		x = int(float(coords[0]))
	        y = int(float(coords[1]))
		#print(str(x) + "," + str(y))
		ser.write(str(x) + "\n")
		ser.write(str(y) + "\n")
		x = (x)/30 - SCREEN_WIDTH/2
		y = (y)/30 - SCREEN_HEIGHT/2
		turtle.setposition(x, y)		
		back = ser.read()
	except EOFError:
		print("nothing")
	#print(int(coords[0]) + ", " + int(coords[1]))
	#x = int(float(coords[0]) * (SCREEN_WIDTH/700.0)) # put in range -screen_width->screen width
	#y = int(float(coords[1]) * (SCREEN_HEIGHT/700.0)) # put in range -screen height->screen height
	#x = int(float(coords[0]))
	#y = int(float(coords[1]))
	#print(str(x) + "," + str(y))	
	#turtle.setposition(x, y)


time.sleep(1000000)

