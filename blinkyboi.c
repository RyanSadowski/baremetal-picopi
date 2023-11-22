#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"

void print_buffer(const char *data);
void parse_data(const char *data);


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
        char buffer[256];
        if (fgets(buffer, sizeof(buffer), stdin)) {
            buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
            parse_data(buffer);
        }        sleep_ms(500);
        gpio_put(LED_PIN, 0);
        printf("😀\n");
    }
    return 0;
}

void print_buffer(const char *data){
    for (int i = 0; i < strlen(data); i++) {
        printf("%02X", data[i]);
    }
    printf("\n");
}

void parse_data(const char *data){
    print_buffer(data);   
}

