#include "Fibonacci_gen.h"

unsigned fibonacci_generator() {
    static unsigned a = 0, b = 1;
    unsigned temp;
    temp = a;
    a = b;
    b = b + temp;
    return a;
}