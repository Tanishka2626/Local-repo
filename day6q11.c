//Write program to input an integer and check whether it is even or odd using if–else.
#include <stdio.h>
int main(){
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    if(n%2==0) printf("Even");
    else printf("Odd");
    return 0;
}