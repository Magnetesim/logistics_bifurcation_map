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
    const char image_name[] = "test_image.png";

    int width = 255;
    int height = 255;

    uint8_t **image_data = (uint8_t**) malloc(sizeof(uint8_t*) * height);
    for(int i = 0; i < height; i++) {
        image_data[i] = malloc(sizeof(uint8_t) * width);
        for(int j = 0; j < width; j++) {
            image_data[i][j] = (uint8_t) (255 - j);
        }
    }

    write_grayscale_8bit_png(image_name, width, height, image_data);


    return 0;
}
