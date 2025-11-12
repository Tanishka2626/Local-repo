#include <stdio.h>

int main(void)
{
    int n, i, num, freq = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the number to find its frequency: ");
    scanf("%d", &num);
    
    for(i = 0; i < n; i++) 
    {
        if(arr[i] == num) 
        {
            freq++;
        }
    }
    
    printf("The frequency of %d is: %d\n", num, freq);
    
    return 0;
}