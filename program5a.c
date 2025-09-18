#include <stdio.h>

int main(){
        int n, i; // i- a loop counter
    printf("Enter how many numbers:");
    scanf("%d",&n);

    int arr[n]; // declares an array named arr with size n. this create space to store n intergers in one line of memory.
    //read n integers
     printf("Enter %d intergers:\n",n); // asks the user to type all n numbers
        for (i = 0; i < n; i++) {  // a loop that runs from i =0 to i =n-1 . each time, it reads one integer and stores it in arr[i]
             scanf("%d", &arr[i]);
}

int first = arr[0];
int second = -2147483648; // start second with a very small value( the smallest possible 32bit integer)
  
for (i = 1; i < n; i++){
    if (arr[i] > first){
        second = first;
        first = arr[i];

    } else if (arr[i] > second &&
     arr[i] < first) {
        second = arr[i];
     }   

    }  
     
    if (second == -2147483648) {
        printf("No second largest number (all numbers may be equal).\n");
    } else {
        printf("Second largest number is: %d\n", second);
    }
    return 0;
}
    
