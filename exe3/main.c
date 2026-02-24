#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_GREEN = 6;
const int LED_RED   = 4;

const int BTN_RED   = 28;
const int BTN_GREEN = 26;

int main() {
  stdio_init_all();

  
  gpio_init(LED_GREEN);
  gpio_set_dir(LED_GREEN, GPIO_OUT);
  gpio_put(LED_GREEN, 0);

  gpio_init(LED_RED);
  gpio_set_dir(LED_RED, GPIO_OUT);
  gpio_put(LED_RED, 0);

  
  gpio_init(BTN_RED);
  gpio_set_dir(BTN_RED, GPIO_IN);
  gpio_pull_up(BTN_RED);

  gpio_init(BTN_GREEN);
  gpio_set_dir(BTN_GREEN, GPIO_IN);
  gpio_pull_up(BTN_GREEN);

  bool red_on = false;
  bool green_on = false;

  while (true) {
    
    if (!gpio_get(BTN_RED)) {
      red_on = !red_on;
      gpio_put(LED_RED, red_on);

      while (!gpio_get(BTN_RED)) { } 
      sleep_ms(20);                  
    }

    // Botão verde
    if (!gpio_get(BTN_GREEN)) {
      green_on = !green_on;
      gpio_put(LED_GREEN, green_on);

      while (!gpio_get(BTN_GREEN)) { } 
      sleep_ms(20);                    
    }
  }
}