#!/usr/bin/python

import turtle

import sys, signal
def signal_handler(signal, frame):
    print("\nprogram exiting gracefully")
    sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)

def test(x, y):
	sys.exit(0)

# micro steps per full step
MICRO_STEPS = 8

# dimensions in full steps * provided micro step number
SCREEN_WIDTH = 108 * MICRO_STEPS
SCREEN_HEIGHT = 80 * MICRO_STEPS

turtle.setup(width=SCREEN_WIDTH, height=SCREEN_HEIGHT)
turtle.hideturtle()
turtle.penup()
turtle.setposition(-SCREEN_WIDTH/2, -SCREEN_HEIGHT/2)
turtle.pendown()

turtle.onscreenclick(test)

while 1:
	try:
		coords = input()
	except EOFError:
		print("Simulation ended")
		sys.exit(0)
	#print(int(coords[0]) + ", " + int(coords[1]))
	x = int(float(coords[0]) * (SCREEN_WIDTH/4)) # put in range -screen_width->screen width
	y = int(float(coords[1]) * (SCREEN_HEIGHT/4)) # put in range -screen height->screen height
	print(str(x) + "," + str(y))	
	turtle.setposition(x, y)

