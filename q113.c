#include <stdio.h>
#include <stdlib.h> // Required for the qsort function

/**
 * @brief Comparison function required by qsort to sort integers in ascending order.
 * * @param a Pointer to the first element (int).
 * @param b Pointer to the second element (int).
 * @return int A value < 0, 0, or > 0 if a is less than, equal to, or greater than b, respectively.
 */
int compareIntegers(const void *a, const void *b) {
    // Cast the void pointers to integer pointers and dereference them
    return (*(int *)a - *(int *)b);
}

/**
 * @brief Finds the k-th smallest element in an integer array.
 * * The function sorts the array in ascending order using qsort (O(N log N)) 
 * and then returns the element at the (k-1)th index.
 * * @param arr The input integer array.
 * @param n The size of the input array.
 * @param k The desired rank (1st smallest, 2nd smallest, etc.).
 * @return int The k-th smallest element. Returns -1 if k is out of range.
 */
int findKthSmallest(int arr[], int n, int k) {
    // Input validation
    if (k <= 0 || k > n) {
        printf("Error: k is out of range (must be between 1 and %d).\n", n);
        return -1; // Indicate error
    }

    // 1. Sort the entire array in ascending order.
    // Time complexity: O(N log N)
    qsort(arr, n, sizeof(int), compareIntegers);

    // 2. The k-th smallest element is at index k-1 (since arrays are 0-indexed).
    return arr[k - 1];
}

// Main function to test the program
int main() {
    // --- Input 1 ---
    int arr1[] = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 4;
    
    // Note: Since qsort modifies the original array, we use a temporary copy if we
    // needed the original array later, but for this specific task, modification is fine.
    int result1 = findKthSmallest(arr1, n1, k1); 

    printf("Input 1: arr[] = [10, 5, 4, 3, 48, 6, 2, 33, 53, 10], k = %d\n", k1);
    printf("Output 1: %d\n", result1);
    printf("Explanation 1: 4th smallest element in the given array is 5.\n\n");
    
    // --- Input 2 ---
    int arr2[] = {7, 10, 4, 3, 20, 15};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 3;

    int result2 = findKthSmallest(arr2, n2, k2); 
    
    printf("Input 2: arr[] = [7, 10, 4, 3, 20, 15], k = %d\n", k2);
    printf("Output 2: %d\n", result2);
    printf("Explanation 2: 3rd smallest element in the given array is 7.\n");

    return 0;
}