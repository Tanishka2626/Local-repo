#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Merges two sorted integer arrays into a single sorted array.
 *
 * This function uses the Two-Pointer technique for an efficient O(M + N) merge.
 *
 * @param nums1 The first sorted input array.
 * @param m The size of nums1.
 * @param nums2 The second sorted input array.
 * @param n The size of nums2.
 * @param merged_array The pointer to the array where the result will be stored.
 */
void mergeSortedArrays(int nums1[], int m, int nums2[], int n, int merged_array[]) {
    int i = 0; // Pointer for nums1
    int j = 0; // Pointer for nums2
    int k = 0; // Pointer for merged_array

    // 1. Traverse both arrays and fill the merged array
    while (i < m && j < n) {
        if (nums1[i] <= nums2[j]) {
            // Take the element from nums1
            merged_array[k] = nums1[i];
            i++;
        } else {
            // Take the element from nums2
            merged_array[k] = nums2[j];
            j++;
        }
        k++; // Move the merge array pointer forward
    }

    // 2. Copy remaining elements of nums1 (if any)
    while (i < m) {
        merged_array[k] = nums1[i];
        i++;
        k++;
    }

    // 3. Copy remaining elements of nums2 (if any)
    while (j < n) {
        merged_array[k] = nums2[j];
        j++;
        k++;
    }
}

/**
 * @brief Utility function to print an array.
 *
 * @param arr The array to print.
 * @param size The size of the array.
 */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

// Main function to test the program
int main() {
    // --- Input 1 ---
    int nums1_1[] = {2, 7, 11, 15};
    int m1 = sizeof(nums1_1) / sizeof(nums1_1[0]);
    int nums2_1[] = {4, 8, 10};
    int n1 = sizeof(nums2_1) / sizeof(nums2_1[0]);
    int size1 = m1 + n1;
    int merged1[size1];
    
    mergeSortedArrays(nums1_1, m1, nums2_1, n1, merged1);
    printf("Input 1: nums1 = [2,7,11,15] nums2 = [4,8,10]\n");
    printf("Output 1:\n");
    printArray(merged1, size1); // Expected: 2 4 7 8 10 11 15

    // --- Input 2 ---
    int nums1_2[] = {1, 2, 7};
    int m2 = sizeof(nums1_2) / sizeof(nums1_2[0]);
    int nums2_2[] = {9, 10, 17};
    int n2 = sizeof(nums2_2) / sizeof(nums2_2[0]);
    int size2 = m2 + n2;
    int merged2[size2];
    
    printf("\nInput 2: nums1 = [1,2,7] nums2 = [9,10,17]\n");
    mergeSortedArrays(nums1_2, m2, nums2_2, n2, merged2);
    printf("Output 2:\n");
    printArray(merged2, size2); // Expected: 1 2 7 9 10 17

    // --- Input 3 (Negative numbers and duplicates) ---
    int nums1_3[] = {-10, -2, 7};
    int m3 = sizeof(nums1_3) / sizeof(nums1_3[0]);
    int nums2_3[] = {-3, -1, 7};
    int n3 = sizeof(nums2_3) / sizeof(nums2_3[0]);
    int size3 = m3 + n3;
    int merged3[size3];
    
    printf("\nInput 3: nums1 = [-10,-2,7] nums2 = [-3, -1, 7]\n");
    mergeSortedArrays(nums1_3, m3, nums2_3, n3, merged3);
    printf("Output 3:\n");
    printArray(merged3, size3); // Expected: -10 -3 -2 -1 7 7

    return 0;
}