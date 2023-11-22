#include <stdio.h>
#include "pico/stdlib.h"

int main()
{
    stdio_init_all();
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    sleep_ms(1000);    

    printf("Howdy Partner!\n");
    while (!false) 
    {
        sleep_ms(500);
        gpio_put(LED_PIN, 1);
        sleep_ms(500);
        gpio_put(LED_PIN, 0);
        printf("😀\n");
    }
    return 0;
}
