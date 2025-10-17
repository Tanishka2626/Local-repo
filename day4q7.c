//Write  program to swap two numbers without using a third variable.
#include <stdio.h>
 
int main(){
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    a = a + b; b = a - b; a = a -b; // a=5, b=10 
    printf("After swapping: %d %d\n", a, b);
    return 0;
}
