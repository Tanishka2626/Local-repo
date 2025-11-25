#include <stdio.h>

int main() {
    char filename[100];
    char text[500];
    FILE *fp;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "a");   // open in append mode
    if (fp == NULL) {
        printf("File not found!\n");
        return 1;
    }

    printf("Enter the text to append: ");
    getchar();  // clear newline from previous input
    fgets(text, sizeof(text), stdin);

    fputs(text, fp);  // append text to file

    printf("Text appended successfully!\n");

    fclose(fp);
    return 0;
}
