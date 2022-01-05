#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "png_utils.h"

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
    if (verify_signatures(signature) == false) {
        fprintf(stderr, "ERROR: %s does not appear to be a valid PNG image\n",
                input_filepath);
        exit(1);
    }

    printf("Read a valid PNG image: %s\n", input_filepath);
    fclose(input_file);
    return 0;
}
