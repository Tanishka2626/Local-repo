#include <stdio.h>
#include <limits.h> // For INT_MIN

/**
 * @brief Finds and prints the maximum element in every contiguous subarray of size k
 * using a simple, brute-force approach.
 *
 * This method iterates through all possible windows and then iterates through all
 * elements within that window to find the maximum.
 * Time complexity: O(n * k).
 *
 * @param arr The input integer array.
 * @param n The size of the input array.
 * @param k The size of the sliding window.
 */
void printMax(int arr[], int n, int k) {
    // Check for invalid input
    if (k > n || k <= 0) {
        printf("Invalid window size (k must be between 1 and %d)\n", n);
        return;
    }

    // Outer loop: Starts at the first element (i=0) and goes up to the index
    // where the last window starts (n - k).
    for (int i = 0; i <= n - k; i++) {
        int current_max = INT_MIN; // Initialize max for the current window

        // Inner loop: Iterates through the k elements in the current window,
        // from the start index 'i' up to the end index 'i + k - 1'.
        for (int j = 0; j < k; j++) {
            if (arr[i + j] > current_max) {
                current_max = arr[i + j];
            }
        }

        // Print the maximum found in this window
        printf("%d ", current_max);
    }

    printf("\n"); // Print a newline at the end
}

// Main function to test the program
int main() {
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // Window size

    printf("Input Array: {1, 3, -1, -3, 5, 3, 6, 7}\n");
    printf("Window Size (k): %d\n", k);
    printf("Maximum elements in each window of size %d:\n", k);

    printMax(arr, n, k); // Expected Output: 3 3 5 5 6 7

    // Another example
    int arr2[] = {12, 1, 78, 90, 57, 89, 56};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 3;

    printf("\nInput Array: {12, 1, 78, 90, 57, 89, 56}\n");
    printf("Window Size (k): %d\n", k2);
    printf("Maximum elements in each window of size %d:\n", k2);

    printMax(arr2, n2, k2); // Expected Output: 78 90 90 89 89

    return 0;
}