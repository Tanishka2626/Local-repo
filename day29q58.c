//Find maximum and minimum element in an array.
#include <stdio.h>
int main() {
    int nums[25], size, m;
    int biggest, smallest;

    printf("Enter number of items: ");
    scanf("%d", &size);

    for(m = 0; m < size; m++)
        scanf("%d", &nums[m]);

    biggest = smallest = nums[0];

    for(m = 1; m < size; m++) {
        if(nums[m] > biggest)
            biggest = nums[m];
        if(nums[m] < smallest)
            smallest = nums[m];
    }

    printf("Max = %d, Min = %d", biggest, smallest);
    return 0;
}
