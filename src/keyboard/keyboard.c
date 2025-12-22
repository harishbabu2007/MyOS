#include "keyboard.h"

keyboard_event_t get_keyboard_event(){
    uint8_t scanncode = get_keyboard_sc();
    keyboard_event_t event = {
        scanncode,
        KEY_NULL
    };

    switch (scanncode)
    {
        case 0x11:
            event.key = KEY_W;
            break;

        case 0x1F:
            event.key = KEY_S;
            break;

        case 0x1E:
            event.key = KEY_A;
            break;

        case 0x20:
            event.key = KEY_D;
            break;

        case 0x48:
            event.key = KEY_UP_ARROW;
            break;

        case 0x50:
            event.key = KEY_DOWN_ARROW;
            break;

        case 0x4B:
            event.key = KEY_LEFT_ARROW;
            break;

        case 0x4D:
            event.key = KEY_RIGHT_ARROW;
            break;

        case 0x39:
            event.key = KEY_SPACE;
            break;
        
        default:
            break;
    }

    // For finding keycodes
    // if ((int)scanncode != 255){
    //     terminal_writeint((int)scanncode);
    //     terminal_writestring("\n");
    // }

    return event;
}