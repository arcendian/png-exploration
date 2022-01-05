#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PNG_UTILS_H
#define PNG_UTILS_H
#define PNG_SIGNATURE_SIZE 8

void read_buffer_or_panic(FILE *file, uint8_t *buffer, size_t buffer_size);
void print_bytes(uint8_t *buffer, size_t buffer_size);
bool verify_signatures(const uint8_t *file_signature);

#endif // PNG_UTILS_H
