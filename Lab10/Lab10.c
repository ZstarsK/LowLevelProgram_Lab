#include <stdio.h>
#include <math.h>

typedef struct {
    unsigned char type_and_color;
    unsigned short x, y;
    unsigned int size;
} Figure;

double calculate_area(Figure fig) {
    if (fig.type_and_color >> 7 == 0) {
        return M_PI * fig.size * fig.size;
    } else {
        return fig.size * fig.size;
    }
}

int is_pure_red(Figure fig) {
    return (fig.type_and_color & 0x3C) == 0x30;
}

int is_pure_green_square(Figure fig) {
    return (fig.type_and_color & 0x3F) == 0x0C && fig.type_and_color >> 7 == 1;
}

int main() {
    FILE *inputFile, *outputFile;
    Figure figures[100];
    int figureCount = 0;
    double greenSquareArea = 0.0;

    inputFile = fopen("input.bin", "rb");
    if (inputFile == NULL) {
        perror("No file \"input.bin\"");
        return 1;
    }

    // Reading graphic data
    while (figureCount < 100 && fread(&figures[figureCount], sizeof(Figure), 1, inputFile)) {
        figureCount++;
    }
    fclose(inputFile);

    // Creating the output.bin file
    outputFile = fopen("output.bin", "wb");
    if (outputFile == NULL) {
        perror("Cant create file \"output.bin\"");
        return 1;
    }

    // Write a solid red circle first
    for (int i = 0; i < figureCount; i++) {
        if (is_pure_red(figures[i])) {
            fwrite(&figures[i], sizeof(Figure), 1, outputFile);
        }
    }

    // Write to other graphics
    for (int i = 0; i < figureCount; i++) {
        if (!is_pure_red(figures[i])) {
            fwrite(&figures[i], sizeof(Figure), 1, outputFile);

            // Cumulative area of solid green squares
            if (is_pure_green_square(figures[i])) {
                greenSquareArea += calculate_area(figures[i]);
            }
        }
    }

    fclose(outputFile);

    printf("The cumulative area of a solid green square is: %f\n", greenSquareArea);

    return 0;
}
