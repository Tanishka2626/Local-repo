#include <stdio.h>
#include <stdlib.h> // For exit()

// Define the maximum buffer size for reading a single line
#define BUFFER_SIZE 256
// Define the filename to read from
#define FILENAME "info.txt"

/**
 * @brief Opens and reads the contents of a file line by line using fgets(), 
 * printing each line to the console until the end of the file is reached.
 */
int main() {
    FILE *file_ptr;
    char buffer[BUFFER_SIZE]; // Buffer to store the line read by fgets

    // 1. Open the file in read mode ("r").
    file_ptr = fopen(FILENAME, "r");

    // Check if the file was opened successfully
    if (file_ptr == NULL) {
        // If fopen returns NULL, the file likely does not exist or permissions are wrong.
        fprintf(stderr, "Error: Could not open file '%s' for reading. \n", FILENAME);
        fprintf(stderr, "Please ensure '%s' exists and contains data (e.g., run Q121 first).\n", FILENAME);
        return 1; // Return non-zero to indicate an error
    }

    printf("--- Contents of %s ---\n", FILENAME);
    
    // 2. Read contents using fgets() until EOF
    // fgets returns NULL when the end of file (EOF) is reached or an error occurs.
    while (fgets(buffer, BUFFER_SIZE, file_ptr) != NULL) {
        // Print the contents of the buffer (which holds the current line) to the console.
        // fgets includes the newline character if it fits in the buffer.
        printf("%s", buffer);
    }

    // Check for reading errors if needed (beyond scope, but good practice)

    // 3. Close the file.
    if (fclose(file_ptr) == EOF) {
        fprintf(stderr, "Error closing the file.\n");
        return 1;
    }

    printf("--------------------------\n");
    printf("Successfully finished reading file contents.\n");

    return 0;
}