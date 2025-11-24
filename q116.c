#include <stdio.h>

/**
 * @brief Finds the indices of two distinct numbers in an array that sum up to a target.
 *
 * This implementation uses a simple brute-force approach with O(n^2) time complexity.
 * It iterates over all unique pairs (i, j) where i < j.
 *
 * @param nums The input integer array (contains positive integers).
 * @param n The size of the array.
 * @param target The target sum.
 */
void findTwoSum(int nums[], int n, int target) {
    // Outer loop iterates through the first number
    for (int i = 0; i < n - 1; i++) {
        // Inner loop iterates through the second number, starting after i to ensure distinct indices
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                // Found the solution. Print indices and return immediately.
                printf("%d %d\n", i, j);
                return;
            }
        }
    }

    // Fallback: If the loop completes without finding a solution.
    printf("-1 -1\n");
}

// Main function to test the program
int main() {
    // --- Input 1 ---
    int nums1[] = {2, 7, 11, 15};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    int target1 = 9;
    
    printf("Input 1: nums = [2, 7, 11, 15], target = %d\n", target1);
    printf("Output 1:\n");
    findTwoSum(nums1, n1, target1); // Expected: 0 1
    printf("\n");

    // --- Input 2 ---
    int nums2[] = {3, 2, 4};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    int target2 = 6;
    
    printf("Input 2: nums = [3, 2, 4], target = %d\n", target2);
    printf("Output 2:\n");
    findTwoSum(nums2, n2, target2); // Expected: 1 2
    printf("\n");

    // --- Input 3 (Duplicates) ---
    int nums3[] = {3, 3};
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    int target3 = 6;
    
    printf("Input 3: nums = [3, 3], target = %d\n", target3);
    printf("Output 3:\n");
    findTwoSum(nums3, n3, target3); // Expected: 0 1
    
    return 0;
}