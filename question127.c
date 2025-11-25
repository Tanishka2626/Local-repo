#include <stdio.h>
#include <ctype.h>   // for toupper()

int main() {
    FILE *inFile, *outFile;
    int ch;

    // Open input file
    inFile = fopen("input.txt", "r");
    if (inFile == NULL) {
        printf("Error: input.txt not found!\n");
        return 1;
    }

    // Open output file
    outFile = fopen("output.txt", "w");
    if (outFile == NULL) {
        printf("Error: Unable to create output.txt\n");
        fclose(inFile);
        return 1;
    }

    // Convert lowercase -> uppercase
    while ((ch = fgetc(inFile)) != EOF) {
        fputc(toupper(ch), outFile);
    }

    printf("Conversion complete! Check output.txt\n");

    fclose(inFile);
    fclose(outFile);
    return 0;
}

