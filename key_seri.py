import serial
import time
import keyboard
import serial.tools.list_ports
import os
from datetime import datetime
import threading
import select

ser = None
escape = None
settings = None
exite = None

mlatch = True
key_states = {}
start = True
reader_thread = None

keys_checked = [
    'space', 'enter', 'backspace', 'delete', 'tab', 'esc',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o',  'p', 'q',  'r',  's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'page up', 'page down', 'home', 'end', 'up', 'down', 'left', 'right',
    'num lock', 'scroll lock', 'pause',
    '~', '`', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '-', '=', '+', '[', ']', '{', '}', '|', '\\', ';', ':', "'", '"', ',', '<', '.', '>', '/', '?',
    'f1', 'f2', 'f3', 'f4', 'f5', 'f6', 'f7', 'f8', 'f9', 'f10', 'f11', 'f12',
    'num 0', 'num /', 'num *', 'num -', 'num +', 'num .', 'num enter',
    'volume up', 'volume down', 'volume mute',
    'play/pause media', 'media stop', 'next track', 'previous track', "shift", "ctrl", "left windows", "alt", "caps lock", 
]

print(len(keys_checked))


keys_pressed_map = {key: index for index, key in enumerate(keys_checked)}
keys_released_map = {key: index+116 for index, key in enumerate(keys_checked)}
print(len(keys_pressed_map))
print(len(keys_released_map))

def read_serial(ser):
    global start
    while start:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip()
            if line:
                with open("esp_log.txt", "a") as file:
                    current_time = datetime.now()
                    file.write(str(current_time) + "\n" + line + "\n\n")
        else:
            time.sleep(0.01)  # Sleep briefly to reduce CPU usage
    return

def read_initialize():
    global escape
    global settings
    global exite
    with open("serial_info.txt", 'r') as file:
        for line in file:
            found = line.find("port_number = ")
            if found != -1:
                port = line[found+14:]
                port = port.rstrip()
                print("Port found =", port)

            found = line.find("baud_rate = ")
            if found != -1:
                baud_rate = line[found+12:]
                baud_rate = baud_rate.rstrip()
                print("Baud rate found =", baud_rate)
            found = line.find("escape_key = ")
            if found != -1:
                escape = line[found+13:]
                escape = escape.rstrip()
                print("toggle key found = " + escape)
            found = line.find("exit_key = ")
            if found != -1:
                exite = line[found+11:]
                exite = exite.rstrip()
                print("exit key found = " + exite)
            found = line.find("settings_key = ")
            if found != -1:
                settings = line[found+15:]
                settings = settings.rstrip()
                print("settings key found = " + settings + "\n")

    port = port.rstrip() if port else None
    baud_rate = int(baud_rate) if baud_rate else None

    if port is not None and baud_rate is not None:
        ser = serial.Serial((str(port)), baud_rate)
        return ser
    else:
        print("Error: Port or Baud rate not found in file.")
        return None
    

def write_first():
    with open("serial_info.txt", 'w') as file:
        file.write("initiated = 1\n")
        ports = serial.tools.list_ports.comports()
        if not ports:
            print("No ports found to be available exiting.\n")
            file.close()
            with open("serial_info.txt", 'w') as file:
                file.write("initiated = 0\n")
            return
        else:
            print("Ports found are: ")
            for port in ports:
                print('\t' + port.device)
            port_no = input("Select port by full name: ")
            file.write("port_number = " + port_no + '\n')
            file.write("baud_rate = " + input("Type baud rate: ") + '\n')
            print("Press any key to set the toggle mode button: ")
            time.sleep(0.3)
            file.write("escape_key = " + (keyboard.read_event(suppress=True)).name + "\n")
            print("Press any key to set the exit program button: ")
            time.sleep(0.3)
            file.write("exit_key = " + (keyboard.read_event(suppress=True)).name + "\n")
            print("Press any key to set the change settings button: ")
            time.sleep(0.3)
            file.write("settings_key = " + (keyboard.read_event(suppress=True)).name + "\n")
            file.write("Here is the map of values to send for press to the esp32\n")
            for key, value in keys_pressed_map.items():
                file.write("\t" + key + ' = ' + str(value) +"\n")
            file.write("Here is the map of values to send for release to the esp32\n")
            for key, value in keys_released_map.items():
                file.write("\t" + key + ' = ' + str(value) +"\n")

def debug_pressed(key):
    print("Key press report: " + key)
    print("\n")
    current_time = datetime.now()
    with open("log.txt","a") as file:
        file.write(str(current_time))
        file.write(" : ")
        file.write("Key press report: " + key + "\n" + '\n')
    return

def press_key(key):
    global keys_pressed_map
    ser.write(keys_pressed_map[key].to_bytes(1,byteorder='big'))
    return

def release_key(key):
    global keys_released_map
    ser.write(keys_released_map[key].to_bytes(1,byteorder='big'))
    return


def startup():   
    global reader_thread
    global ser
    if not os.path.exists("serial_info.txt"):
        # Create the file if it doesn't exist
        with open("serial_info.txt", 'w') as file:
            file.write("initiated = 0\n")
    with open("serial_info.txt", 'r') as file:
        contents = file.read()
        if (contents.find("initiated = 1") == -1):
            write_first()
    ser = read_initialize()
    reader_thread = threading.Thread(target=read_serial, args=(ser,), daemon=True)
    reader_thread.start()

#actual program

startup()
latch = True
while True:
    if latch:
        while True:
            event = keyboard.read_event(suppress=True)
            if event.name == escape:
                latch = False
                print("toggle key detected : unsupressing now.")
                break
            if event.event_type == keyboard.KEY_DOWN:
                press_key(event.name.lower())
                debug_pressed(event.name)
            elif event.event_type == keyboard.KEY_UP:
                release_key(event.name.lower())
                debug_pressed(event.name)
                continue

    time.sleep(0.2)
    if mlatch:
        print("\nMenu options:")
        print("\t" + escape + " : toggle mode")
        print("\t" + exite + " : exit the program")
        print("\t" + settings + " : Change settings\n")
        
        
    if keyboard.read_event().name == escape:
        print("toggle key detected : supressing now.")
        latch = True
        mlatch = True
        time.sleep(0.1)
        continue
    elif keyboard.is_pressed(exite):
        print("Exiting the program now...",end = "")
        exit()
    elif keyboard.is_pressed(settings):
        
        start = False
        time.sleep(0.01)
        print("resetting the settings")
        reader_thread.join()
        print("succesfully closed listener thread")
        ser.close()
        open("serial_info.txt", 'w')
        start = True
        startup()
        mlatch = True
        continue
    mlatch = False
    

