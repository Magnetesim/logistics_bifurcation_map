#pragma once

#include <stdint.h>

int write_grayscale_8bit_png(const char *filename, int width, int height, uint8_t **image_data);
