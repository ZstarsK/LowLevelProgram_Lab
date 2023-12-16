//
// Created by Administrator on 2023/12/12.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    unsigned char type;
    unsigned char color[3];
    unsigned short x, y;
    unsigned int size;
} Figure;

double calculate_area(Figure fig) {
    if (fig.type == 0) {
        return M_PI * fig.size * fig.size;
    } else {
        return fig.size * fig.size;
    }
}

int main() {
    FILE *file;
    Figure fig;
    double area, maxArea = 0;
    int isFirst = 1;

    file = fopen("output.bin", "rb");
    if (file == NULL) {
        perror("cant open output.bin");
        return 1;
    }

    while (fread(&fig, sizeof(Figure), 1, file)) {
        area = calculate_area(fig);

        // If the first figure has Max area
        if (isFirst) {
            maxArea = area;
            isFirst = 0;
        } else if (area > maxArea) {
            printf("Error\n");
            return 1;
        }

        // print figure info
        printf("Type: %d, Area: %f\n", fig.type, area);
    }

    fclose(file);
    printf("Success \n");

    return 0;
}
