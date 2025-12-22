#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

void keyboard_init(void);
uint8_t get_keyboard_sc(void);


typedef enum {
    KEY_W,
    KEY_S,
    KEY_A,
    KEY_D,
    KEY_UP_ARROW,
    KEY_DOWN_ARROW,
    KEY_LEFT_ARROW,
    KEY_RIGHT_ARROW,
    KEY_SPACE,
    KEY_NULL,
} KeyEvent;

typedef struct KeyboardEvent {
    uint8_t scancode;
    KeyEvent key;
} keyboard_event_t;

keyboard_event_t get_keyboard_event();

#endif