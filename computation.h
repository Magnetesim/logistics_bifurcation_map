#include <stdlib.h>

typedef double precision;

typedef struct perThreadInfo {
    _Atomic unsigned int x; // depends on gcc for _Atomic
    precision **data_arrays; // contains all of the arrays
    unsigned int threshold; // threshold (can be set for a per thread basis.. redundant because
    // I probably won't use that feature
    size_t array_elements; // num of array elements for fill_array
    precision r;
    precision x_initial; // values
} perThreadInfo;

void fill_array(precision *data_array, unsigned int threshold, size_t array_elements, precision r, precision x_initial);
