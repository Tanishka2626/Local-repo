#include <stdio.h>

int main (){
    int n, i;
    printf("Enter how many numbers:");
    scanf("%d", &n);

    int arr[n]; // array to hold the numbers

    // read the numbers
    printf("Enter %d intergers:\n",n);
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        }
        // counters
        int positive = 0, negative = 0;
        int odd = 0, even = 0;

        // check each number
        for (i = 0; i < n; i++){
            if (arr[i] > 0)
               positive++;
            else if (arr[i] < 0)
                negative++;

            if (arr[i] % 2== 0)
                even++;
            else
                odd++;
        }

        // show the results
        printf("\npositive numbers: %d\n",positive);
        printf("Negative numbers: %d\n", negative);
        printf("Even numbers: %d\n", even);
        printf("Odd numbers: %d\n", odd);

        return 0;
}