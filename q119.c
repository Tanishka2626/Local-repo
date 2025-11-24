#include <stdio.h>

// Define a maximum possible value for elements in the array. 
// This must be large enough to cover the largest expected element value in the input array.
// We assume a maximum value of 100,000 for standard constraints.
#define MAX_VAL 100000 

/**
 * @brief Finds the single repeated element in an array in a single O(N) iteration.
 *
 * This function uses a frequency map (an auxiliary array) to track visited elements.
 * The index of the visited array corresponds to the value of the number in the input array.
 *
 * @param nums The input integer array containing positive integers.
 * @param n The size of the array.
 * @return int The repeated element, or -1 if no duplicate is found.
 */
int findDuplicate(int nums[], int n) {
    // Auxiliary array 'visited' acts as a frequency map. 
    // It's initialized to 0, meaning no element has been seen yet.
    int visited[MAX_VAL] = {0}; 

    // Iterate through the array elements once (O(n) time complexity)
    for (int i = 0; i < n; i++) {
        int current_val = nums[i];

        // Simple check to prevent segmentation fault if the element value exceeds MAX_VAL
        if (current_val >= MAX_VAL || current_val < 0) {
            fprintf(stderr, "Error: Element %d is out of assumed range [0, %d).\n", current_val, MAX_VAL);
            return -1;
        }

        // Check if the current value has been seen before
        if (visited[current_val] == 1) {
            // Found the repeated element. Return it immediately.
            return current_val;
        }

        // Mark the current value as visited
        visited[current_val] = 1;
    }

    // Should ideally not be reached based on the problem statement
    return -1; 
}

// Main function to test the program
int main() {
    int result;

    // --- Input 1 ---
    int nums1[] = {1, 3, 3, 4};
    int n1 = sizeof(nums1) / sizeof(nums1[0]); 
    result = findDuplicate(nums1, n1);
    
    printf("Input 1: nums1 = [1, 3, 3, 4]\n");
    printf("Output 1:\n%d\n", result); // Expected: 3

    // --- Input 2 ---
    int nums2[] = {1, 2, 2};
    int n2 = sizeof(nums2) / sizeof(nums2[0]); 
    result = findDuplicate(nums2, n2);
    
    printf("\nInput 2: nums1 = [1, 2, 2]\n");
    printf("Output 2:\n%d\n", result); // Expected: 2

    // --- Input 3 ---
    int nums3[] = {0, 4, 1, 1, 5};
    int n3 = sizeof(nums3) / sizeof(nums3[0]); 
    result = findDuplicate(nums3, n3);
    
    printf("\nInput 3: nums1 = [0, 4, 1, 1, 5]\n");
    printf("Output 3:\n%d\n", result); // Expected: 1

    return 0;
}