#include <stdio.h>

/**
 * @brief Finds the missing number in an array of size n containing unique numbers 
 * from the range [0, n], where n is the size of the array.
 * * This function uses the mathematical summation formula (Gauss' formula) 
 * for an O(n) time complexity solution.
 * * @param nums The input integer array.
 * @param n The size of the input array (meaning numbers are from 0 to n).
 * @return int The missing number.
 */
int findMissingNumber(int nums[], int n) {
    // Since the array size is 'n', the total count of numbers in the full 
    // sequence (including the missing one) is N_total = n + 1.
    // The range of numbers is [0, n].

    // 1. Calculate the expected sum of all numbers from 0 to n (the length of the sequence is n+1).
    // Use long long to prevent potential overflow, although for typical constraints, int might suffice.
    long long expected_sum = (long long)n * (n + 1) / 2;
    
    // 2. Calculate the actual sum of the elements present in the array.
    long long actual_sum = 0;
    for (int i = 0; i < n; i++) {
        actual_sum += nums[i];
    }
    
    // 3. The missing number is the difference.
    int missing_number = (int)(expected_sum - actual_sum);
    
    return missing_number;
}

// Main function to test the program
int main() {
    // --- Input 1 ---
    int nums1[] = {0, 3, 2, 4};
    int n1 = sizeof(nums1) / sizeof(nums1[0]); // n1 = 4, range is [0, 4]
    int result1 = findMissingNumber(nums1, n1);
    
    printf("Input 1: nums1 = [0, 3, 2, 4]\n");
    printf("Output 1:\n%d\n", result1); // Expected: 1
    
    // --- Input 2 ---
    int nums2[] = {1, 2, 3};
    int n2 = sizeof(nums2) / sizeof(nums2[0]); // n2 = 3, range is [0, 3]
    int result2 = findMissingNumber(nums2, n2);
    
    printf("\nInput 2: nums1 = [1, 2, 3]\n");
    printf("Output 2:\n%d\n", result2); // Expected: 0
    
    // --- Input 3 ---
    int nums3[] = {0, 4, 3, 1, 5};
    int n3 = sizeof(nums3) / sizeof(nums3[0]); // n3 = 5, range is [0, 5]
    int result3 = findMissingNumber(nums3, n3);
    
    printf("\nInput 3: nums1 = [0, 4, 3, 1, 5]\n");
    printf("Output 3:\n%d\n", result3); // Expected: 2

    return 0;
}