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
        // Area of Circle
        return M_PI * fig.size * fig.size;
    } else {
        // Area of Square
        return fig.size * fig.size;
    }
}

int main() {
    FILE *inputFile, *outputFile;
    Figure figures[100], maxAreaFigure;
    int figureCount = 0, maxAreaIndex = -1;
    double minArea = INFINITY, maxArea = 0;

    inputFile = fopen("input.bin", "rb");
    if (inputFile == NULL) {
        perror("Cant open file \"input.bin\"");
        return 1;
    }

    /* READ FIGURE DATA */
    while (figureCount < 100 && fread(&figures[figureCount], sizeof(Figure), 1, inputFile)) {
        double area = calculate_area(figures[figureCount]);
        if (area < minArea) {
            minArea = area;
        }
        if (area > maxArea) {
            maxArea = area;
            maxAreaFigure = figures[figureCount];
            maxAreaIndex = figureCount;
        }
        figureCount++;
    }
    fclose(inputFile);

    // Create "output.bin" File
    outputFile = fopen("output.bin", "wb");
    if (outputFile == NULL) {
        perror("Cant create file \"output.bin\"");
        return 1;
    }

    // If a figure with the largest area exists, write it first
    if (maxAreaIndex != -1) {
        fwrite(&maxAreaFigure, sizeof(Figure), 1, outputFile);
    }

    // Write other graphics, skipping the graphics with the smallest area
    for (int i = 0; i < figureCount; i++) {
        double area = calculate_area(figures[i]);
        if (area != minArea || (figureCount == 1 && i == maxAreaIndex)) {
            fwrite(&figures[i], sizeof(Figure), 1, outputFile);
        }
    }

    fclose(outputFile);
    printf("Success!\n");

    return 0;
}
