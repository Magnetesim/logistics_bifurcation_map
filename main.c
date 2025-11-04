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
    int x;


    return 0;
}
