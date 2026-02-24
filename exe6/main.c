#include <stdio.h>
#include "hardware/gpio.h"
#include "pico/stdlib.h"

static const int FIRST_GPIO = 2;
static const int BTN_PIN_G  = 28;

static const int bits[10] = {
    0x3f,  // 0
    0x06,  // 1
    0x5b,  // 2
    0x4f,  // 3
    0x66,  // 4
    0x6d,  // 5
    0x7d,  // 6
    0x07,  // 7
    0x7f,  // 8
    0x67   // 9
};

static void seven_seg_init(void) {
    for (int gpio = FIRST_GPIO; gpio < (FIRST_GPIO + 7); gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        gpio_put(gpio, 0);
    }
}

static void seven_seg_display(int digit) {
    if (digit < 0 || digit > 9) {
        digit = 0; 
    }

    const int value = bits[digit];

    for (int i = 0; i < 7; i++) {
        const int gpio = FIRST_GPIO + i;
        const int bit  = (value >> i) & 1;
        gpio_put(gpio, bit);
    }
}

int main(void) {
    stdio_init_all();

    int cnt = 0;

    gpio_init(BTN_PIN_G);
    gpio_set_dir(BTN_PIN_G, GPIO_IN);
    gpio_pull_up(BTN_PIN_G);

    seven_seg_init();
    seven_seg_display(cnt);

    int last_btn = gpio_get(BTN_PIN_G); 

    while (true) {
        const int btn = gpio_get(BTN_PIN_G);

        if (last_btn && !btn) {
            cnt++;
            if (cnt > 9) {
                cnt = 0;
            }

            seven_seg_display(cnt);
            printf("cnt: %d\n", cnt);
        }

        last_btn = btn;
        sleep_ms(10);
    }
}