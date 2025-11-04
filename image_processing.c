#include <stdio.h>
#include <png.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

int write_grayscale_8bit_png(const char *filename, int width, int height, uint8_t **image_data) {

    FILE *png_file = NULL;
    png_structp png_ptr = NULL;
    png_infop info_ptr = NULL;
    int code = 0;

    errno = 0;

    png_file = fopen(filename, "wb");
    if(!png_file) {
        perror("Error opening file!");
        return -1;
    }


    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if(!png_ptr) {
        fprintf(stderr, "Error creating png write struct");
        code = -2;
        goto error_dungeon;
    }

    info_ptr = png_create_info_struct(png_ptr);
    if(!info_ptr) {
        fprintf(stderr, "Error creating png info struct");
        code = -3;
        goto error_dungeon;
    }

    if(setjmp(png_jmpbuf(png_ptr))) {
        fprintf(stderr, "Error during PNG creation");
        code = -4;
        goto error_dungeon;
    }

    png_init_io(png_ptr, png_file);

    png_set_IHDR(png_ptr, info_ptr, width, height, 8, PNG_COLOR_TYPE_GRAY, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
    // grayscale image with 8 bit color depth, probably going to make a 16 bit version of this function later for higher quality images
    

    png_write_info(png_ptr, info_ptr);

    png_write_image(png_ptr, image_data);

    png_write_end(png_ptr, info_ptr);

    printf("Successfully wrote file %s\n", filename);

    error_dungeon:
        if (png_file) fclose(png_file);
        if(png_ptr) png_destroy_write_struct(&png_ptr, &info_ptr);

    return code;
}
