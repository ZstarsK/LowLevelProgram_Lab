#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main() {
    FILE *inputFile, *outputFile, *logFile;
    double a, b, c;
    double discriminant, root1, root2;
    uint8_t numRoots = 0;

    // Open files
    inputFile = fopen("input.bin", "rb");
    outputFile = fopen("output.bin", "wb");
    logFile = fopen("log.txt", "w");

    // Check for file open errors
    if (!inputFile || !outputFile || !logFile) {
        printf("Error opening files.\n");
        return 1;
    }

    //Read a b c
    fseek(inputFile, 0, SEEK_SET);
    fread(&a, sizeof(a), 1, inputFile);
    fread(&b, sizeof(b), 1, inputFile);
    fread(&c, sizeof(c), 1, inputFile);
    fprintf(logFile, "A , B , C : %g, %g, %g\n", a, b, c);

    // Calculate discriminant
    discriminant = b * b - 4 * a * c;
    fprintf(logFile, "Discriminant is equal to %g\n", discriminant);

    // Calculate roots
    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        numRoots = 2;
        printf(" Two real root: %g and %g.\n", root1, root2);
        fprintf(logFile, " Two real root: %g and %g.\n", root1, root2);
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        numRoots = 1;
        printf("One real root: %g\n", root1);
        fprintf(logFile, "One real root: %f\n", root1);
    } else {
        printf("No real roots.\n");
        fprintf(logFile, "No real roots.\n");
    }

    // Write results to output file
    fwrite(&numRoots, sizeof(numRoots), 1, outputFile);
    if (numRoots > 0) {
        fwrite(&root1, sizeof(root1), 1, outputFile);
        if (numRoots == 2) {
            fwrite(&root2, sizeof(root2), 1, outputFile);
        }
    }

    // Close files
    fclose(inputFile);
    fclose(outputFile);
    fclose(logFile);

    return 0;
}
