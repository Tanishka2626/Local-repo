#include <stdio.h>

int main() {
    FILE *fp;
    char name[50];
    int roll, marks;
    int n, i;

    fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Writing records using fprintf()
    for (i = 1; i <= n; i++) {
        printf("\nEnter details of student %d:\n", i);

        printf("Name: ");
        scanf("%s", name);

        printf("Roll Number: ");
        scanf("%d", &roll);

        printf("Marks: ");
        scanf("%d", &marks);

        fprintf(fp, "%s %d %d\n", name, roll, marks);
    }

    fclose(fp);

    // Reading records using fscanf()
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    printf("\n--- Student Records from File ---\n");

    while (fscanf(fp, "%s %d %d", name, &roll, &marks) != EOF) {
        printf("Name: %s, Roll: %d, Marks: %d\n", name, roll, marks);
    }

    fclose(fp);

    return 0;
}
