#include"clock.h"

void delay(uint32_t count){
    count*=100000000;
    volatile uint32_t i;
    for (i=0; i<count; i++){
        __asm__ volatile ("nop");
    }
}