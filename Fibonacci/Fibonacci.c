#include <stdio.h>
#include "pico/stdlib.h"

int main() {
    unsigned a = 0, b = 1, i = 0, temp;
    stdio_init_all();
    while (true) {
        temp = a;
        a = b;
        b = b + temp;
        i++;
        printf("Fib(%u) = %u\n", i, a);
        if (i == 47) {
            printf("Program stops\n");
            break;
        }
        else
            sleep_ms(1000);
    }
}