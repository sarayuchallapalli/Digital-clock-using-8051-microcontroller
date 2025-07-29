#include <regx51.h>
#include "lcd.h"

unsigned char hours = 0, minutes = 0, seconds = 0;

void display_time() {
    lcd_cmd(0x80);  // First row

    // Display Hours
    lcd_data((hours / 10) + '0');
    lcd_data((hours % 10) + '0');
    lcd_data(':');

    // Display Minutes
    lcd_data((minutes / 10) + '0');
    lcd_data((minutes % 10) + '0');
    lcd_data(':');

    // Display Seconds
    lcd_data((seconds / 10) + '0');
    lcd_data((seconds % 10) + '0');
}

void delay_1sec() {
    // 1 second delay using nested loops (approximate)
    int i, j;
    for(i = 0; i < 20; i++) {
        for(j = 0; j < 1275; j++);
    }
}

void main() {
    lcd_init();

    while(1) {
        display_time();
        delay_1sec();

        seconds++;
        if (seconds == 60) {
            seconds = 0;
            minutes++;
        }
        if (minutes == 60) {
            minutes = 0;
            hours++;
        }
        if (hours == 24) {
            hours = 0;
        }
    }
}