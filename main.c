#include "computation.h"
#include "image_processing.h"

#include <stdio.h>
#include <stdint.h>

void fill_thread_info(perThreadInfo *info, _Atomic unsigned int x, precision **data_arrays, unsigned int threshold,
                      size_t array_elements, precision r, precision x_initial) {
    info->x = x;
    info->data_arrays = data_arrays;
    info->threshold = threshold;
    info->array_elements = array_elements;
    info->r = r;
    info->x_initial = x_initial;
}

int main(void) {
    const char image_name[] = "bifurcation_map.png";
    int width = 1024;
    int height = 1024;

    precision max_r = 4.0;

    uint8_t **image_data = (uint8_t**) malloc(sizeof(uint8_t*) * height);
    for(unsigned int i = 0; i < height; i++) {
        image_data[i] = calloc(sizeof(uint8_t), width);
        // calloc necessary here since sideways_sum_array assumes pixels are set to 0
    }

    for(unsigned int i = 0; i < height; i++) {
        precision* temp_data_array = malloc(sizeof(precision) * 100);
        precision r_value = max_r * ((precision) i) / ((precision) height);
        fill_array(temp_data_array, 5000, 100, r_value, 0.5);
        sideways_sum_array(temp_data_array, image_data[i], 100, height);
    }

    write_grayscale_8bit_png(image_name, width, height, image_data);


    return 0;
}
