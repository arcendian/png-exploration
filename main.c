#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PNG_SIGNATURE_SIZE 8

const uint8_t png_signature[PNG_SIGNATURE_SIZE] = {137, 80, 78, 71,
                                                   13,  10, 26, 10};

void read_buffer_or_panic(FILE *file, uint8_t *buffer, size_t buffer_size) {
    size_t n = fread(buffer, buffer_size, 1, file);
    if (n != 1) {
        if (ferror(file)) {
            fprintf(stderr, "ERROR: could not read PNG header: %s\n",
                    strerror(errno));
            exit(1);
        } else {
            assert(0 && "unreachable");
        }
    }
}

void print_bytes(uint8_t *buffer, size_t buffer_size) {
    for (size_t i = 0; i < buffer_size; i++) {
        printf("%u ", buffer[i]);
    }
    putchar('\n');
}

int main(int argc, char **argv) {
    (void)argc;
    assert(*argv != NULL);
    char *program = *argv++;

    if (*argv == NULL) {
        fprintf(stderr, "ERROR: no input file provided\n");
        fprintf(stderr, "USAGE: %s <input.png>\n", program);
        exit(1);
    }

    char *input_filepath = *argv++;
    FILE *input_file = fopen(input_filepath, "rb");
    if (input_file == NULL) {
        fprintf(stderr, "ERROR: could not open file %s: %s\n", input_filepath,
                strerror(errno));
        exit(1);
    }

    uint8_t signature[8];
    read_buffer_or_panic(input_file, signature, PNG_SIGNATURE_SIZE);
    print_bytes(signature, PNG_SIGNATURE_SIZE);
    if (memcmp(signature, png_signature, PNG_SIGNATURE_SIZE) != 0) {
        fprintf(stderr, "ERROR: %s does not appear to be a valid PNG image",
                input_filepath);
        exit(1);
    }

    printf("Read a valid PNG image: %s\n", input_filepath);
    fclose(input_file);
    return 0;
}
