//Write  program to find and display the sum of the first n natural numbers.
#include <stdio.h>
int main (){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("sum = %d", n*(n+1)/2);// if n=5, numbers are 1+2+3+4+5 = 15
    return 0;
}