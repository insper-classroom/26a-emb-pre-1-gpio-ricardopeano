#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_RED    = 5;
const int LED_PURPLE = 8;
const int LED_BLUE   = 11;
const int LED_YELLOW = 15; 

const int BTN_RED = 28;

static void all_off(void) {
  gpio_put(LED_RED, 0);
  gpio_put(LED_PURPLE, 0);
  gpio_put(LED_BLUE, 0);
  gpio_put(LED_YELLOW, 0);
}

int main() {
  stdio_init_all();

  gpio_init(LED_RED);    gpio_set_dir(LED_RED, GPIO_OUT);
  gpio_init(LED_PURPLE); gpio_set_dir(LED_PURPLE, GPIO_OUT);
  gpio_init(LED_BLUE);   gpio_set_dir(LED_BLUE, GPIO_OUT);
  gpio_init(LED_YELLOW); gpio_set_dir(LED_YELLOW, GPIO_OUT);

  all_off();

  gpio_init(BTN_RED);
  gpio_set_dir(BTN_RED, GPIO_IN);
  gpio_pull_up(BTN_RED);

  while (true) {
    if (!gpio_get(BTN_RED)) {
      
      all_off();
      gpio_put(LED_RED, 1);
      sleep_ms(300);

      all_off();
      gpio_put(LED_PURPLE, 1);
      sleep_ms(300);

      all_off();
      gpio_put(LED_BLUE, 1);
      sleep_ms(300);

      all_off();
      gpio_put(LED_YELLOW, 1);
      sleep_ms(300);

      all_off();

      while (!gpio_get(BTN_RED)) { }
      sleep_ms(20); 
    }
  }
}