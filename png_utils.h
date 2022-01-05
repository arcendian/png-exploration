#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PNG_UTILS_H
#define PNG_UTILS_H
#define PNG_SIGNATURE_SIZE 8

void read_bytes_or_panic(FILE *file, void *buffer, size_t buffer_size);
void print_bytes(uint8_t *buffer, size_t buffer_size);
bool verify_signatures(const uint8_t *file_signature);
void reverse_bytes(void *buffer, size_t buffer_size);

#endif // PNG_UTILS_H
