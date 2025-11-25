#include <stdio.h>

int main() {
    char filename[100];
    FILE *fp;
    int ch;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");   // open in read mode

    if (fp == NULL) {
        printf("Error: File does not exist!\n");
        return 1;
    }

    printf("\n--- File Content ---\n");

    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);   // display character on screen
    }

    fclose(fp);
    return 0;
}
