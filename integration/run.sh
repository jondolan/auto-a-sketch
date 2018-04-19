#!/bin/bash

# usage:
# ./run.sh <input.file>
# ie: ./run.sh apple.png

cp $1 toolpath
cd toolpath

node index.js $1

cp gcode.gcode ../simulation
cd ../simulation

./parser gcode.gcode