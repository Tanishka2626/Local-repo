//Write  program to input an integer and check whether it is positive, negative or zero using nested if–else.
#include <stdio.h>
int main(){ 
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    if(n>0) printf("Positive");
    else if(n<0) printf("Negative");
    else printf("Zero");
    return 0;
}