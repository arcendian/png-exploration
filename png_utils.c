#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "png_utils.h"

void read_buffer_or_panic(FILE *file, uint8_t *buffer, size_t buffer_size) {
    size_t n = fread(buffer, buffer_size, 1, file);
    if (n != 1) {
        if (ferror(file)) {
            fprintf(stderr, "ERROR: could not read PNG header: %s\n",
                    strerror(errno));
            exit(1);
        } else {
            fprintf(stderr, "ERROR: %s is possibly empty!\n", __FILE__);
            exit(1);
        }
    }
}

void print_bytes(uint8_t *buffer, size_t buffer_size) {
    for (size_t i = 0; i < buffer_size; i++) {
        printf("%u ", buffer[i]);
    }
    putchar('\n');
}

bool verify_signatures(const uint8_t *file_signature) {
    const uint8_t png_signature[PNG_SIGNATURE_SIZE] = {137, 80, 78, 71,
                                                       13,  10, 26, 10};
    if (memcmp(file_signature, png_signature, PNG_SIGNATURE_SIZE) != 0) {
        return false;
    }
    return true;
}
