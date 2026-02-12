#include "computation.h"


precision next_iteration(precision r, precision x_old) {
    return r * x_old * (1.0 - x_old); // plain old quadratic difference equation
}

// Runs for threshold + array_elements iterations
void fill_array(precision* restrict data_array, unsigned int threshold, size_t array_elements, precision r, precision x_initial) {
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

uint8_t min(int a, int b) {
    return a < b ? a : b; // fast i think because of ternary operator
    // but is this really necessary if a is 255? not sure
}



void sideways_sum_array(precision *restrict data_array, uint8_t* restrict image_array, size_t data_elements, size_t pixel_elements) {
    // assumes max 8 bit grayscale pixel values, so max value is 255, will probably change this later

    for(unsigned int i = 0; i < data_elements; i++) {
        unsigned int temp_index = (int) (data_array[i] * (float) pixel_elements);
        // scaling the float values that range from 0-1.0 to 0-pixel_elements(height) to figure out
        // where to place pixels
        if(image_array[temp_index] != 255) {
            image_array[temp_index] += 16;
        }
        // 255 needs to be max because uint8_t is 8 bits
        // 16 is added each time a value is present at that pixel
        // so that there can be gradients between spots that have more occurences
    }
}