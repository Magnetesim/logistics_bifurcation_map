#include "computation.h"

#include <stdio.h>

int main(void) {
    precision data[20];

    fill_array(data, 1000, 20, 3.5, 0.5);

    for(int i = 0; i < 20; i++) {
        printf("%.3f\n", data[i]);
    }

    return 0;
}
