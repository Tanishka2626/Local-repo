#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char srcName[260], dstName[260];
    FILE *src = NULL, *dst = NULL;
    int ch;

    printf("Enter source filename: ");
    if (scanf("%259s", srcName) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    printf("Enter destination filename: ");
    if (scanf("%259s", dstName) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    src = fopen(srcName, "r");
    if (src == NULL) {
        perror("Error opening source file");
        return 1;
    }

    dst = fopen(dstName, "w");
    if (dst == NULL) {
        perror("Error opening/creating destination file");
        fclose(src);
        return 1;
    }

    /* Copy character-by-character */
    while ((ch = fgetc(src)) != EOF) {
        if (fputc(ch, dst) == EOF) {
            perror("Write error");
            fclose(src);
            fclose(dst);
            return 1;
        }
    }

    printf("File copied successfully from '%s' to '%s'.\n", srcName, dstName);

    fclose(src);
    fclose(dst);
    return 0;
}
