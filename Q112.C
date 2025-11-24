#include <stdio.h>
#include <limits.h> // For INT_MIN

/**
 * @brief Finds the maximum sum of a contiguous subarray using Kadane's Algorithm.
 * * Kadane's algorithm works by maintaining two variables:
 * 1. max_so_far: The maximum sum found anywhere in the array so far.
 * 2. current_max: The maximum sum ending at the current array position (i).
 * * @param arr The input integer array.
 * @param n The size of the input array.
 * @return The maximum contiguous subarray sum.
 */
long long maxSubarraySum(int arr[], int n) {
    // Check for an empty array
    if (n <= 0) {
        return 0;
    }

    // Use long long for sums to prevent potential integer overflow, 
    // although the elements are standard ints.
    long long max_so_far = (long long)INT_MIN; // Overall maximum sum found
    long long current_max = 0;                  // Maximum sum ending at the current position

    // Flag to check if the array contains at least one non-negative element
    int all_negative = 1;
    
    // First pass: Find the overall maximum sum using Kadane's main logic
    for (int i = 0; i < n; i++) {
        // If we find a non-negative element, the 'all_negative' case is void.
        if (arr[i] >= 0) {
            all_negative = 0;
        }
        
        // 1. Update current_max: Add the current element to the sum ending at the previous element.
        current_max = current_max + arr[i];

        // 2. Reset current_max if it becomes negative. 
        // A negative subarray sum will never contribute to a larger overall sum.
        if (current_max < 0) {
            current_max = 0;
        }

        // 3. Update max_so_far: If the sum ending at the current position is the largest seen so far.
        if (current_max > max_so_far) {
            max_so_far = current_max;
        }
    }

    // Handle the edge case: if all elements are negative
    if (all_negative) {
        // In this case, the standard Kadane's will return 0 (due to current_max reset).
        // We must re-evaluate to find the largest (least negative) single element.
        long long largest_negative = (long long)INT_MIN;
        for (int i = 0; i < n; i++) {
            if (arr[i] > largest_negative) {
                largest_negative = arr[i];
            }
        }
        return largest_negative;
    }

    // If there was at least one positive element, max_so_far holds the correct result.
    return max_so_far;
}

// Main function to test the program
int main() {
    // Example 1: Standard case with positive and negative numbers
    int arr1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]); // Expected: 6 (from [4, -1, 2, 1])
    
    printf("Array 1: {-2, 1, -3, 4, -1, 2, 1, -5, 4}\n");
    printf("Maximum contiguous sum: %lld\n", maxSubarraySum(arr1, n1));

    // Example 2: All positive numbers
    int arr2[] = {1, 2, 3, 4, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]); // Expected: 15
    
    printf("\nArray 2: {1, 2, 3, 4, 5}\n");
    printf("Maximum contiguous sum: %lld\n", maxSubarraySum(arr2, n2));

    // Example 3: All negative numbers (edge case)
    int arr3[] = {-2, -3, -1, -5, -4};
    int n3 = sizeof(arr3) / sizeof(arr3[0]); // Expected: -1 (the largest/least negative element)
    
    printf("\nArray 3: {-2, -3, -1, -5, -4}\n");
    printf("Maximum contiguous sum: %lld\n", maxSubarraySum(arr3, n3));

    // Example 4: Mixed, ending with negative elements
    int arr4[] = {10, -5, 8, -20, 1};
    int n4 = sizeof(arr4) / sizeof(arr4[0]); // Expected: 13 (from [10, -5, 8])
    
    printf("\nArray 4: {10, -5, 8, -20, 1}\n");
    printf("Maximum contiguous sum: %lld\n", maxSubarraySum(arr4, n4));

    return 0;
}