#include <stdio.h>
#include <stdlib.h> // For array indexing

// Define a maximum size for the array and queue.
#define MAX_SIZE 1000

/**
 * @brief Finds the first negative integer in every contiguous subarray of size k.
 *
 * This function uses a Queue (implemented as a fixed-size array of indices) to
 * efficiently track the position of negative numbers.
 * Time complexity: O(n).
 *
 * @param arr The input integer array.
 * @param n The size of the input array.
 * @param k The size of the sliding window.
 */
void findFirstNegative(int arr[], int n, int k) {
    // Check for invalid input
    if (k > n || k <= 0) {
        printf("Invalid window size (k must be between 1 and %d)\n", n);
        return;
    }

    // Queue stores the indices of all negative elements currently in the window.
    int queue[MAX_SIZE];
    int front = 0; // Index of the front of the queue
    int rear = 0;  // Index of the rear of the queue (where the next element will be added)

    // Iterate through the array from the start to the end
    for (int i = 0; i < n; i++) {

        // 1. ADD NEW ELEMENT INDEX
        // If the current element is negative, add its index to the back of the queue.
        if (arr[i] < 0) {
            queue[rear] = i;
            rear++;
        }

        // 2. CHECK & REMOVE OLD INDEX (Window Contraction)
        // If the index at the front of the queue falls outside the current window
        // (which starts at i - k + 1), remove it.
        if (front != rear && queue[front] == i - k) {
            front++; // Dequeue from front
        }

        // 3. PRINT RESULT (Only start printing once the window is full, i.e., i >= k-1)
        if (i >= k - 1) {
            // If the queue is NOT empty, the element at the index stored at the front
            // is the first negative number in the current window.
            if (front != rear) {
                printf("%d ", arr[queue[front]]);
            } else {
                // If the queue IS empty, there are no negative numbers in the window.
                printf("0 ");
            }
        }
    }

    printf("\n"); // Print a newline at the end
}

// Main function to test the program
int main() {
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // Window size

    printf("Input Array: {12, -1, -7, 8, -15, 30, 16, 28}\n");
    printf("Window Size (k): %d\n", k);
    printf("First negative elements in each window of size %d:\n", k);

    // Expected Output: -1 -1 -7 8 -15 -15 0
    // Window [12, -1, -7] -> -1
    // Window [-1, -7, 8] -> -1
    // Window [-7, 8, -15] -> -7
    // Window [8, -15, 30] -> -15
    // Window [-15, 30, 16] -> -15
    // Window [30, 16, 28] -> 0
    findFirstNegative(arr, n, k);

    // Another example
    int arr2[] = {-8, 2, 3, -6, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 2;

    printf("\nInput Array: {-8, 2, 3, -6, 10}\n");
    printf("Window Size (k): %d\n", k2);
    printf("First negative elements in each window of size %d:\n", k2);

    // Expected Output: -8 -8 0 -6
    findFirstNegative(arr2, n2, k2);

    return 0;
}