// Write  program to check if a number is prime. 
#include <stdio.h>

int main(){
    int n, i, isPrime = 1;

    printf("Enter a number: ");
    scanf("%d", &n);
     if (n <=1){
        isPrime = 0; // numbers less than or equal to 1 are not prime 
     } else {
        for (i = 2; i <= n /2; i++) {
            if (n % i == 0){
                isPrime = 0;
                break;
            }
        }
        
     }
     if (isPrime)
         printf("%d is a prime number.\n",n );
         else
             printf("%d is not a prime number.\n", n);

             return 0;
}