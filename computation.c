#include <stdlib.h>

typedef double precision; // used so that the precision for the program can be quickly changed from double to float


precision next_iteration(precision r, precision x_old) {
    return r * x_old * (1.0 - x_old); // plain old quadratic difference equation
}

void fill_array(precision *data_array, unsigned int threshold, size_t array_elements, precision r, precision x_initial) {
    precision current_x = x_initial; // seeting current x to x_initial

    for(unsigned int i = 0; i < threshold; i++) {
        current_x = next_iteration(r, x_initial); // iterating the current_x value for a while so it settles
        // into the long term values (2 cycle, 4 cycle, chaos, 3 cycle, etc.)
    }

    for(size_t i = 0; i < array_elements; i++) {
        data_array[i] = current_x; // starts filling in the array
        // i decided to fill the ith position first before updating current_x
        // so that if you use a value of 0 for threshold, the initial value is the first value in the array
        current_x = next_iteration(r, current_x);
    }
}
