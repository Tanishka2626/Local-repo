#include <stdio.h>
#include <stdlib.h> // Required for exit() or general utilities

// Define the maximum size for the name string
#define MAX_NAME_LEN 50
// Define the filename
#define FILENAME "info.txt"

/**
 * @brief Main function to take user input (name, age) and write it to info.txt.
 */
int main() {
    FILE *file_ptr;
    char name[MAX_NAME_LEN];
    int age;

    // 1. Get input from the user
    printf("Enter your name (max %d characters): ", MAX_NAME_LEN - 1);
    // Read string input safely, limiting the buffer size
    if (scanf("%49s", name) != 1) { 
        fprintf(stderr, "Error reading name.\n");
        return 1;
    }

    printf("Enter your age: ");
    // Read integer input
    if (scanf("%d", &age) != 1) {
        fprintf(stderr, "Error reading age.\n");
        return 1;
    }

    // 2. Open the file in write mode ("w").
    // If the file exists, its contents will be truncated (deleted). If it doesn't exist, it will be created.
    file_ptr = fopen(FILENAME, "w");

    // Check if the file was opened successfully
    if (file_ptr == NULL) {
        // If fopen returns NULL, there was an error (e.g., permission denied)
        fprintf(stderr, "Error: Could not open file %s for writing.\n", FILENAME);
        return 1; // Return non-zero to indicate an error
    }

    // 3. Write the data to the file using fprintf()
    // We write a formatted line to the file.
    fprintf(file_ptr, "Name: %s\n", name);
    fprintf(file_ptr, "Age: %d\n", age);

    // 4. Close the file. This flushes the buffer and ensures data is saved to disk.
    fclose(file_ptr);

    // 5. Display confirmation message
    printf("\nSuccess! Data for %s (Age: %d) has been successfully saved to %s.\n", name, age, FILENAME);

    return 0;
}