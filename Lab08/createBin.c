//
// Created by Administrator on 2023/12/10.
//
#include <stdio.h>

int main() {
    double A = 1.0, B = -8.0, C = 12.0;

    FILE *file_write = fopen("input.bin", "wb");
    if (file_write == NULL) {
        perror("Unable to open file for reading");
        return 1;
    }
    fwrite(&A, sizeof(A), 1, file_write);
    fwrite(&B, sizeof(B), 1, file_write);
    fwrite(&C, sizeof(C), 1, file_write);
    fclose(file_write);
    return 0;
} 