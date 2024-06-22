
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

#include "wrapper_class.h"




HID_wrapper::HID_wrapper(int baud_rate) :usb_serial_interface(baud_rate)
{
    initializer();
    ez_key_initialization();
}

bool HID_wrapper::ez_key_initialization() 
{
    this->write_log("initializing ez_key_maps");

    ez_normal_key["a"] = 4;
    ez_normal_key["A"] = 4;
    ez_normal_key["b"] = 5;
    ez_normal_key["B"] = 5;
    ez_normal_key["c"] = 6;
    ez_normal_key["C"] = 6;
    ez_normal_key["d"] = 7;
    ez_normal_key["D"] = 7;
    ez_normal_key["e"] = 8;
    ez_normal_key["E"] = 8;
    ez_normal_key["f"] = 9;
    ez_normal_key["F"] = 9;
    ez_normal_key["g"] = 10;
    ez_normal_key["G"] = 10;
    ez_normal_key["h"] = 11;
    ez_normal_key["H"] = 11;
    ez_normal_key["i"] = 12;
    ez_normal_key["I"] = 12;
    ez_normal_key["j"] = 13;
    ez_normal_key["J"] = 13;
    ez_normal_key["k"] = 14;
    ez_normal_key["K"] = 14;
    ez_normal_key["l"] = 15;
    ez_normal_key["L"] = 15;
    ez_normal_key["m"] = 16;
    ez_normal_key["M"] = 16;
    ez_normal_key["n"] = 17;
    ez_normal_key["N"] = 17;
    ez_normal_key["o"] = 18;
    ez_normal_key["O"] = 18;
    ez_normal_key["p"] = 19;
    ez_normal_key["P"] = 19;
    ez_normal_key["q"] = 20;
    ez_normal_key["Q"] = 20;
    ez_normal_key["r"] = 21;
    ez_normal_key["R"] = 21;
    ez_normal_key["s"] = 22;
    ez_normal_key["S"] = 22;  
    ez_normal_key["t"] = 23;
    ez_normal_key["T"] = 23;
    ez_normal_key["u"] = 24;
    ez_normal_key["U"] = 24;
    ez_normal_key["v"] = 25;
    ez_normal_key["V"] = 25;
    ez_normal_key["w"] = 26;
    ez_normal_key["W"] = 26;
    ez_normal_key["x"] = 27;
    ez_normal_key["X"] = 27;
    ez_normal_key["y"] = 28;
    ez_normal_key["Y"] = 28;
    ez_normal_key["z"] = 29;
    ez_normal_key["Z"] = 29;

 

    ez_normal_key["1"] = 30;
    ez_normal_key["2"] = 31;
    ez_normal_key["3"] = 32;
    ez_normal_key["4"] = 33;
    ez_normal_key["5"] = 34;
    ez_normal_key["6"] = 35;
    ez_normal_key["7"] = 36;
    ez_normal_key["8"] = 37;
    ez_normal_key["9"] = 38;
    ez_normal_key["0"] = 39;
    ez_normal_key["!"] = 30;
    ez_normal_key["@"] = 31;
    ez_normal_key["#"] = 32;
    ez_normal_key["$"] = 33;
    ez_normal_key["%"] = 34;
    ez_normal_key["^"] = 35;
    ez_normal_key["&"] = 36;
    ez_normal_key["*"] = 37;
    ez_normal_key["("] = 38;
    ez_normal_key[")"] = 39;
    ez_normal_key["\n"] = 40;
    ez_normal_key["Escape"] = 41;
    ez_normal_key["Back_Space"] = 42;
    ez_normal_key["Tab"] = 43;
    ez_normal_key[" "] = 44;
    ez_normal_key["-"] = 45;
    ez_normal_key["_"] = 45;
    ez_normal_key["="] = 46;
    ez_normal_key["+"] = 46;
    ez_normal_key["["] = 47;
    ez_normal_key["{}"] = 47;
    ez_normal_key["]"] = 48;
    ez_normal_key["}"] = 48;
    ez_normal_key["\\"] = 49;
    ez_normal_key["|"] = 49;
    ez_normal_key[";"] = 51;
    ez_normal_key[":"] = 51;
    ez_normal_key["'"] = 52;
    ez_normal_key["\""] = 52;
    ez_normal_key["~"] = 53;
    ez_normal_key["`"] = 53;
    ez_normal_key[","] = 54;
    ez_normal_key["<"] = 54;
    ez_normal_key["."] = 55;
    ez_normal_key[">"] = 55;
    ez_normal_key["/"] = 56;
    ez_normal_key["?"] = 56;
    ez_normal_key["/"] = 57;
    ez_normal_key["F1"] = 58;
    ez_normal_key["F2"] = 59;
    ez_normal_key["F3"] = 60;
    ez_normal_key["F4"] = 61;
    ez_normal_key["F5"] = 62;
    ez_normal_key["F6"] = 63;
    ez_normal_key["F7"] = 64;
    ez_normal_key["F8"] = 65;
    ez_normal_key["F9"] = 66;
    ez_normal_key["F10"] = 67;
    ez_normal_key["F11"] = 68;
    ez_normal_key["F12"] = 69;
    ez_normal_key["Print_Screen"] = 70;
    ez_normal_key["Scroll_Lock"] = 71;
    ez_normal_key["Pause"] = 72;
    ez_normal_key["Insert"] = 73;
    ez_normal_key["Home"] = 74;
    ez_normal_key["Page_Up"] = 75;
    ez_normal_key["Delete"] = 76;
    ez_normal_key["End"] = 77;
    ez_normal_key["Page_Down"] = 78;
    ez_normal_key["Right_Arrow"] = 79;
    ez_normal_key["Left_Arrow"] = 80;
    ez_normal_key["Down_Arrow"] = 81;
    ez_normal_key["Up_Arrow"] = 82;
    ez_normal_key["Num_lock"] = 83;
    ez_normal_key["Numpad_/"] = 84;
    ez_normal_key["Numpad_*"] = 85;
    ez_normal_key["Numpad_-"] = 86;
    ez_normal_key["Numpad_+"] = 87;
    ez_normal_key["Numpad_Enter"] = 88;
    ez_normal_key["Numpad_1"] = 89;
    ez_normal_key["Numpad_End"] = 89;
    ez_normal_key["Numpad_2"] = 90;
    ez_normal_key["Numpad_Down_Arrow"] = 90;
    ez_normal_key["Numpad_3"] = 91;
    ez_normal_key["Numpad_Page_Down"] = 91;
    ez_normal_key["Numpad_4"] = 92;
    ez_normal_key["Numpad_Left_Arrow"] = 92;
    ez_normal_key["Numpad_5"] = 93;
    ez_normal_key["Numpad_6"] = 94;
    ez_normal_key["Numpad_Page_Up"] = 94;
    ez_normal_key["Numpad_7"] = 95;
    ez_normal_key["Numpad_Home"] = 95;
    ez_normal_key["Numpad_8"] = 96;
    ez_normal_key["Numpad_Up_Arrow"] = 96;
    ez_normal_key["Numpad_9"] = 97;
    ez_normal_key["Numpad_Page_Up"] = 97;
    ez_normal_key["Numpad_0"] = 98;
    ez_normal_key["Numpad_Insert"] = 98;
    ez_normal_key["Numpad_."] = 99;
    ez_normal_key["Numpad_Delete"] = 99;
    ez_normal_key["Mute"] = 127;
    ez_normal_key["Volume_Up"] = 128;
    ez_normal_key["Volume_down"] = 129;
    ez_normal_key["Left_Control"] = 224;
    ez_normal_key["Left_Shift"] = 225;
    ez_normal_key["Left_Alt"] = 226;
    ez_normal_key["Left_GUI"] = 227;
    ez_normal_key["Right_Control"] = 228;
    ez_normal_key["Right_Shift"] = 229;
    ez_normal_key["Right_Alt"] = 230;
    ez_normal_key["Right_GUI"] = 231;

    ez_special_key["Play"] = 176;
    ez_special_key["Pause"] = 177;
    ez_special_key["Previous_Track"] = 181;
    ez_special_key["Next_Track"] = 182;

    seri_normal_key[0] =  44;
    seri_normal_key[1] =  40;
    seri_normal_key[2] =  42;
    seri_normal_key[3] =  76;
    seri_normal_key[4] =  43;
    seri_normal_key[5] =  41;
    seri_normal_key[6] =  4;
    seri_normal_key[8] =  5;
    seri_normal_key[10] =  6;
    seri_normal_key[12] =  7;
    seri_normal_key[14] =  8;
    seri_normal_key[16] =  9;
    seri_normal_key[18] =  10;
    seri_normal_key[20] =  11;
    seri_normal_key[22] =  12;
    seri_normal_key[24] =  13;
    seri_normal_key[26] =  14;
    seri_normal_key[28] =  15;
    seri_normal_key[30] =  16;
    seri_normal_key[32] =  17;
    seri_normal_key[34] =  18;
    seri_normal_key[36] =  19;
    seri_normal_key[38] =  20;
    seri_normal_key[40] =  21;
    seri_normal_key[42] =  22;
    seri_normal_key[44] =  23;
    seri_normal_key[46] =  24;
    seri_normal_key[48] =  25;
    seri_normal_key[50] =  26;
    seri_normal_key[52] =  27;
    seri_normal_key[54] =  28;
    seri_normal_key[56] =  29;

    seri_normal_key[7] =  4;
    seri_normal_key[9] =  5;
    seri_normal_key[11] =  6;
    seri_normal_key[13] =  7;
    seri_normal_key[15] =  8;
    seri_normal_key[17] =  9;
    seri_normal_key[19] =  10;
    seri_normal_key[21] =  11;
    seri_normal_key[23] =  12;
    seri_normal_key[25] =  13;
    seri_normal_key[27] =  14;
    seri_normal_key[29] =  15;
    seri_normal_key[31] =  16;
    seri_normal_key[33] =  17;
    seri_normal_key[35] =  18;
    seri_normal_key[37] =  19;
    seri_normal_key[39] =  20;
    seri_normal_key[41] =  21;
    seri_normal_key[43] =  22;
    seri_normal_key[45] =  23;
    seri_normal_key[47] =  24;
    seri_normal_key[49] =  25;
    seri_normal_key[51] =  26;
    seri_normal_key[53] =  27;
    seri_normal_key[55] =  28;
    seri_normal_key[57] =  29;
    
    seri_normal_key[58] = 39;
    seri_normal_key[59] = 30;
    seri_normal_key[60] = 31;
    seri_normal_key[61] = 32;
    seri_normal_key[62] = 33;
    seri_normal_key[63] = 34;
    seri_normal_key[64] = 35;
    seri_normal_key[65] = 36;
    seri_normal_key[66] = 37;
    seri_normal_key[67] = 38;
    seri_normal_key[68] = 75;
    seri_normal_key[69] = 78;
    seri_normal_key[70] = 74;
    seri_normal_key[71] = 77;
    seri_normal_key[72] = 82;
    seri_normal_key[73] = 81;
    seri_normal_key[74] = 80;
    seri_normal_key[75] = 79;
    seri_normal_key[76] = 0;
    seri_normal_key[77] = 71;
    seri_normal_key[78] = 72;
    seri_normal_key[79] = 53;
    seri_normal_key[80] = 53;
    seri_normal_key[81] = 30;
    seri_normal_key[82] = 31;
    seri_normal_key[83] = 32;
    seri_normal_key[84] = 33;
    seri_normal_key[85] = 34;
    seri_normal_key[86] = 35;
    seri_normal_key[87] = 36;
    seri_normal_key[88] = 37;
    seri_normal_key[89] = 38;
    seri_normal_key[90] = 39 ;
    seri_normal_key[91] = 45;
    seri_normal_key[92] = 45;
    seri_normal_key[93] = 46;
    seri_normal_key[94] = 46;
    seri_normal_key[95] = 47 ;
    seri_normal_key[96] = 48;
    seri_normal_key[97] = 47;
    seri_normal_key[98] = 48;
    seri_normal_key[99] = 49;
    seri_normal_key[100] = 49;
    seri_normal_key[101] = 51;
    seri_normal_key[102] = 51;
    seri_normal_key[103] = 52;
    seri_normal_key[104] = 52;
    seri_normal_key[105] = 54;
    seri_normal_key[106] = 54;
    seri_normal_key[107] = 55;
    seri_normal_key[108] = 55;
    seri_normal_key[109] = 56;
    seri_normal_key[110] = 56;
    seri_normal_key[111] = 58;
    seri_normal_key[112] = 59;
    seri_normal_key[113] = 60;
    seri_normal_key[114] = 61;
    seri_normal_key[115] = 62;
    seri_normal_key[116] = 63;
    seri_normal_key[117] = 64;
    seri_normal_key[118] = 65;
    seri_normal_key[119] = 66;
    seri_normal_key[120] = 67;
    seri_normal_key[121] = 68;
    seri_normal_key[122] = 69;
    seri_normal_key[123] = 98;
    seri_normal_key[124] = 84;
    seri_normal_key[125] = 85;
    seri_normal_key[126] = 86;
    seri_normal_key[127] = 87;
    seri_normal_key[128] = 99;
    seri_normal_key[129] = 88;
    seri_normal_key[130] = 128;
    seri_normal_key[131] = 129;
    seri_normal_key[132] = 226;
    seri_normal_key[133] = 176;
    seri_normal_key[134] = 183;
    seri_normal_key[135] = 181;
    seri_normal_key[136] = 182;
    seri_normal_key[137] = 225;
    seri_normal_key[139] = 224;
    seri_normal_key[141] = 227;
    seri_normal_key[143] = 226;
    seri_normal_key[145] = 227;

    for (int i = 0 ; i < 116 ; i++){
        key_state[i] = false;
    }
    return true;
}

bool HID_wrapper::key_input(string c)
{
    uint8_t id = ez_normal_key[c];
    uint8_t temp = 0;
    bool shifted = false;

    if (!id) return false;

    if (c[0] == '?' || c[0] == '!' || c[0] == '@' || c[0] == '#' || c[0] == '$' || c[0] == '%' 
    || c[0] == '^' || c[0] == '&' || c[0] == '*' || c[0] == '(' || c[0] == ')' || c[0] == '_' || c[0] == '+' 
    || c[0] == '<' || c[0] == '>' || c[0] == '{' || c[0] == '}' || c[0] == '|' || c[0] == ':' ||c[0] == ';')
    {
        shifted = true;
    }

    if (shifted)
    {
        esp_hidd_send_keyboard_value(0, LEFT_SHIFT_KEY_MASK , &id, 1);
        esp_hidd_send_keyboard_value(0, 0, &temp, 1);
    } else {
        esp_hidd_send_keyboard_value(0, LEFT_GUI_KEY_MASK, &id, 1);
        esp_hidd_send_keyboard_value(0, 0, &temp, 1);
    }
    return true;
}

bool HID_wrapper::line_input(std::string s)
{
    return true;
}

key_mask_t HID_wrapper::special_key_combinator() //change this to rely on keystateMap
{
    key_mask_t result = 0;
    if (key_state[111]) result = result | LEFT_SHIFT_KEY_MASK;
    if (key_state[112]) result = result | LEFT_CONTROL_KEY_MASK;
    if (key_state[113]) result = result | LEFT_GUI_KEY_MASK;
    if (key_state[114]) result = result | LEFT_ALT_KEY_MASK;
    return result;
}
void HID_wrapper::press_key(uint8_t c)
{
    uint8_t a;
    switch (c)
    {
        case 137: //shift
            a = seri_normal_key[137];
            shift = true;
            esp_hidd_send_keyboard_value(0, special_key_combinator(), &a, 1);
            return;
        case 139: //control
            a = seri_normal_key[139];
            ctrl = true;
            esp_hidd_send_keyboard_value(0, special_key_combinator(), &a, 1);
            return;
        case 141: //window
            a = seri_normal_key[141];
            windows = true;
            esp_hidd_send_keyboard_value(0, special_key_combinator(), &a, 1);
            return;
        case 143: //alt
            a = seri_normal_key[143];
            alt = true;
            esp_hidd_send_keyboard_value(0, special_key_combinator(), &a, 1);
            return;
        default:
            a = seri_normal_key[c];
            esp_hidd_send_keyboard_value(0, special_key_combinator(), &a, 1);
            return;
    }
        
}

void HID_wrapper::release_key(uint8_t c)
{
    uint8_t a = 0;
    switch (c)
    {
        case 138:
            shift = false;
            esp_hidd_send_keyboard_value(0, 0, &a, 1);
            return;
        case 140:
            ctrl = false;
            esp_hidd_send_keyboard_value(0, 0, &a, 1);
            return;
        case 142:
            windows = false;
            esp_hidd_send_keyboard_value(0, 0, &a, 1);
            return;
        case 144:
            alt = false;
            esp_hidd_send_keyboard_value(0, 0, &a, 1);
            return;
        default:
            esp_hidd_send_keyboard_value(0, 0, &a, 1);
    }
}

bool HID_wrapper::serial_2_input()
{

    while (true)
    {
        uint8_t temp = read_byte();
        //update key_state
        if (temp > 115){
            temp -= 116;
            key_state[temp] = false;
        } else {
            key_state[temp] = true;
        }

        press_state();
        // if (temp == 138 || temp == 140 || temp == 142 || temp == 144 || temp == 146 || temp == 147)
        // {
        //     release_key(temp);
        // } else {
        //     press_key(temp);
        // }
         // Pass a string with a single character
    }
    
    return true;
}

void HID_wrapper::press_state(){
    key_mask_t modifiers = special_key_combinator();
    vector<uint8_t> keys_pressed;
    for (int i = 0 ; i < 116 ; i++){
    }

}

bool HID_wrapper::write_log(string s)
{
    ESP_LOGI("Bluetooth Device: ","%s",s.c_str());
            return true;
}

bool HID_wrapper::write_log(string t, string s)
{
    ESP_LOGI(t.c_str(),"%s",s.c_str());
            return true;
}


bool HID_wrapper::serial_2_line_input()
{
    return true;
}

bool HID_wrapper::special_input(std::string s)
{
    vTaskDelay(300 / portTICK_PERIOD_MS);
    this->write_log("Sending Special Input",s);
    esp_hidd_send_consumer_value(0, ez_special_key[s], true);
    vTaskDelay(150 / portTICK_PERIOD_MS);
    esp_hidd_send_consumer_value(0, ez_special_key[s], false);
    vTaskDelay(100 / portTICK_PERIOD_MS);
    return true;
}   