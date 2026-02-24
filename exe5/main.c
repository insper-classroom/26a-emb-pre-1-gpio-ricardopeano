#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN_PIN   = 26;
const int BTN_PIN_2 = 7;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  gpio_init(BTN_PIN_2);
  gpio_set_dir(BTN_PIN_2, GPIO_IN);
  gpio_pull_up(BTN_PIN_2);

  int cnt_1 = 0;
  int cnt_2 = 0;

  bool last_1 = true; 
  bool last_2 = true;

  absolute_time_t last_time_1 = 0;
  absolute_time_t last_time_2 = 0;

  const int DEBOUNCE_MS = 30;

  while (true) {
    bool now_1 = gpio_get(BTN_PIN);
    bool now_2 = gpio_get(BTN_PIN_2);

    if (last_1 && !now_1) {
      absolute_time_t t = get_absolute_time();
      if (absolute_time_diff_us(last_time_1, t) > (DEBOUNCE_MS * 1000)) {
        last_time_1 = t;
        cnt_1++;
        printf("Botao 1: %d\n", cnt_1);
      }
    }

    if (last_2 && !now_2) {
      absolute_time_t t = get_absolute_time();
      if (absolute_time_diff_us(last_time_2, t) > (DEBOUNCE_MS * 1000)) {
        last_time_2 = t;
        cnt_2++;
        printf("Botao 2: %d\n", cnt_2);
      }
    }

    last_1 = now_1;
    last_2 = now_2;

    sleep_ms(1); 
  }
}