#!/bin/bash

# Compile and upload the Arduino sketch

arduino-cli compile --fqbn arduino:avr:uno bin-night-light.ino
arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno bin-night-light.ino

