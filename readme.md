# KeSP
A way to mirror keyboard inputs via bluetooth.

# Description
Have you ever needed to use 2 different computers on the same desk and didn't want 
2 different keyboards. KeSP is a tool using the ESP32 Microprocessor to mirror
the keyboard inputs on your pc to another device of your choosing via Bluetooth

# License
[WTFPL](http://www.wtfpl.net)

# Installation
Bought the finished product:
- if you have bought the esp32 directly from the source no flashing will be neccesary and you can download the python application and run it as normal. (packaging needed)
- if you have not bought the esp32 from the source and is using a new ESP32, make sure it has bluetooth and Wifi as well as an onboard Serial to usb interface. Flashing the software onto the esp32 should be pretty simple just clone the repository via VScode and use the platformIO tool for easy ROM flashing.

# Usage
- you will have to find the COM port linked to the ESP32 by going to device manager on windows/ it should work for Mac as well and looking for the ESP32,
- Once you have found the COM port, type in the direct name i.e COM1, TTY0 etc. according to the instructions in the command prompt. Then bind keys for the interrupt button that toggles the functionality on and off, bind the key for changing the settings and bind the key for exiting the application.
- to connect your second device It is as easy as just connecting to the name ESP32 etc on your bluetooth settings.