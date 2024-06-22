
extern "C"
{
    #include "mainish.h"
  
    #include <stdio.h>
    #include <stdlib.h>

    #include "freertos/FreeRTOS.h"
    #include "freertos/task.h"
    #include "freertos/event_groups.h"
    #include "esp_system.h"
    #include "esp_wifi.h"
    #include "esp_event.h"
    #include "esp_log.h"
    #include "nvs_flash.h"
    #include "esp_bt.h"

    #include "esp_hidd_prf_api.h"
    #include "esp_bt_defs.h"
    #include "esp_gap_ble_api.h"
    #include "esp_gatts_api.h"
    #include "esp_gatt_defs.h"
    #include "esp_bt_main.h"
    #include "esp_bt_device.h"
    #include "driver/gpio.h"
    #include "hid_dev.h"
}

using namespace std;

#include "usb_serial_interface.h"
#include <iostream>
#include <map>
#include <string>

class HID_wrapper : public usb_serial_interface
{
    public:
        HID_wrapper(int baud_rate);
        bool key_input(string c);
        bool special_input(string s);
        bool line_input(string s);
        void press_key(uint8_t c);
        void release_key(uint8_t c);
        bool serial_2_input();
        bool serial_2_line_input();
        bool write_log(string s);
        bool write_log(string t,string s);
        key_mask_t special_key_combinator();
    private:
        bool ez_key_initialization();
        void press_state();
        map<string,int> ez_normal_key;
        map<string,int> ez_special_key;
        map<int,int> seri_normal_key;
        bool key_state[118];
        bool shift;
        bool windows;
        bool alt;
        bool ctrl;
        bool cmd;
};

// wrapper class that provides a few useful features as add key_input, line_input, read serial and convert it directly to a bluetooth input. 