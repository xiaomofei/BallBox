#!/bin/sh
gcc ./ballbox.c -lm -o ./ball
./ball < ./input.txt
