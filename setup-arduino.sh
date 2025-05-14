#!/bin/bash

# Ensure Arduino is setup for the Arduino Uno board

arduino-cli core update-index
arduino-cli core install arduino:avr

